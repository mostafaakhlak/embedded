/*
 * PushButtonCfg.h
 *
 *  Created on: Jun 12, 2022
 *      Author: musta
 */

#ifndef HAL_PUSHBUTTON_PUSHBUTTONCFG_H_
#define HAL_PUSHBUTTON_PUSHBUTTONCFG_H_


/****************************SELECT_PB_PIIS*********************************/
#define ACTIVE_LOW							1
#define ACTIVE_HIGH							2
#define PUSHBUTTON1_PIN						PD2
#define PUSHBUTTON2_PIN						PD3
#define PUSHBUTTON3_PIN						PD4
#define PUSHBUTTON4_PIN						PD5

/**************************SELECT_PB_MODE************************************/

/* 		OPTION_1 --> [ACTIVE_LOW] 		*/
/* 		OPTION_1 --> [ACTIVE_LOW] 		*/

#define PUSHBUTTON_MODE						ACTIVE_LOW

/**************************SELECT_PUSH_BUTTON_DEBOUNCING_TIME*****************/
/*PUSH_BUTTON_DEBOUNCING_TIME is in ms*/
#define PUSH_BUTTON_DEBOUNCING_TIME			100
#endif /* HAL_PUSHBUTTON_PUSHBUTTONCFG_H_ */
