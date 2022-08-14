/*
 * SSD.c
 *
 *  Created on: Jul 31, 2022
 *      Author: musta
 */

/*=======================================================================================
============================   The Foundation Of Function   =============================
=========================================================================================*/

/*===========   INCLUDE LIB   ===========*/
		 #include "LIB/Std_Types.h"
		 #include "LIB/Bit_Math.h"
		 #include "LIB/Delay_interface.h"
/*======================================*/
/*===========  INCLUDE MCAL  ===========*/
		#include "MCAL/GPIO/GPIO_Config.h"
		#include "MCAL/GPIO/GPIO.h"
		#include "MCAL/STK/STK.h"

/*======================================*/
#include "HAL/SSD/SSDCfg.h"
#include "HAL/SSD/SSD.h"

/*===========  INCLUDE HAL   ===========*/

void H_SSD_VoidSSDInit(void)
{
	for(int i =0; i<8; i++)
	{
		GPIO_vSetMode(GPIO_A, i, GPIO_Output);
		GPIO_vSetType(GPIO_A, i, PushPull);
		GPIO_vSetPullUpPullDown(GPIO_A, i, Float);
		GPIO_vSetSpeed(GPIO_A, i, LowSpeed);
	}
}
void H_SSD_VoidSSDDisplay(u8 L_u8Number)
{
	GPIO_vClearPort(GPIO_A);
	Delay_vMsIn16MHz(50);
	GPIO_vWriteByte(GPIO_A, Seven[L_u8Number]);
}
void H_SSD_VoidSSDCountUp(u8 L_u8StartNumber)
{
	u8 L_u8Counter = L_u8StartNumber;
	while(L_u8Counter <10 )
	{
		GPIO_vClearPort(GPIO_A);
		Delay_vMsIn16MHz(50);
		GPIO_vWriteByte(GPIO_A, Seven[L_u8Counter]);
		Delay_vMsIn16MHz(100);
		L_u8Counter++;
	}
}
void H_SSD_VoidSSDCountDown(u8 L_u8StartNumber)
{
	s8 L_u8Counter = L_u8StartNumber;
	while(1 )
	{
		GPIO_vClearPort(GPIO_A);
		Delay_vMsIn16MHz(50);
		GPIO_vWriteByte(GPIO_A, Seven[L_u8Counter]);
		Delay_vMsIn16MHz(100);
		if(!L_u8Counter) break;
		L_u8Counter--;
	}
}
