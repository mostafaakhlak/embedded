/*
 * TFT_Prog.c
 *
 *  Created on: Aug 2, 2022
 *      Author: musta
 */


/*=======================================================================================
============================   The Foundation Of Function   =============================
=========================================================================================*/

/*===========   INCLUDE LIB   ===========*/
		 #include "LIB/Std_Types.h"
		 #include "LIB/Bit_Math.h"
/*======================================*/
/*===========  INCLUDE MCAL  ===========*/
		#include "MCAL/GPIO/GPIO_Config.h"
		#include "MCAL/GPIO/GPIO.h"
		#include "MCAL/STK/STK.h"
		#include "MCAL/07_SPI/SPI_interface.h"
/*======================================*/
#include "HAL/TFT/TFT_Config.h"
#include "HAL/TFT/TFT_Interface.h"
#include "HAL/TFT/TFT_Private.h"

/*===========  INCLUDE HAL   ===========*/

static void HTFT_VoidTFTWriteCommand(u8 Copy_Command)
{
	/*Set A0 PIN to LOW(WR/D/C PIN)*/
	GPIO_vWritePinValue(GPIO_A, TFT_A0_PIN, LowState);
	/*Send command through SPI1*/
	SPI_u8SendRecive(SPI3, Copy_Command);
}
static void HTFT_VoidTFTWriteData(u8 Copy_Data)
{
	/*Set A0 PIN to HIGH(WR/D/C PIN)*/
	GPIO_vWritePinValue(GPIO_A, TFT_A0_PIN, HighState);
	/*Send command through SPI1*/
	SPI_u8SendRecive(SPI3, Copy_Data);
}


void HTFT_VoidTFTInit(void)
{
	/*Reset Pulse*/
	GPIO_vWritePinValue(GPIO_A, TFT_RESET_PIN, HighState);
	STK_DelayUs(100);
	GPIO_vWritePinValue(GPIO_A, TFT_RESET_PIN, LowState);
	STK_DelayUs(1);
	GPIO_vWritePinValue(GPIO_A, TFT_RESET_PIN, HighState);
	STK_DelayUs(100);
	GPIO_vWritePinValue(GPIO_A, TFT_RESET_PIN, LowState);
	STK_DelayUs(100);
	GPIO_vWritePinValue(GPIO_A, TFT_RESET_PIN, HighState);
	STK_DelayMs(120);
	/*Sleep out command*/
	HTFT_VoidTFTWriteCommand(0x11);
	/*wait 150 ms*/
	STK_DelayMs(150);
	/*Color mode command*/
	HTFT_VoidTFTWriteCommand(0x31);
	HTFT_VoidTFTWriteData(0x05);
	/*Display on command*/
	HTFT_VoidTFTWriteCommand(0x29);
}

void HTFT_VoidTFTSetCursorPosition(u16 Copy_X1,u16 Copy_X2,u16 Copy_Y1,u16 Copy_Y2)
{
	/*Set X Address*/
	HTFT_VoidTFTWriteCommand(0x2A);	//Set X Address command
	HTFT_VoidTFTWriteData(Copy_X1);
	HTFT_VoidTFTWriteData(Copy_X1);
	HTFT_VoidTFTWriteData(Copy_X1);
	HTFT_VoidTFTWriteData(Copy_X2);

	/*Set Y Address*/
	HTFT_VoidTFTWriteCommand(0x2B);	//Set Y Address command
	HTFT_VoidTFTWriteData(Copy_Y1);
	HTFT_VoidTFTWriteData(Copy_Y1);
	HTFT_VoidTFTWriteData(Copy_Y1);
	HTFT_VoidTFTWriteData(Copy_Y2);
}
void HTFT_VoidTFTDisplayImage(const u32*Copy_Image)
{

	u16 L_Counter =0;

	/*Drow on the whole screen*/
	HTFT_VoidTFTSetCursorPosition(0, 239, 0, 320);
	/*RAM write command*/
	HTFT_VoidTFTWriteCommand(0x2C);

	for(L_Counter =0;L_Counter<76800;L_Counter++)
	{
		/*Write high byte*/
		HTFT_VoidTFTWriteData(Copy_Image[L_Counter] >> 8);
		/*Write low byte*/
		HTFT_VoidTFTWriteData(Copy_Image[L_Counter] & 0x00ff);
	}
}

