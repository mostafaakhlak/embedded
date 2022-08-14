/*
 * ADC_Prog.c
 *
 *  Created on: Aug 4, 2022
 *      Author: Mustafa Akhlak
 */


/*=======================================================================================
============================   The Foundation Of Function   =============================
=========================================================================================*/

/*===========   INCLUDE LIB   ===========*/
		 #include "LIB/Std_Types.h"
		 #include "LIB/Bit_Math.h"
/*======================================*/
/*===========  INCLUDE MCAL  ===========*/
		#include "MCAL/ADC_/ADC_Config.h"
		#include "MCAL/ADC_/ADC_Interface.h"
		#include "MCAL/ADC_/ADC_Private.h"
#include "MCAL/GPIO/GPIO.h"
/*======================================*/
/*===========  INCLUDE HAL   ===========*/


/*======================================*/

/*===========  INCLUDEAPP   ===========*/

/*=====================================*/


/*====================================================   Start_FUNCTION   ====================================================*/

void MADC_VoidADCInit(RegConversions_Number Copy_Number_Conversions)
{
	//Set ADC Resolution
	MADC_REG->CR1.RES = ADC_RESOLUTION;
	//Set scan mode
	MADC_REG->CR1.SCAN = SCAN_MODE;
	//Set Prescaller
	MADC_CCR->ADCPRE  = ADC_PRESCALER;
	//Set Conversion mode
	MADC_REG->CR2.CONT = CONVERSION_MODE;
	//number of conversions
	 MADC_REG->SQR1.SQR1_REG.SQ_L= Copy_Number_Conversions;
}
void MADC_VoidADCEnable(void)
{
	//Set ADC ON
	MADC_REG->CR2.ADON = ENABLED;
}
void MADC_VoidADCDisable(void)
{
	//Set ADC ON
	MADC_REG->CR2.ADON = DISABLED;
}
void MADC_VoidADCStartConversion(ADC_MODE Copy_Mode)
{
	switch(Copy_Mode)
	{
		case Regular:
				 MADC_REG->CR2.SWSTART =	 ENABLED;
				 break;
		case Injected:
				 MADC_REG->CR2.JSWSTART = ENABLED;
				 break;
		default: break;
	}
}
void MADC_VoidADCEnableINT(ADC_MODE Copy_Mode)
{
	switch(Copy_Mode)
	{
		case Regular:
				 MADC_REG->CR1.EOCIE =	 ENABLED;
				 break;
		case Injected:
				 MADC_REG->CR1.JEOCIE = ENABLED;
				 break;
		default: break;
	}
}
void MADC_VoidADCDisableINT(ADC_MODE Copy_Mode)
{
	switch(Copy_Mode)
	{
		case Regular:
				 MADC_REG->CR1.EOCIE =	 DISABLED;
				 break;
		case Injected:
				 MADC_REG->CR1.JEOCIE =  DISABLED;
				 break;
		default: break;
	}
}

void MADC_VoidADCDRegularSequencer(Channel_t Copy_Channel,Sequence_Order Copy_Order)
{


	 if(Copy_Order<=SEQ6)
	 {
		 MADC_REG->SQR3.SQR3 |= (( Copy_Channel)<< (Copy_Order*5U));
	 }
	 else if(Copy_Order<=SEQ12)
	 {
		 Copy_Order = Copy_Order - SEQ7;
		 MADC_REG->SQR2.SQR2 |= (( Copy_Channel)<< (Copy_Order*5U));
	 }
	 else
	 {
		 Copy_Order = Copy_Order - SEQ1;
		 MADC_REG->SQR1.SQR1 |= (( Copy_Channel)<< (Copy_Order*5U));
	 }

}

void MADC_VoidADCDInjectedSequencer(InjConversions_Number Copy_Number_Conversions,Channel_t Copy_Channel,Sequence_Order Copy_Order)
{
	MADC_REG->JSQR.JSQR_REG.JSQ_L = Copy_Number_Conversions;
	MADC_REG->JSQR.JSQR |= (( Copy_Channel)<< (Copy_Order*(5U)));
}
//Note: You should write 0 in second argument if you choose regular mode
u16 MADC_U16ADCReadData(ADC_MODE Copy_Mode,Injected_Registers Copy_Register)
{
	u16 L_U8Data = 0;
	switch(Copy_Mode)
	{
		case Regular:
				//start conversion
				 MADC_REG->CR2.SWSTART = ENABLED;
				 //test if conversion is started
				/* if(MADC_REG->SR.STRT)
				 {
					 	GPIO_vWritePinValue(GPIO_D, Pin8, HighState);
				 }*/

					 //wait until end of conversion
					 while(!(MADC_REG->SR.EOC));

					 //Read value from DR
				 	 L_U8Data = MADC_REG->ADC_DR;
				 break;
		case Injected:
				 //start conversion
				 MADC_REG->CR2.JSWSTART = ENABLED;
				 	 //wait until end of conversion
				 	 while(!(MADC_REG->SR.JEOC));
				 	 //Read value from DR
				 	 L_U8Data = MADC_REG->ADC_JDR[Copy_Register];
				 break;
		default: break;
	}
	return L_U8Data;
}
void MADC_VoidSetCallBack(void(*ptr)(void));
