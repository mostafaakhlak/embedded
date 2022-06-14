/*
 * SSD.c
 *
 *  Created on: Jun 9, 2022
 *      Author: musta
 */
#include"SSd.h"

void H_SSD_Void_SSDInit(void)
{
	M_Dio_Void_PinMode(SSD_LED_A,OUTPUT);
	M_Dio_Void_PinMode(SSD_LED_B,OUTPUT);
	M_Dio_Void_PinMode(SSD_LED_C,OUTPUT);
	M_Dio_Void_PinMode(SSD_LED_D,OUTPUT);
	M_Dio_Void_PinMode(SSD_LED_E,OUTPUT);
	M_Dio_Void_PinMode(SSD_LED_F,OUTPUT);
	M_Dio_Void_PinMode(SSD_LED_G,OUTPUT);
	M_Dio_Void_PinMode(SSD_LED_DOT,OUTPUT);
	M_Dio_Void_PinMode(SSD_EN_1,OUTPUT);
	M_Dio_Void_PinMode(SSD_EN_2,OUTPUT);
}
void H_SSD_Void_SSDDisplay(u8 Local_u8_Num)
{
	u8 Local_u8_Units = Local_u8_Num % 10;
	u8 Local_u8_Tens = Local_u8_Num / 10;
	u16 Local_u16_Counter=0;
	M_Dio_Void_PinWrite(SSD_EN_1,LOW);
	M_Dio_Void_PinWrite(SSD_EN_2,LOW);


	for(Local_u16_Counter=0;Local_u16_Counter < DISPLAY_TIME_INTERNAL;Local_u16_Counter++)
	{
		switch(Local_u8_Units)
		{
		case 0:
			M_Dio_Void_PinWrite(SSD_LED_A,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_B,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_C,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_D,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_E,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_F,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_G,LOW);
			break;
		case 1:
			M_Dio_Void_PinWrite(SSD_LED_A,LOW);
			M_Dio_Void_PinWrite(SSD_LED_B,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_C,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_D,LOW);
			M_Dio_Void_PinWrite(SSD_LED_F,LOW);
			M_Dio_Void_PinWrite(SSD_LED_E,LOW);
			M_Dio_Void_PinWrite(SSD_LED_G,LOW);
			break;
		case 2:
			M_Dio_Void_PinWrite(SSD_LED_A,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_B,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_C,LOW);
			M_Dio_Void_PinWrite(SSD_LED_D,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_E,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_F,LOW);
			M_Dio_Void_PinWrite(SSD_LED_G,HIGH);
			break;
		case 3:
			M_Dio_Void_PinWrite(SSD_LED_A,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_B,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_C,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_D,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_E,LOW);
			M_Dio_Void_PinWrite(SSD_LED_F,LOW);
			M_Dio_Void_PinWrite(SSD_LED_G,HIGH);
			break;
		case 4:
			M_Dio_Void_PinWrite(SSD_LED_A,LOW);
			M_Dio_Void_PinWrite(SSD_LED_B,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_C,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_D,LOW);
			M_Dio_Void_PinWrite(SSD_LED_E,LOW);
			M_Dio_Void_PinWrite(SSD_LED_F,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_G,HIGH);
			break;
		case 5:
			M_Dio_Void_PinWrite(SSD_LED_A,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_B,LOW);
			M_Dio_Void_PinWrite(SSD_LED_C,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_D,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_E,LOW);
			M_Dio_Void_PinWrite(SSD_LED_F,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_G,HIGH);
			break;
		case 6:
			M_Dio_Void_PinWrite(SSD_LED_A,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_B,LOW);
			M_Dio_Void_PinWrite(SSD_LED_C,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_D,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_E,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_F,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_G,HIGH);
			break;
		case 7:
			M_Dio_Void_PinWrite(SSD_LED_A,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_B,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_C,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_D,LOW);
			M_Dio_Void_PinWrite(SSD_LED_E,LOW);
			M_Dio_Void_PinWrite(SSD_LED_F,LOW);
			M_Dio_Void_PinWrite(SSD_LED_G,LOW);
			break;
		case 8:
			M_Dio_Void_PinWrite(SSD_LED_A,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_B,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_C,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_D,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_E,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_F,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_G,HIGH);
			break;
		case 9:
			M_Dio_Void_PinWrite(SSD_LED_A,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_B,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_C,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_D,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_E,LOW);
			M_Dio_Void_PinWrite(SSD_LED_F,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_G,HIGH);
			break;
		default: break;
		}
		M_Dio_Void_PinWrite(SSD_EN_1,HIGH);
		M_Dio_Void_PinWrite(SSD_EN_2,LOW);
		_delay_ms(1);
		M_Dio_Void_PinWrite(SSD_EN_1,LOW);
		switch(Local_u8_Tens)
		{
		case 0:
			M_Dio_Void_PinWrite(SSD_LED_A,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_B,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_C,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_D,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_E,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_F,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_G,LOW);
			break;
		case 1:
			M_Dio_Void_PinWrite(SSD_LED_A,LOW);
			M_Dio_Void_PinWrite(SSD_LED_B,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_C,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_D,LOW);
			M_Dio_Void_PinWrite(SSD_LED_F,LOW);
			M_Dio_Void_PinWrite(SSD_LED_E,LOW);
			M_Dio_Void_PinWrite(SSD_LED_G,LOW);
			break;
		case 2:
			M_Dio_Void_PinWrite(SSD_LED_A,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_B,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_C,LOW);
			M_Dio_Void_PinWrite(SSD_LED_D,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_E,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_F,LOW);
			M_Dio_Void_PinWrite(SSD_LED_G,HIGH);
			break;
		case 3:
			M_Dio_Void_PinWrite(SSD_LED_A,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_B,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_C,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_D,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_E,LOW);
			M_Dio_Void_PinWrite(SSD_LED_F,LOW);
			M_Dio_Void_PinWrite(SSD_LED_G,HIGH);
			break;
		case 4:
			M_Dio_Void_PinWrite(SSD_LED_A,LOW);
			M_Dio_Void_PinWrite(SSD_LED_B,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_C,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_D,LOW);
			M_Dio_Void_PinWrite(SSD_LED_E,LOW);
			M_Dio_Void_PinWrite(SSD_LED_F,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_G,HIGH);
			break;
		case 5:
			M_Dio_Void_PinWrite(SSD_LED_A,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_B,LOW);
			M_Dio_Void_PinWrite(SSD_LED_C,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_D,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_E,LOW);
			M_Dio_Void_PinWrite(SSD_LED_F,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_G,HIGH);
			break;
		case 6:
			M_Dio_Void_PinWrite(SSD_LED_A,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_B,LOW);
			M_Dio_Void_PinWrite(SSD_LED_C,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_D,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_E,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_F,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_G,HIGH);
			break;
		case 7:
			M_Dio_Void_PinWrite(SSD_LED_A,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_B,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_C,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_D,LOW);
			M_Dio_Void_PinWrite(SSD_LED_E,LOW);
			M_Dio_Void_PinWrite(SSD_LED_F,LOW);
			M_Dio_Void_PinWrite(SSD_LED_G,LOW);
			break;
		case 8:
			M_Dio_Void_PinWrite(SSD_LED_A,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_B,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_C,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_D,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_E,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_F,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_G,HIGH);
			break;
		case 9:
			M_Dio_Void_PinWrite(SSD_LED_A,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_B,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_C,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_D,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_E,LOW);
			M_Dio_Void_PinWrite(SSD_LED_F,HIGH);
			M_Dio_Void_PinWrite(SSD_LED_G,HIGH);
			break;
		default: break;
		}

		M_Dio_Void_PinWrite(SSD_EN_1,LOW);
		M_Dio_Void_PinWrite(SSD_EN_2,HIGH);
		_delay_ms(1);
		M_Dio_Void_PinWrite(SSD_EN_2,LOW);
	}
}

void H_SSD_Void_SSDCounterUp(u8 Local_Num)
{
	u8 Local_u8_Counter=0;
	for(Local_u8_Counter=0 ; Local_u8_Counter <= Local_Num ; Local_u8_Counter++)
	{
		H_SSD_Void_SSDDisplay(Local_u8_Counter);
	}
}

void H_SSD_Void_SSDCounterDown(u8 Local_Num)
{
	s8 Local_u8_Counter=0;
	for(Local_u8_Counter=Local_Num ; Local_u8_Counter >= 0 ; Local_u8_Counter--)
	{
		H_SSD_Void_SSDDisplay(Local_u8_Counter);
	}
}
