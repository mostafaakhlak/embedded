/*
 * TEMP_SENSOR.c
 *
 *  Created on: ٠٤‏/٠٨‏/٢٠٢٢
 *      Author: ONLiNE
 */


#include "LIB/Std_Types.h"
#include "MCAL/ADC_/ADC_Interface.h"
#include "MCAL/GPIO/GPIO.h"

void H_TempSensor_Void_TempSensorInit()
{
	GPIO_vSetMode(GPIO_A, Pin1, GPIO_Analog);
	GPIO_vSetMode(GPIO_A, Pin0, GPIO_Analog);
	MADC_VoidADCDRegularSequencer(CHANNEL_0, SEQ1);
}
u16 H_TempSensor_U16_TempSensorRead()
{
	u16 Local_AdcReading =0;
	Local_AdcReading = MADC_U16ADCReadData(Regular,0);
	return ((Local_AdcReading-2817));
}

