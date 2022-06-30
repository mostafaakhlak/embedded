/*
 * DC_Motor.c
 *
 *  Created on: Jun 29, 2022
 *      Author: musta
 */

#include "DC_Motor.h"

void H_Motor_Void_MotorInit(void)
{
	M_Dio_Void_PinMode(MOTOR_PIN1,OUTPUT);
	M_Dio_Void_PinMode(MOTOR_PIN2,OUTPUT);
}
void H_Motor_Void_MotorDirection(u8 Local_U8_Direction)
{
	if(Local_U8_Direction == CLOCKWISE)
	{
		M_Dio_Void_PinWrite(MOTOR_PIN1,HIGH);
		M_Dio_Void_PinWrite(MOTOR_PIN2,LOW);
	}
	else if(Local_U8_Direction == COUNTER_CLOCKWISE)
	{
		M_Dio_Void_PinWrite(MOTOR_PIN1,LOW);
		M_Dio_Void_PinWrite(MOTOR_PIN2,HIGH);
	}
	else;
}
void H_Motor_Void_MotorSpeed(u8 Copy_U8_Speed)
{
	M_Timer0_Void_Init();

	M_Dio_Void_PinMode(PB3_PIN,OUTPUT);

	M_Timer0_Void_StartTimer();

	M_Timer0_Void_SetPhaseCorrectPWM(Copy_U8_Speed);
}

void H_Motor_Void_MotorOff(void)
{
	M_Dio_Void_PinWrite(MOTOR_PIN1,LOW);
	M_Dio_Void_PinWrite(MOTOR_PIN2,LOW);
}
