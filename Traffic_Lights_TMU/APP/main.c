/*
 * main.c
 *
 *  Created on: Aug 8, 2022
 *      Author: Ahmed El-Gaafrawy
 */
#include "stdTypes.h"
#include "errorStates.h"

#include "TMU_int.h"
#include "DIO_int.h"
#include "SSD.h"

#include "util/delay.h"

void task1(void);
void task2(void);
void task3(void);
void task4(void);
void task5(void);
void task6(void);

u8 U8PosPressFlag;
u8 U8PosReleaseFlag;
u8 U8NegPressFlag;
u8 U8NegReleaseFlag;
u8 U8InitNum = 15;
u8 U8Counter;
u8 U8TraficFlag;


int main(void)
{
	H_SSD_Void_SSDInit();

	DIO_enuSetPinDirection(DIO_u8PORTC,DIO_u8PIN0,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(DIO_u8PORTC,DIO_u8PIN2,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(DIO_u8PORTC,DIO_u8PIN1,DIO_u8OUTPUT);

	DIO_enuSetPinDirection(DIO_u8PORTC,DIO_u8PIN3,DIO_u8INPUT);
	DIO_enuSetPinDirection(DIO_u8PORTC,DIO_u8PIN4,DIO_u8INPUT);

	TMU_vidInit();

	TMU_vidCreateTask(task1 , 5 , 0);
	TMU_vidCreateTask(task2 , 1 , 1);
	TMU_vidCreateTask(task3 , 2 , 2);
	TMU_vidCreateTask(task4 , 1 , 4);
	TMU_vidCreateTask(task5 , 1 , 5);
	TMU_vidCreateTask(task6 , 1 , 3);


	TMU_vidStartScheduler();
	return 0;
}



void task1(void)
{


	if(!U8Counter)
	{
		U8TraficFlag ^=1;
		U8Counter =	U8InitNum + 1;
	}
	U8Counter--;
	H_SSD_Void_SSDDisplay(U8Counter);
}

void task2(void)
{
	u8 L_U8Flag = 0;
	DIO_enuGetPinValue(DIO_u8PORTC,DIO_u8PIN3,&L_U8Flag);
	if(L_U8Flag == 1)
	{
		U8PosPressFlag++;
		U8PosReleaseFlag = 0;
	}
	if(L_U8Flag == 0)
	{
		U8PosReleaseFlag++;
	}
	if(U8PosPressFlag && U8PosReleaseFlag)
	{
		U8InitNum++;
		U8PosPressFlag   = 0;
		U8PosReleaseFlag = 0;
	}
}
void task3(void)
{
	u8 L_U8Flag = 0;
	DIO_enuGetPinValue(DIO_u8PORTC,DIO_u8PIN4,&L_U8Flag);
	if(L_U8Flag == 1)
	{
		U8NegPressFlag++;
		U8NegReleaseFlag = 0;
	}
	if(L_U8Flag == 0)
	{
		U8NegReleaseFlag++;
	}
	if(U8NegPressFlag && U8NegReleaseFlag)
	{
		U8InitNum--;
		U8NegPressFlag   = 0;
		U8NegReleaseFlag = 0;
	}
}

void task4(void)
{
	if(U8TraficFlag)
	{
		DIO_enuSetPinValue(DIO_u8PORTC , DIO_u8PIN0,DIO_u8HIGH);
		DIO_enuSetPinValue(DIO_u8PORTC , DIO_u8PIN2,DIO_u8LOW);
	}
}

void task5(void)
{
	if(U8Counter <= 4)
	{
		DIO_enuSetPinValue(DIO_u8PORTC ,DIO_u8PIN1,DIO_u8HIGH);
	}
	else
	{
		DIO_enuSetPinValue(DIO_u8PORTC ,DIO_u8PIN1,DIO_u8LOW);
	}

}

void task6(void)
{
	if(!U8TraficFlag)
	{
		DIO_enuSetPinValue(DIO_u8PORTC , DIO_u8PIN2,DIO_u8HIGH);
		DIO_enuSetPinValue(DIO_u8PORTC , DIO_u8PIN0,DIO_u8LOW);
	}
}
