/*
 * SSD.c
 *
 *  Created on: Jun 9, 2022
 *      Author: musta
 */
#include"SSd.h"

void H_SSD_Void_SSDInit(void)
{
	M_Dio_Void_PinMode(SSD1_LED_A,OUTPUT);
	M_Dio_Void_PinMode(SSD1_LED_B,OUTPUT);
	M_Dio_Void_PinMode(SSD1_LED_C,OUTPUT);
	M_Dio_Void_PinMode(SSD1_LED_D,OUTPUT);
	M_Dio_Void_PinMode(SSD1_LED_E,OUTPUT);
	M_Dio_Void_PinMode(SSD1_LED_F,OUTPUT);
	M_Dio_Void_PinMode(SSD1_LED_G,OUTPUT);


	M_Dio_Void_PinMode(SSD2_LED_A,OUTPUT);
	M_Dio_Void_PinMode(SSD2_LED_B,OUTPUT);
	M_Dio_Void_PinMode(SSD2_LED_C,OUTPUT);
	M_Dio_Void_PinMode(SSD2_LED_D,OUTPUT);
	M_Dio_Void_PinMode(SSD2_LED_E,OUTPUT);
	M_Dio_Void_PinMode(SSD2_LED_F,OUTPUT);
	M_Dio_Void_PinMode(SSD2_LED_G,OUTPUT);


}
void H_SSD_Void_SSDDisplay(u8 Local_u8_Num)
{
	u8 Local_u8_Units = Local_u8_Num % 10;
	u8 Local_u8_Tens = Local_u8_Num / 10;

	switch(Local_u8_Units)
	{
	case 0:
		M_Dio_Void_PinWrite(SSD1_LED_A,HIGH);
		M_Dio_Void_PinWrite(SSD1_LED_B,HIGH);
		M_Dio_Void_PinWrite(SSD1_LED_C,HIGH);
		M_Dio_Void_PinWrite(SSD1_LED_D,HIGH);
		M_Dio_Void_PinWrite(SSD1_LED_E,HIGH);
		M_Dio_Void_PinWrite(SSD1_LED_F,HIGH);
		M_Dio_Void_PinWrite(SSD1_LED_G,LOW);
		break;
	case 1:
		M_Dio_Void_PinWrite(SSD1_LED_A,LOW);
		M_Dio_Void_PinWrite(SSD1_LED_B,HIGH);
		M_Dio_Void_PinWrite(SSD1_LED_C,HIGH);
		M_Dio_Void_PinWrite(SSD1_LED_D,LOW);
		M_Dio_Void_PinWrite(SSD1_LED_F,LOW);
		M_Dio_Void_PinWrite(SSD1_LED_E,LOW);
		M_Dio_Void_PinWrite(SSD1_LED_G,LOW);
		break;
	case 2:
		M_Dio_Void_PinWrite(SSD1_LED_A,HIGH);
		M_Dio_Void_PinWrite(SSD1_LED_B,HIGH);
		M_Dio_Void_PinWrite(SSD1_LED_C,LOW);
		M_Dio_Void_PinWrite(SSD1_LED_D,HIGH);
		M_Dio_Void_PinWrite(SSD1_LED_E,HIGH);
		M_Dio_Void_PinWrite(SSD1_LED_F,LOW);
		M_Dio_Void_PinWrite(SSD1_LED_G,HIGH);
		break;
	case 3:
		M_Dio_Void_PinWrite(SSD1_LED_A,HIGH);
		M_Dio_Void_PinWrite(SSD1_LED_B,HIGH);
		M_Dio_Void_PinWrite(SSD1_LED_C,HIGH);
		M_Dio_Void_PinWrite(SSD1_LED_D,HIGH);
		M_Dio_Void_PinWrite(SSD1_LED_E,LOW);
		M_Dio_Void_PinWrite(SSD1_LED_F,LOW);
		M_Dio_Void_PinWrite(SSD1_LED_G,HIGH);
		break;
	case 4:
		M_Dio_Void_PinWrite(SSD1_LED_A,LOW);
		M_Dio_Void_PinWrite(SSD1_LED_B,HIGH);
		M_Dio_Void_PinWrite(SSD1_LED_C,HIGH);
		M_Dio_Void_PinWrite(SSD1_LED_D,LOW);
		M_Dio_Void_PinWrite(SSD1_LED_E,LOW);
		M_Dio_Void_PinWrite(SSD1_LED_F,HIGH);
		M_Dio_Void_PinWrite(SSD1_LED_G,HIGH);
		break;
	case 5:
		M_Dio_Void_PinWrite(SSD1_LED_A,HIGH);
		M_Dio_Void_PinWrite(SSD1_LED_B,LOW);
		M_Dio_Void_PinWrite(SSD1_LED_C,HIGH);
		M_Dio_Void_PinWrite(SSD1_LED_D,HIGH);
		M_Dio_Void_PinWrite(SSD1_LED_E,LOW);
		M_Dio_Void_PinWrite(SSD1_LED_F,HIGH);
		M_Dio_Void_PinWrite(SSD1_LED_G,HIGH);
		break;
	case 6:
		M_Dio_Void_PinWrite(SSD1_LED_A,HIGH);
		M_Dio_Void_PinWrite(SSD1_LED_B,LOW);
		M_Dio_Void_PinWrite(SSD1_LED_C,HIGH);
		M_Dio_Void_PinWrite(SSD1_LED_D,HIGH);
		M_Dio_Void_PinWrite(SSD1_LED_E,HIGH);
		M_Dio_Void_PinWrite(SSD1_LED_F,HIGH);
		M_Dio_Void_PinWrite(SSD1_LED_G,HIGH);
		break;
	case 7:
		M_Dio_Void_PinWrite(SSD1_LED_A,HIGH);
		M_Dio_Void_PinWrite(SSD1_LED_B,HIGH);
		M_Dio_Void_PinWrite(SSD1_LED_C,HIGH);
		M_Dio_Void_PinWrite(SSD1_LED_D,LOW);
		M_Dio_Void_PinWrite(SSD1_LED_E,LOW);
		M_Dio_Void_PinWrite(SSD1_LED_F,LOW);
		M_Dio_Void_PinWrite(SSD1_LED_G,LOW);
		break;
	case 8:
		M_Dio_Void_PinWrite(SSD1_LED_A,HIGH);
		M_Dio_Void_PinWrite(SSD1_LED_B,HIGH);
		M_Dio_Void_PinWrite(SSD1_LED_C,HIGH);
		M_Dio_Void_PinWrite(SSD1_LED_D,HIGH);
		M_Dio_Void_PinWrite(SSD1_LED_E,HIGH);
		M_Dio_Void_PinWrite(SSD1_LED_F,HIGH);
		M_Dio_Void_PinWrite(SSD1_LED_G,HIGH);
		break;
	case 9:
		M_Dio_Void_PinWrite(SSD1_LED_A,HIGH);
		M_Dio_Void_PinWrite(SSD1_LED_B,HIGH);
		M_Dio_Void_PinWrite(SSD1_LED_C,HIGH);
		M_Dio_Void_PinWrite(SSD1_LED_D,HIGH);
		M_Dio_Void_PinWrite(SSD1_LED_E,LOW);
		M_Dio_Void_PinWrite(SSD1_LED_F,HIGH);
		M_Dio_Void_PinWrite(SSD1_LED_G,HIGH);
		break;

	}


	switch(Local_u8_Tens)
	{
	case 0:
		M_Dio_Void_PinWrite(SSD2_LED_A,HIGH);
		M_Dio_Void_PinWrite(SSD2_LED_B,HIGH);
		M_Dio_Void_PinWrite(SSD2_LED_C,HIGH);
		M_Dio_Void_PinWrite(SSD2_LED_D,HIGH);
		M_Dio_Void_PinWrite(SSD2_LED_E,HIGH);
		M_Dio_Void_PinWrite(SSD2_LED_F,HIGH);
		M_Dio_Void_PinWrite(SSD2_LED_G,LOW);
		break;
	case 1:
		M_Dio_Void_PinWrite(SSD2_LED_A,LOW);
		M_Dio_Void_PinWrite(SSD2_LED_B,HIGH);
		M_Dio_Void_PinWrite(SSD2_LED_C,HIGH);
		M_Dio_Void_PinWrite(SSD2_LED_D,LOW);
		M_Dio_Void_PinWrite(SSD2_LED_F,LOW);
		M_Dio_Void_PinWrite(SSD2_LED_E,LOW);
		M_Dio_Void_PinWrite(SSD2_LED_G,LOW);
		break;
	case 2:
		M_Dio_Void_PinWrite(SSD2_LED_A,HIGH);
		M_Dio_Void_PinWrite(SSD2_LED_B,HIGH);
		M_Dio_Void_PinWrite(SSD2_LED_C,LOW);
		M_Dio_Void_PinWrite(SSD2_LED_D,HIGH);
		M_Dio_Void_PinWrite(SSD2_LED_E,HIGH);
		M_Dio_Void_PinWrite(SSD2_LED_F,LOW);
		M_Dio_Void_PinWrite(SSD2_LED_G,HIGH);
		break;
	case 3:
		M_Dio_Void_PinWrite(SSD2_LED_A,HIGH);
		M_Dio_Void_PinWrite(SSD2_LED_B,HIGH);
		M_Dio_Void_PinWrite(SSD2_LED_C,HIGH);
		M_Dio_Void_PinWrite(SSD2_LED_D,HIGH);
		M_Dio_Void_PinWrite(SSD2_LED_E,LOW);
		M_Dio_Void_PinWrite(SSD2_LED_F,LOW);
		M_Dio_Void_PinWrite(SSD2_LED_G,HIGH);
		break;
	case 4:
		M_Dio_Void_PinWrite(SSD2_LED_A,LOW);
		M_Dio_Void_PinWrite(SSD2_LED_B,HIGH);
		M_Dio_Void_PinWrite(SSD2_LED_C,HIGH);
		M_Dio_Void_PinWrite(SSD2_LED_D,LOW);
		M_Dio_Void_PinWrite(SSD2_LED_E,LOW);
		M_Dio_Void_PinWrite(SSD2_LED_F,HIGH);
		M_Dio_Void_PinWrite(SSD2_LED_G,HIGH);
		break;
	case 5:
		M_Dio_Void_PinWrite(SSD2_LED_A,HIGH);
		M_Dio_Void_PinWrite(SSD2_LED_B,LOW);
		M_Dio_Void_PinWrite(SSD2_LED_C,HIGH);
		M_Dio_Void_PinWrite(SSD2_LED_D,HIGH);
		M_Dio_Void_PinWrite(SSD2_LED_E,LOW);
		M_Dio_Void_PinWrite(SSD2_LED_F,HIGH);
		M_Dio_Void_PinWrite(SSD2_LED_G,HIGH);
		break;
	case 6:
		M_Dio_Void_PinWrite(SSD2_LED_A,HIGH);
		M_Dio_Void_PinWrite(SSD2_LED_B,LOW);
		M_Dio_Void_PinWrite(SSD2_LED_C,HIGH);
		M_Dio_Void_PinWrite(SSD2_LED_D,HIGH);
		M_Dio_Void_PinWrite(SSD2_LED_E,HIGH);
		M_Dio_Void_PinWrite(SSD2_LED_F,HIGH);
		M_Dio_Void_PinWrite(SSD2_LED_G,HIGH);
		break;
	case 7:
		M_Dio_Void_PinWrite(SSD2_LED_A,HIGH);
		M_Dio_Void_PinWrite(SSD2_LED_B,HIGH);
		M_Dio_Void_PinWrite(SSD2_LED_C,HIGH);
		M_Dio_Void_PinWrite(SSD2_LED_D,LOW);
		M_Dio_Void_PinWrite(SSD2_LED_E,LOW);
		M_Dio_Void_PinWrite(SSD2_LED_F,LOW);
		M_Dio_Void_PinWrite(SSD2_LED_G,LOW);
		break;
	case 8:
		M_Dio_Void_PinWrite(SSD2_LED_A,HIGH);
		M_Dio_Void_PinWrite(SSD2_LED_B,HIGH);
		M_Dio_Void_PinWrite(SSD2_LED_C,HIGH);
		M_Dio_Void_PinWrite(SSD2_LED_D,HIGH);
		M_Dio_Void_PinWrite(SSD2_LED_E,HIGH);
		M_Dio_Void_PinWrite(SSD2_LED_F,HIGH);
		M_Dio_Void_PinWrite(SSD2_LED_G,HIGH);
		break;
	case 9:
		M_Dio_Void_PinWrite(SSD2_LED_A,HIGH);
		M_Dio_Void_PinWrite(SSD2_LED_B,HIGH);
		M_Dio_Void_PinWrite(SSD2_LED_C,HIGH);
		M_Dio_Void_PinWrite(SSD2_LED_D,HIGH);
		M_Dio_Void_PinWrite(SSD2_LED_E,LOW);
		M_Dio_Void_PinWrite(SSD2_LED_F,HIGH);
		M_Dio_Void_PinWrite(SSD2_LED_G,HIGH);
		break;

	}
}

void H_SSD_Void_SSDCountUp(u8 Local_u8_Num)
{
	u8 Local_u8_Count = 0;
	for(Local_u8_Count = 0 ; Local_u8_Count <= Local_u8_Num ; Local_u8_Count++)
	{
		H_SSD_Void_SSDDisplay(Local_u8_Count);
		_delay_ms(5);
	}
}

void H_SSD_Void_SSDCountDown(u8 Local_u8_Num)
{
	s8 Local_u8_Count = Local_u8_Num;
	for(Local_u8_Count = Local_u8_Num ; Local_u8_Count > Local_u8_Num ; Local_u8_Count--)
	{
		H_SSD_Void_SSDDisplay(Local_u8_Count);
		_delay_ms(5);
	}
}
