/*
 * IR_SENSOR.c
 *
 *  Created on: Aug 4, 2022
 *      Author: 20101
 */

#include "HAL/IR_SENSOR.h"

/* NOTE : Only used in 4 Pins IR Module , Neglect if using 3 pins modules */
void IR_vSENSOR_ENABLE (void)
{
	SET_EN_IR_PIN_OUTPUT ;
	ENABLE_IR ;
}

/* SET IR OUTPUT Pin as input */
void IR_vSENSOR_DATA_PIN_MODE (void)
{
	SET_IR_DATA_PIN_INPUT ;
}

/* Read IR Digital data
 * NOTE : Reading either High or Low
 */
u8 IR_vSENSOR_READ (void)
{
	u8 Local_u8Data = 0;
	GPIO_vGetPinValue(IR_PORT,IR_OUTPUT_PIN,&Local_u8Data);
	return Local_u8Data ;
}
