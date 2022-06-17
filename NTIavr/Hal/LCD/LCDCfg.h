/*
 * LCDCfg.h
 *
 *  Created on: Jun 13, 2022
 *      Author: musta
 */

#ifndef HAL_LCD_LCDCFG_H_
#define HAL_LCD_LCDCFG_H_

/*********************************_SELECT_LCD_MODE_***************************************/
/*		OPTION_1 --> [8_BIT_MODE]		*/
/*		OPTION_2 --> [4_BIT_MODE]		*/

#define LCD_MODE					_4_BIT_MODE

/*********************************_SELECT_LCD_PIN_***************************************/


#define LCD_DATA4_PIN				PA3
#define LCD_DATA5_PIN				PA4
#define LCD_DATA6_PIN				PA5
#define LCD_DATA7_PIN				PA6
#define LCD_EN_PIN					PA2
#define LCD_RS_PIN					PA1


/*********************************_SELECT_LCD_DATA_PORT_***********************************/
#define LCD_DATA_PORT				PORTA
/*********************************_SELECT_F_CPU_******************************************/
#define F_CPU						16000000UL






#endif /* HAL_LCD_LCDCFG_H_ */
