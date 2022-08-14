/*
 * ADC_Interface.h
 *
 *  Created on: Aug 4, 2022
 *      Author: Mustafa Akhlak
 */

#ifndef MCAL_ADC__ADC_INTERFACE_H_
#define MCAL_ADC__ADC_INTERFACE_H_

/*********************************************************_ADC_ENUMS_****************************************************************************/

typedef enum
{
	CHANNEL_0  = (0U)	,
	CHANNEL_1  			,
	CHANNEL_2  			,
	CHANNEL_3  			,
	CHANNEL_4  			,
	CHANNEL_5  			,
	CHANNEL_6  			,
	CHANNEL_7  			,
	CHANNEL_8  			,
	CHANNEL_9  			,
	CHANNEL_10 			,
	CHANNEL_11 			,
	CHANNEL_12 			,
	CHANNEL_13 			,
	CHANNEL_14 			,
	CHANNEL_15 			,
	CHANNEL_16 			,
	CHANNEL_17 			,
	CHANNEL_18
}Channel_t;


typedef enum
{
	Regular			=0u,
	Injected
}ADC_MODE;


typedef enum
{
	Single			=0u,
	Continueous
}Conversion_Mode;

typedef enum
{
	JDR1			=0u,
	JDR2			   ,
	JDR3			   ,
	JDR4
}Injected_Registers;

typedef enum
{
	SEQ1		   =(0U),
	SEQ2				,
	SEQ3				,
	SEQ4				,
	SEQ5				,
	SEQ6				,
	SEQ7				,
	SEQ8				,
	SEQ9				,
	SEQ10				,
	SEQ11				,
	SEQ12				,
	SEQ13				,
	SEQ14				,
	SEQ15				,
	SEQ16
}Sequence_Order;


typedef enum
{
	_1_Conversion  		=(0x0),
	_2_Conversions			  ,
	_3_Conversions			  ,
	_4_Conversions			  ,
	_5_Conversions			  ,
	_6_Conversions			  ,
	_7_Conversions			  ,
	_8_Conversions			  ,
	_9_Conversions			  ,
	_10_Conversions			  ,
	_11_Conversions			  ,
	_12_Conversions			  ,
	_13_Conversions			  ,
	_14_Conversions			  ,
	_15_Conversions			  ,
	_16_Conversions
}RegConversions_Number;


typedef enum
{
	_1_InjConversion  		=(0b00),
	_2_InjConversions			   ,
	_3_InjConversions			   ,
	_4_InjConversions
}InjConversions_Number;


/****************************************************_ADC_FUNCTION_PROTOTYPES_************************************************************************************/
void MADC_VoidADCInit(RegConversions_Number Copy_Number_Conversions);
void MADC_VoidADCEnable(void);
void MADC_VoidADCDisable(void);
void MADC_VoidADCStartConversion(ADC_MODE Copy_Mode);
void MADC_VoidADCEnableINT(ADC_MODE Copy_Mode);
void MADC_VoidADCDisableINT(ADC_MODE Copy_Mode);
void MADC_VoidADCDRegularSequencer(Channel_t Copy_Channel,Sequence_Order Copy_Order);
void MADC_VoidADCDInjectedSequencer(InjConversions_Number Copy_Number_Conversions,Channel_t Copy_Channel,Sequence_Order Copy_Order);
u16 MADC_U16ADCReadData(ADC_MODE Copy_Mode,Injected_Registers Copy_Register);
void MADC_VoidSetCallBack(void(*ptr)(void));


#endif /* MCAL_ADC__ADC_INTERFACE_H_ */
