/*
 * Led.c
 *
 *  Created on: Jun 8, 2022
 *      Author: musta
 */

#include"Led.h"

void H_Led_Void_LedInit(void)
{
	M_Dio_Void_PinMode(PC0,OUTPUT);
}

void H_Led_Void_LedOn(void)
{
	M_Dio_Void_PinWrite(PC0,HIGH);
}
void H_Led_Void_Off(void)
{
	M_Dio_Void_PinWrite(PC0,LOW);
}
