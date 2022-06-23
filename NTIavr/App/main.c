/*
 * main.c
 *
 *  Created on: 07/06/2022
 *      Author: Mostafa Akhlak Mohamed
 */

#include"Std.h"
#include"GIE_Interface.h"
#include"Led.h"
#include"Timer_Interface.h"
#include"LCD.h"


/*************************************************TIMER0_PROJECT******************************************************************************/

#if 0

/************************************LED_ACTION_USING_OVER_FLOW_MODE************************
void Led_Action(void)
{
	//Action tog led every 1 sec
	static u16 OVF_count = 0;
	OVF_count++;
	if(OVF_count == 245)
	{
		M_Timer0_Void_SetPreload(220);
		OVF_count = 0;
		H_Led_Void_LedTog(RED_LED);
	}
}
*/

/************************************LED_ACTION_USING_CTC_MODE************************/
/*void Led_Action(void)
{
	//Action tog led every 1 sec
	static u16 counter = 0;
	counter++;
	if(counter == 625)
	{
		counter = 0;
		H_Led_Void_LedTog(BLU_LED);
	}
}*/

int main()
{
#if 0
	H_Led_Void_LedInit(RED_LED);

	M_Timer0_Void_Init();

	M_Timer0_Void_InterruptEnable(Timer0_OVF_INT_ID);

	M_Timer0_Void_SetCallBackFun(Led_Action,Timer0_OVF_INT_ID);

	M_GIE_Void_Enable();

	M_Timer0_Void_SetPreload(220);

	M_Timer0_Void_StartTimer();
#endif

	//H_Led_Void_LedInit(BLU_LED);

	M_Timer0_Void_Init();

	//M_Timer0_Void_InterruptEnable(Timer0_CMPMATCH_INT_ID);

	//M_Timer0_Void_SetCallBackFun(Led_Action,Timer0_CMPMATCH_INT_ID);

	//M_GIE_Void_Enable();

	//M_Timer0_Void_SetCmpMatch(100);
	M_Dio_Void_PinMode(PB3_PIN,OUTPUT);


	M_Timer0_Void_StartTimer();
	while(1)
	{
		M_Timer0_Void_SetPhaseCorrectPWM(0);
		_delay_ms(1000);
		M_Timer0_Void_SetPhaseCorrectPWM(10);
		_delay_ms(1000);
		M_Timer0_Void_SetPhaseCorrectPWM(30);
		_delay_ms(1000);
		M_Timer0_Void_SetPhaseCorrectPWM(50);
		_delay_ms(1000);
		M_Timer0_Void_SetPhaseCorrectPWM(80);
		_delay_ms(1000);
		M_Timer0_Void_SetPhaseCorrectPWM(100);
	}
}
#endif

#if 0
/*************************************************ICU_PROJECT******************************************************************************/
void ICU_HW(void);

volatile u16 Reading1 = 0;
volatile u16 Reading2 = 0;
volatile u16 Reading3 = 0;
volatile u8 StateCounter = 1;
int main()
{
	u32 TotalTicks =0;
	u32	ONTicks = 0;
	f32 Duty = 0;

	//init ICU in timer1 normal mode
	M_Timer1_Void_Init();

	M_Timer1_Void_ICUInit();

	M_Timer1_Void_InterruptEnable();

	M_Timer1_Void_SetCallBackFun(ICU_HW);
	//set ICP1 as input
	M_Dio_Void_PinMode(PD6_PIN,INPUT);
	//init ICU in timer0 fast PWM mode
	M_Timer0_Void_Init();

	M_Dio_Void_PinMode(PB3_PIN,OUTPUT);

	M_Timer0_Void_StartTimer();

	M_Timer0_Void_SetFastPWM(30);
	//init LCD
	H_LCD_Void_LCDInit();

	//enable global int
	M_GIE_Void_Enable();

	while(StateCounter != 4);
	TotalTicks = (Reading2 - Reading1);
	ONTicks = (Reading3 - Reading2);
	Duty = (((f32)ONTicks / TotalTicks) * 100);

	while(1)
	{
		H_LCD_Void_LCDWriteString("Total ticks = ");
		H_LCD_Void_LCDGoto(1,0);
		H_LCD_Void_LCDWriteNumber(TotalTicks);
		_delay_ms(2000);
		H_LCD_Void_LCDClr();


		H_LCD_Void_LCDWriteString("ON ticks = ");
		H_LCD_Void_LCDGoto(1,0);
		H_LCD_Void_LCDWriteNumber(ONTicks);
		_delay_ms(2000);
		H_LCD_Void_LCDClr();

		H_LCD_Void_LCDWriteString("Duty cycle = ");
		H_LCD_Void_LCDGoto(1,0);
		H_LCD_Void_LCDWriteNumber(Duty);
		H_LCD_Void_LCDWriteString("%");
		_delay_ms(2000);
		H_LCD_Void_LCDClr();

	}

	return 0;
}

void ICU_HW(void)
{
	switch(StateCounter)
	{
	case 1:
		Reading1 = M_Timer1_Void_InputCapture();
		StateCounter++;
		break;
	case 2:
		Reading2 = M_Timer1_Void_InputCapture();
		M_Timer1_Void_Settrigger(Timer1_FALLING_EDGE_TRIGGER);
		StateCounter++;
		break;
	case 3:
		Reading3 = M_Timer1_Void_InputCapture();
		StateCounter++;
		M_Timer1_Void_InterruptDisable();
		break;
	default:
		break;
	}
}

#endif
