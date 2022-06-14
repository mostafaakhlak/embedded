/*
 * SSDCfg.h
 *
 *  Created on: Jun 9, 2022
 *      Author: musta
 */

#ifndef HAL_SSD_SSDCFG_H_
#define HAL_SSD_SSDCFG_H_

/*********************************_SELECT_SSD_LED_PIN_***************************************/
#define SSD_LED_A				PA1
#define SSD_LED_B				PA2
#define SSD_LED_C				PA3
#define SSD_LED_D				PA4
#define SSD_LED_E				PA5
#define SSD_LED_F				PA6
#define SSD_LED_G				PA7
#define SSD_LED_DOT				PB0
#define SSD_EN_1				PC6
#define SSD_EN_2				PC7

/*********************************_SELECT_F_CPU_******************************************/
#define F_CPU					16000000UL
/*********************************_SELECT_LED_DELAY_TIME_********************************/
#define DISPLAY_TIME_INTERNAL			300

#endif /* HAL_SSD_SSDCFG_H_ */
