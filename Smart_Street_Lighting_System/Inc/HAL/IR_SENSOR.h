/*
 * IR_SENSOR.h
 *
 *  Created on: Aug 4, 2022
 *      Author: 20101
 */

#ifndef IR_SENSOR_H_
#define IR_SENSOR_H_

#include "LIB/Bit_Math.h"
#include "LIB/Std_Types.h"
#include "MCAL/GPIO/GPIO_Private.h"
#include "MCAL/GPIO/GPIO.h"
#include "MCAL/RCC/RCC.h"

#define IR_PORT GPIO_H
#define IR_ENABLE_PIN   0U
#define IR_OUTPUT_PIN	1U
#define LOW 	0U
#define HIGH	1U
/* Setting Enable Pin as Output */
#define SET_EN_IR_PIN_OUTPUT GPIO_vSetMode(IR_PORT,IR_ENABLE_PIN,GPIO_Output)
/* Setting IR output pin as input */
#define SET_IR_DATA_PIN_INPUT GPIO_vSetMode(IR_PORT,IR_OUTPUT_PIN,GPIO_Input)
/* Setting IR Enable Pin as Low ( Active Low Enable ) */
#define ENABLE_IR GPIO_vWritePinValue(IR_PORT,IR_ENABLE_PIN,LOW)
/* Reading IR Output PIN */
#define READ_IR_STATUS GPIO_vGetPinValue(IR_PORT,IR_OUTPUT_PIN,&Local_u8Data)

void IR_vSENSOR_ENABLE (void);
void IR_vSENSOR_DATA_PIN_MODE (void);
u8 IR_vSENSOR_READ (void);

#endif /* IR_SENSOR_H_ */
