/*
 * SSDCfg.h
 *
 *  Created on: Jun 9, 2022
 *      Author: musta
 */

#ifndef HAL_SSD_SSDCFG_H_
#define HAL_SSD_SSDCFG_H_

#include "stdTypes.h"
#include "Dio.h"
/*********************************_SELECT_SSD_LED_PIN_***************************************/
#define SSD1_LED_A				PA1_PIN
#define SSD1_LED_B				PA2_PIN
#define SSD1_LED_C				PA3_PIN
#define SSD1_LED_D				PA4_PIN
#define SSD1_LED_E				PA5_PIN
#define SSD1_LED_F				PA6_PIN
#define SSD1_LED_G				PA7_PIN

#define SSD2_LED_A				PB1_PIN
#define SSD2_LED_B				PB2_PIN
#define SSD2_LED_C				PB3_PIN
#define SSD2_LED_D				PB4_PIN
#define SSD2_LED_E				PB5_PIN
#define SSD2_LED_F				PB6_PIN
#define SSD2_LED_G				PB7_PIN


/*********************************_SELECT_F_CPU_******************************************/
#define F_CPU					16000000UL
/*********************************_SELECT_LED_DELAY_TIME_********************************/
#define LED_DELAY_TIME			500

#endif /* HAL_SSD_SSDCFG_H_ */
