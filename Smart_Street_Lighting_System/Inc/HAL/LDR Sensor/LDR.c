

#include "MCAL/GPIO/GPIO.h"
#include "MCAL/ADC_/ADC_Interface.h"
#include "HAL/LDR Sensor/LDR.h"
#include "HAL/LDR Sensor/LDR_Config.h"

void HLDR_vInit(void)
{
	GPIO_vSetMode(GPIO_B, Pin0, GPIO_Input);
	GPIO_vSetPullUpPullDown(GPIO_B, Pin0, Pull_Down);
}

u8 HLDR_u8LdrRead(void)
{
	u8  copy_u8LdrDigiltal ;
	GPIO_vGetPinValue(GPIO_B, Pin0, &copy_u8LdrDigiltal);
	return copy_u8LdrDigiltal;
}
