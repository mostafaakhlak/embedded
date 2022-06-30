/*
 * DC_Motor.h
 *
 *  Created on: Jun 29, 2022
 *      Author: musta
 */

#ifndef HAL_DC_MOTOR_DC_MOTOR_H_
#define HAL_DC_MOTOR_DC_MOTOR_H_

/**********************************************************_INCLUDES_*****************************************************************/
#include"Dio.h"
#include"DC_MotorConfg.h"
#include "Timer_Interface.h"
/**********************************************************_MACROS_******************************************************************/
#define CLOCKWISE 				0
#define COUNTER_CLOCKWISE		1
/**********************************************************_PROTOTYPES_***************************************************************/

void H_Motor_Void_MotorInit(void);
void H_Motor_Void_MotorDirection(u8);
void H_Motor_Void_MotorSpeed(u8);
void H_Motor_Void_MotorOff(void);

#endif /* HAL_DC_MOTOR_DC_MOTOR_H_ */
