/*
 * WDT_Prog.c
 *
 *  Created on: Jun 29, 2022
 *      Author: musta
 */
#include "Std.h"
#include "BitMath.h"
#include "Reg.h"
#include "WDT_Config.h"
#include "WDT_Interface.h"
#include "WDT_Private.h"


void M_WDT_Void_Enable(u8 Copy_U8_Prescaler)
{
	SetBit(WDTCR_REG,3);
	WDTCR_REG &= WDT_PRESCALER_MASK;
	WDTCR_REG |= Copy_U8_Prescaler;
}
void M_WDT_Void_Disable(void)
{
	WDTCR_REG |= (1<<3) | (1<<4);
	WDTCR_REG = 0x00;
}
void M_WDT_Void_Sleep(u8 Copy_U8_SleepTimeout)
{
	WDTCR_REG &= WDT_PRESCALER_MASK;
	WDTCR_REG |= Copy_U8_SleepTimeout;
}
