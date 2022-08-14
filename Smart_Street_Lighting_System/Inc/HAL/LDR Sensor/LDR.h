#ifndef _LDR_H
#define _LDR_H


#include "LIB/Std_Types.h"
#include "MCAL/GPIO/GPIO.h"
#include "HAL/LDR Sensor/LDR_Config.h"
typedef struct
{
	GPIO_PortNum PortName	;
	GPIO_PinNum	 PinNum  	;
}LDR_t;

extern LDR_t LDR[LDR_NUM];


void HLDR_vInit(void);
u8 HLDR_u8LdrRead(void);


#endif /*_LDR_H*/
