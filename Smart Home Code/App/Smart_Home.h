/*
 * Smart_Home.h
 *
 *  Created on: Jun 27, 2022
 *      Author: Mostafa Akhlak Mohamed
 *      Project Name:Smart Home
 */

#ifndef APP_SMART_HOME_H_
#define APP_SMART_HOME_H_

/*****************************************************INCLUDES************************************************************************/

#include"Dio.h"
#include "LCD.h"
#include "Timer_Interface.h"
#include "Buzzer.h"

/*****************************************************MACROS**************************************************************************/

#define  CORRECT				1
#define  WRONG					2
/****************************************************PROTOTYPES***********************************************************************/
u8 A_SmartHome_Void_PasswordCheck(u8*);
void A_SmartHome_U8_PasswordCorrect(void);
void A_SmartHome_U8_PasswordWrong(void);
void A_SmartHome_Void_MainMenu(void);


#endif /* APP_SMART_HOME_H_ */
