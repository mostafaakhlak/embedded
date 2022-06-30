/*
 * TempSensor.c
 *
 *  Created on: Jun 16, 2022
 *      Author: musta
 */

#include"TempSensor.h"

void H_TempSensor_Void_TempSensorInit(void)
{
	M_ADC_Void_ADCInit();
}
f32 H_TempSensor_F32_TempSensorRead(void)
{
	f32 Local_u16_ADCReading = M_ADC_U16_ADCRead();
	return ((f32)Local_u16_ADCReading*500) / 1023 ;
}

