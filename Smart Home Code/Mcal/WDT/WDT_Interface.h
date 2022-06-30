/*
 * WDT_Interface.h
 *
 *  Created on: Jun 29, 2022
 *      Author: musta
 */

#ifndef MCAL_WDT_WDT_INTERFACE_H_
#define MCAL_WDT_WDT_INTERFACE_H_
/********************************************_MACROS_***********************************************************************************/
#define WDT_TIMEOUT_16_3_MS				0
#define WDT_TIMEOUT_32_5_MS				1
#define WDT_TIMEOUT_64_MS				2
#define WDT_TIMEOUT_0_13_S				3
#define WDT_TIMEOUT_0_26_S				4
#define WDT_TIMEOUT_0_52_S				5
#define WDT_TIMEOUT_1_S					6
#define WDT_TIMEOUT_2_1_S				7
/*******************************************_PROTOTYPES_*******************************************************************************/
void M_WDT_Void_Enable(u8 Copy_U8_Prescaler);
void M_WDT_Void_Disable(void);
void M_WDT_Void_Sleep(u8 Copy_U8_SleepTimeout);
#endif /* MCAL_WDT_WDT_INTERFACE_H_ */
