/*
 * TMU_prog.c
 *
 *  Created on: Aug 8, 2022
 *      Author: Ahmed El-Gaafrawy
 */
#include "stdTypes.h"


#include "TMU_config.h"
#include "TMU_priv.h"


#if TIMER_CHANNEL == TIMER0 || TIMER_CHANNEL == TIMER2
static u8 TMU_u8ISRNum;
static u8 TMU_u8ISRCount;
static u8 TMU_u8Preload;
#endif

#if MAX_TASK == 0 ||MAX_TASK > 15
#error "max number of tasks is invalid ya lat5"
#endif


static TCB_t TMU_AstrAllTasks[ MAX_TASK ];
static u32 TMU_u32OsTicks;

void TMU_vidInit(void)
{
#if TIMER_CHANNEL ==  TIMER0

	// CTC , disconnect OC0 pin , 1024 prescaler
	TCCR0 = 0xD;
	#if OS_TICK >0 && OS_TICK <=16

		OCR0 = (u8)((OS_TICK * TMU_FREQ)/1024ul);

		TMU_u8ISRNum = 1;
		TMU_u8ISRCount = TMU_u8ISRNum;

		//enable PIE of CTC mode
		TIMSK |= (1<<1);
	#elif OS_TICK <= 150

		u8 max = 16;
		for ( ; max >= 1 ; max--)
			if (! (OS_TICK % max))
				break;
		if (max > 4)
		{
			OCR0 = (u8)((max * TMU_FREQ)/1024ul);
			TMU_u8ISRNum = (OS_TICK / max);
			TMU_u8ISRCount = TMU_u8ISRNum;
			//enable PIE of CTC mode
			TIMSK |= (1<<1);
		}
		else
		{
			TCCR0 = 0x5;
			u32 counts = (OS_TICK * TMU_FREQ)/1024ul;
			if (counts %256)
			{
				TMU_u8ISRNum = counts / 256 +1;
				TMU_u8ISRCount = TMU_u8ISRNum;
				TMU_u8Preload = (u8)(256 - (counts % 256));
				TCNT0 = 0;
			}
			else
			{
				TMU_u8ISRNum = counts / 256 ;
				TMU_u8ISRCount = TMU_u8ISRNum;
				TMU_u8Preload = 0;
			}
			TIMSK |= (1<<0);
		}
	#else
	#error "OS tick value is invalid"
	#endif

#elif TIMER_CHANNEL == TIMER1
	//CTC on OCR1A , 64 pres , dis OC1A ,OC1B
	TCCR1A = 0;
	TCCR1B = 0xB;
	#if OS_TICK >0 && OS_TICK <=150

	u16 counts = (OS_TICK * TMU_FREQ)/64ul;

	OCR1AH = (u8)(counts >> 8);
	OCR1AL = (u8)(counts);

	TIMSK |= (1<<4);

	#else
	#error"OS tick value is invalid"
	#endif

#elif TIMER_CHANNEL == TIMER2

	// CTC , disconnect OC0 pin , 1024 prescaler
	TCCR2 = 0xF;
	#if OS_TICK >0 && OS_TICK <=16

		OCR2 = (u8)((OS_TICK * TMU_FREQ)/1024ul);

		TMU_u8ISRNum = 1;
		TMU_u8ISRCount = TMU_u8ISRNum;

		//enable PIE of CTC mode
		TIMSK |= (1<<7);
	#elif OS_TICK <= 150

		u8 max = 16;
		for ( ; max >= 1 ; max--)
			if (! (OS_TICK % max))
				break;
		if (max > 4)
		{
			OCR2 = (u8)((max * TMU_FREQ)/1024ul);
			TMU_u8ISRNum = (OS_TICK / max);
			TMU_u8ISRCount = TMU_u8ISRNum;
			//enable PIE of CTC mode
			TIMSK |= (1<<7);
		}
		else
		{
			TCCR2 = 0x7;
			u32 counts = (OS_TICK * TMU_FREQ)/1024ul;
			if (counts %256)
			{
				TMU_u8ISRNum = counts / 256 +1;
				TMU_u8ISRCount = TMU_u8ISRNum;
				TMU_u8Preload = (u8)(256 - (counts % 256));
				TCNT2 = 0;
			}
			else
			{
				TMU_u8ISRNum = counts / 256 ;
				TMU_u8ISRCount = TMU_u8ISRNum;
				TMU_u8Preload = 0;
			}
			TIMSK |= (1<<6);
		}
	#else
	#error "OS tick value is invalid"
	#endif

#else
#error "selection of timer channel is wrong ya 7omar"
#endif
}



void TMU_vidCreateTask(void (*Copy_pFunAppFun)(void) , u16 Copy_u16Periodicity , u8 Copy_u8Priority)
{
	if ( Copy_pFunAppFun != NULL )
	{
		TMU_AstrAllTasks[ Copy_u8Priority ].pFun = Copy_pFunAppFun;
		TMU_AstrAllTasks[ Copy_u8Priority ].Periodicity = Copy_u16Periodicity;
	}
	else
	{

	}
}


void TMU_vidStartScheduler(void)
{
	u32 Local_u32Temp = 0;
	asm ("SEI");
	while(1)
	{
		//if (TMU_u32OsTicks == Local_u32Temp )
		if (TMU_u32OsTicks > Local_u32Temp )
		{
			//Local_u32Temp ++;
			Local_u32Temp = TMU_u32OsTicks;

			//MAX_TASK is highest
			for (s8 i= MAX_TASK-1 ; i>=0 ;i--)
			{
				if ( (!(TMU_u32OsTicks % TMU_AstrAllTasks[i].Periodicity))
						&&
						TMU_AstrAllTasks[i].pFun !=NULL)
				{
					TMU_AstrAllTasks[i].pFun ();
				}
			}
			//0 highest
			//for (u8 i=0;i<MAX_TASK;i++)
		}
	}
}

#if TIMER_CHANNEL == TIMER0

//ISR of CTC Timer0
void __vector_10(void)__attribute__ ((signal));
void __vector_10(void)
{
	TMU_u8ISRCount --;
	if (! TMU_u8ISRCount)
	{
		TMU_u32OsTicks++;

		TMU_u8ISRCount =  TMU_u8ISRNum;
	}
}


//ISR of OVF Timer0
void __vector_11(void)__attribute__ ((signal));
void __vector_11(void)
{
	TMU_u8ISRCount --;
	if (! TMU_u8ISRCount)
	{
		TCNT0 = TMU_u8Preload;

		TMU_u32OsTicks++;

		TMU_u8ISRCount =  TMU_u8ISRNum;
	}
}


#elif TIMER_CHANNEL == TIMER1

//ISR of CTC Timer1 ,A channel
void __vector_7(void)__attribute__ ((signal));
void __vector_7(void)
{
	TMU_u32OsTicks++;
}


#elif TIMER_CHANNEL == TIMER2

//ISR of CTC Timer2
void __vector_4(void)__attribute__ ((signal));
void __vector_4(void)
{
	TMU_u8ISRCount --;
	if (! TMU_u8ISRCount)
	{
		TMU_u32OsTicks++;

		TMU_u8ISRCount =  TMU_u8ISRNum;
	}
}


//ISR of OVF Timer2
void __vector_5(void)__attribute__ ((signal));
void __vector_5(void)
{
	TMU_u8ISRCount --;
	if (! TMU_u8ISRCount)
	{
		TCNT2 = TMU_u8Preload;

		TMU_u32OsTicks++;

		TMU_u8ISRCount =  TMU_u8ISRNum;
	}
}



#endif
