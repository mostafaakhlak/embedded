/*
 * Smart_Home.c
 *
 *  Created on: Jun 27, 2022
 *      Author: Mostafa Akhlak Mohamed
 *      Project Name:Smart Home
 */


#include "Smart_Home.h"



/*************************************************************************************************************************************
 * NAME:			A_SmartHome_Void_PasswordCheck
 * FUNCTION:		This function checks whether the password is correct or not
 * ARGUMENTS:		u8 pointer to password array address
 * RETURN VALUE:	Correct or Wrong
 *************************************************************************************************************************************/
u8 A_SmartHome_Void_PasswordCheck(u8 *Local_u8_Ptr_Password)
{
	u8 Local_u8CheckResult = 0;
	if(Local_u8_Ptr_Password[0] == '1' && Local_u8_Ptr_Password[1] == '5' && Local_u8_Ptr_Password[2] == '9' && Local_u8_Ptr_Password[3] == '7' )
		Local_u8CheckResult = CORRECT;
	else
		Local_u8CheckResult = WRONG ;

	return Local_u8CheckResult;
}


/*************************************************************************************************************************************
 * NAME:			A_SmartHome_U8_PasswordCorrect
 * FUNCTION:		This function displays messages when the entered password is correct
 * ARGUMENTS:		void
 * RETURN VALUE:	void
 *************************************************************************************************************************************/
void A_SmartHome_U8_PasswordCorrect(void)
{
	u8 Local_U8_String[] = "**Welcome Home**";
	H_LCD_Void_LCDClr();
	H_LCD_Void_LCDWriteString(Local_U8_String);
}

/*************************************************************************************************************************************
 * NAME:A_SmartHome_U8_PasswordWrong
 * FUNCTION:This function displays messages when the entered password is wrong
 * ARGUMENTS:void
 * RETURN VALUE:void
 *************************************************************************************************************************************/
void A_SmartHome_U8_PasswordWrong(void)
{
	u8 Local_U8_String1[] = "*Wrong Password*";
	H_LCD_Void_LCDClr();
	H_LCD_Void_LCDWriteString(Local_U8_String1);
	H_LCD_Void_LCDGoto(1,0);
	u8 Local_U8_String2[] = "Please try again";
	H_LCD_Void_LCDWriteString(Local_U8_String2);
	H_Buzzer_Void_BuzzerOnce();
}



/*************************************************************************************************************************************
 * NAME:			A_SmartHome_Void_MainMenu
 * FUNCTION:		This function displays the list of activities when user enters home
 * ARGUMENTS:		void
 * RETURN VALUE:	void
 *************************************************************************************************************************************/
void A_SmartHome_Void_MainMenu(void)
{
	H_LCD_Void_LCDGoto(0,0);
	u8 Local_U8_String1[] = "Choose activity:";
	H_LCD_Void_LCDWriteString(Local_U8_String1);
	_delay_ms(2000);
	H_LCD_Void_LCDGoto(1,0);
	u8 Local_U8_String2[] = "(1)Lights ON    ";
	H_LCD_Void_LCDWriteString(Local_U8_String2);
	_delay_ms(2000);
	H_LCD_Void_LCDGoto(1,0);
	u8 Local_U8_String3[] = "(2)Lights OFF   ";
	H_LCD_Void_LCDWriteString(Local_U8_String3);
	_delay_ms(2000);
	H_LCD_Void_LCDGoto(1,0);
	u8 Local_U8_String5[] = "(3)Exit Home     ";
	H_LCD_Void_LCDWriteString(Local_U8_String5);
	_delay_ms(2000);
	H_LCD_Void_LCDGoto(1,0);
	u8 Local_U8_String4[] = "(4)Repeat again";
	H_LCD_Void_LCDWriteString(Local_U8_String4);
	_delay_ms(2000);

}
