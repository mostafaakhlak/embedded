/*
 * Smart_Home_main.c
 *
 *  Created on: Jun 27, 2022
 *      Author: Mostafa Akhlak Mohamed
 *      Project Name:Smart Home
 */


#if 1

#include"Std.h"
#include"GIE_Interface.h"
#include"Led.h"
#include"Timer_Interface.h"
#include"LCD.h"
#include "Smart_Home.h"
#include "KeyPad.h"
#include "TempSensor.h"
#include "DC_Motor.h"
#include "ADC.h"

void Heat_Handler(void);

int main()
{


	//Timer initialization
	M_Timer0_Void_Init();
	//LEDs initialization
	H_Led_Void_LedInit(BLU_LED);
	H_Led_Void_LedInit(RED_LED);
	H_Led_Void_LedInit(GRN_LED);
	//Keypad initialization
	H_KeyPad_Void_KeyPadInit();
	//LCD initialization
	H_LCD_Void_LCDInit();
	//Buzzer initialization
	H_Buzzer_Void_BuzzerInit();
	//Temperature sensor initialization
	H_TempSensor_Void_TempSensorInit();
	//Motor initialization
	H_Motor_Void_MotorInit();
	//Call back function
	M_ADC_Void_SetCallBackFun(Heat_Handler);
	//Enable Global Interrupt
	M_GIE_Void_Enable();
	//Local variables declaration
	u8 Local_U8_check = 0;
	u8 Local_U8_PassDigits = 0;
	u8 Local_U8_PassAlarm = 0;
	u8 Local_U8_KeyPad_Reading = 0;
	u8 Local_U8_PassArr[4] = {};
	//main loop
	while(1)
	{
		while(Local_U8_PassDigits < 4)
		{
			//System asks for password
			H_LCD_Void_LCDGoto(0,0);
			u8 Local_U8_String[] = "Enter password";
			H_LCD_Void_LCDWriteString(Local_U8_String);
			//System takes 4 readings(password) in an array and checks them
			Local_U8_KeyPad_Reading = H_KeyPad_U8_KeyPadRead();
			if(Local_U8_KeyPad_Reading)
			{
				Local_U8_PassArr[Local_U8_PassDigits] = Local_U8_KeyPad_Reading;
				Local_U8_PassDigits++;
				H_LCD_Void_LCDGoto(1,Local_U8_PassDigits);
				H_LCD_Void_LCDWriteCharacter(Local_U8_KeyPad_Reading);
			}
		}

		while(Local_U8_PassDigits == 4)
		{
			_delay_ms(1000);
			Local_U8_check = A_SmartHome_Void_PasswordCheck(Local_U8_PassArr);
			if(Local_U8_check == CORRECT)
			{
				A_SmartHome_U8_PasswordCorrect();
				_delay_ms(2000);
				H_LCD_Void_LCDClr();
			}
			else if(Local_U8_check == WRONG)
			{
				Local_U8_PassAlarm++;
				//System locks for two minutes after Entering wrong password 3 times
				if(Local_U8_PassAlarm == 3)
				{
					u8 Stuck_Counter = 120;
					H_LCD_Void_LCDClr();
					u8 Local_U8_String1[] = "*wrong password*";
					H_LCD_Void_LCDWriteString(Local_U8_String1);
					H_Buzzer_Void_BuzzerTriple();
					u8 Local_U8_String2[] = "Try again later";
					H_LCD_Void_LCDGoto(1,0);
					H_LCD_Void_LCDWriteString(Local_U8_String2);
					_delay_ms(1000);
					while(Stuck_Counter > 0)
					{
						H_LCD_Void_LCDClr();
						H_LCD_Void_LCDGoto(0,2);
						u8 Local_U8_String2[] = "2 MIN Timer";
						H_LCD_Void_LCDWriteString(Local_U8_String2);
						H_LCD_Void_LCDGoto(1,4);
						H_LCD_Void_LCDWriteNumber(Stuck_Counter);
						_delay_ms(1000);
						Stuck_Counter--;
					}
					H_LCD_Void_LCDClr();
					Local_U8_PassAlarm = 0;
				}
				else
				{
					A_SmartHome_U8_PasswordWrong();
					_delay_ms(2000);
					H_LCD_Void_LCDClr();
				}
			}
			else;
			Local_U8_PassDigits = 0;
		}

		if(Local_U8_check == CORRECT)
		{
			//System shows the user his options to choose:
					/*
					 * 1- Lights ON
					 * 2- Lights OFF
					 * 3- Exit Home
					 */
					u8 Local_U8_Choice = 0;
					while(!Local_U8_Choice)
					{
						Local_U8_KeyPad_Reading = 0;
						A_SmartHome_Void_MainMenu();
						while(!Local_U8_KeyPad_Reading)
							Local_U8_KeyPad_Reading = H_KeyPad_U8_KeyPadRead();
						switch(Local_U8_KeyPad_Reading)
						{
						case '1' :
							H_Led_Void_LedOn(BLU_LED);
							H_Led_Void_LedOn(RED_LED);
							H_Led_Void_LedOn(GRN_LED);
							break;
						case '2' :
							H_Led_Void_LedOff(BLU_LED);
							H_Led_Void_LedOff(RED_LED);
							H_Led_Void_LedOff(GRN_LED);
							break;
						case '3' :
							Local_U8_Choice = 1;
							H_LCD_Void_LCDClr();
							break;
						case '4' :
							H_LCD_Void_LCDClr();
							break;
						default :
							H_LCD_Void_LCDClr();
							u8 Local_U8_Str[] = {"Wrong choice"};
							H_LCD_Void_LCDWriteString(Local_U8_Str);
							H_LCD_Void_LCDGoto(1,0);
							u8 Local_U8_Str1[] = {"Try again"};
							H_LCD_Void_LCDWriteString(Local_U8_Str1);
							_delay_ms(2000);
							H_LCD_Void_LCDClr();
							break;
						}
					}
		}
		else;
	}
	return 0;
}

void Heat_Handler(void)
{
	static u16 Local_U16_Counter = 0;
	Local_U16_Counter++;
	if(Local_U16_Counter == 3000)
	{
		f32 Local_F32_Reading = H_TempSensor_F32_TempSensorRead();

		if(Local_F32_Reading > 25 && Local_F32_Reading < 30)
		{
			H_Motor_Void_MotorDirection(CLOCKWISE);
			H_Motor_Void_MotorSpeed(50);
		}

		else if(Local_F32_Reading >= 30)
		{
			H_Motor_Void_MotorDirection(CLOCKWISE);
			H_Motor_Void_MotorSpeed(100);
		}
		else
		{
			H_Motor_Void_MotorSpeed(0);
			H_Motor_Void_MotorOff();
		}
		Local_U16_Counter = 0;
	}
}
#endif
