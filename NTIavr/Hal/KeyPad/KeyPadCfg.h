/*
 * KeyPadCfg.h
 *
 *  Created on: Jun 14, 2022
 *      Author: musta
 */

#ifndef HAL_KEYPAD_KEYPADCFG_H_
#define HAL_KEYPAD_KEYPADCFG_H_

/*********************************_SELECT_KEYPAD_PIN_***************************************/
#define KEYPAD_R0_PIN			PB4
#define KEYPAD_R1_PIN			PB5
#define KEYPAD_R2_PIN			PB6
#define KEYPAD_R3_PIN			PB7

#define KEYPAD_C0_PIN			PD2
#define KEYPAD_C1_PIN			PD3
#define KEYPAD_C2_PIN			PD4
#define KEYPAD_C3_PIN			PD5
/**************************SELECT_KEY_PAD_MODE************************************/

/* 		OPTION_1 --> [CALCULATOR] 		*/
/* 		OPTION_1 --> [KEYBOARD] 		*/
/*		CALCULATOR :			 {{'1','2','3','+'},
							  	  {'4','5','6','-'},
	 	 	 	 	 	 	  	  {'7','8','9','*'},
	 	 	 	 	 	 	  	  {'.','0','=','/'}};
		KEYBOARD   :			 {{'1','2','3','A'},
							  	  {'4','5','6','B'},
	 	 	 	 	 	 	  	  {'7','8','9','C'},
	 	 	 	 	 	 	  	  {'*','0','#','D'}};*/

#define KEY_PAD_MODE						CALCULATOR
/**************************SELECT_PUSH_BUTTON_DEBOUNCING_TIME*****************/
/*PUSH_BUTTON_DEBOUNCING_TIME is in ms*/
#define PUSH_BUTTON_DEBOUNCING_TIME			100


/*********************************_SELECT_F_CPU_******************************************/
#define F_CPU					16000000UL

#endif /* HAL_KEYPAD_KEYPADCFG_H_ */
