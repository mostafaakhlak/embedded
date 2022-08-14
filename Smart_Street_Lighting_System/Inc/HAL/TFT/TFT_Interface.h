/*
 * TFT_Interface.h
 *
 *  Created on: Aug 2, 2022
 *      Author: musta
 */

#ifndef HAL_TFT_TFT_INTERFACE_H_
#define HAL_TFT_TFT_INTERFACE_H_


void HTFT_VoidTFTInit(void);
void HTFT_VoidTFTDisplayImage(const u32*Copy_Image);
void HTFT_VoidTFTSetCursorPosition(u16 Copy_X1,u16 Copy_X2,u16 Copy_Y1,u16 Copy_Y2);


#endif /* HAL_TFT_TFT_INTERFACE_H_ */
