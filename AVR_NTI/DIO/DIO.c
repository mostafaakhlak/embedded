/*
 * DIO.c
 *
 *  Created on: 07/06/2022
 *      Author: Mostafa Akhlak Mohamed
 */

#include"DIO.h"

void PinMode(u8 Local_u8_Num,u8 Local_u8_Mode)
{
	u8 Local_u8_Pin = Local_u8_Num % 10;
	u8 Local_u8_Port = Local_u8_Num / 10;
	switch(Local_u8_Mode)
	{
	case INPUT:
		switch(Local_u8_Port)
		{
			case 1:ClrBit(DDRA,Local_u8_Pin); break;
			case 2:ClrBit(DDRB,Local_u8_Pin); break;
			case 3:ClrBit(DDRC,Local_u8_Pin); break;
			case 4:ClrBit(DDRD,Local_u8_Pin); break;
			default:						  break;
		}
		break;
	case OUTPUT:
		switch(Local_u8_Port)
		{
			case 1:SetBit(DDRA,Local_u8_Pin); break;
			case 2:SetBit(DDRB,Local_u8_Pin); break;
			case 3:SetBit(DDRC,Local_u8_Pin); break;
			case 4:SetBit(DDRD,Local_u8_Pin); break;
			default:						  break;
		}
		break;
	}
}

void PinWrite(u8 Local_u8_Num,u8 Local_u8_Mode)
{
	u8 Local_u8_Pin = Local_u8_Num % 10;
	u8 Local_u8_Port = Local_u8_Num / 10;
	switch(Local_u8_Mode)
	{
	case LOW:
		switch(Local_u8_Port)
		{
			case 1:ClrBit(PORTA,Local_u8_Pin); break;
			case 2:ClrBit(PORTB,Local_u8_Pin); break;
			case 3:ClrBit(PORTC,Local_u8_Pin); break;
			case 4:ClrBit(PORTD,Local_u8_Pin); break;
			default:						   break;
		}
		break;
	case HIGH:
		switch(Local_u8_Port)
		{
			case 1:SetBit(PORTA,Local_u8_Pin); break;
			case 2:SetBit(PORTB,Local_u8_Pin); break;
			case 3:SetBit(PORTC,Local_u8_Pin); break;
			case 4:SetBit(PORTD,Local_u8_Pin); break;
			default:						   break;
		}
		break;
	}
}

