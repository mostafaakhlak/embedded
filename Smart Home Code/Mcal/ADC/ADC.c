/*
 * ADC.c
 *
 *  Created on: Jun 15, 2022
 *      Author: musta
 */

#include"ADC.h"
#include"LED.h"


static void (*PV_CallBack)(void) = NULL;


void M_ADC_Void_ADCInit(void)
{
	//to select Vref
#if V_REF == AVCC
	SetBit(ADMUX_REG,6);
	ClrBit(ADMUX_REG,7);
#elif V_REF == AREF_PIN
	ClrBit(ADMUX_REG,6);
	ClrBit(ADMUX_REG,7);
#elif V_REF == _2V_PIN
	SetBit(ADMUX_REG,6);
	ClrBit(ADMUX_REG,7);
#endif
	//to select right adjust
	ClrBit(ADMUX_REG,5);
	//to select ADC channel (ADC0)
	ClrBit(ADMUX_REG,4);
	ClrBit(ADMUX_REG,3);
	ClrBit(ADMUX_REG,2);
	ClrBit(ADMUX_REG,1);
	ClrBit(ADMUX_REG,0);
	//to select prescaler (128)
	SetBit(ADCSRA_REG,2);
	SetBit(ADCSRA_REG,1);
	SetBit(ADCSRA_REG,0);
	// To Enable auto trigger mode -> free running
	SetBit(ADCSRA_REG,5);
	//to enable ADC circuit
	SetBit(ADCSRA_REG,7);
#if  ADC_MODE	==	ADC_INT
	//to enable interrupt
	SetBit(ADCSRA_REG,3);
	//to start conversion
	SetBit(ADCSRA_REG,6);
#endif
}


u16 M_ADC_U16_ADCRead(void)
{
	#if ADC_MODE	==	ADC_POL
	// to start conversion
	SetBit(ADCSRA_REG,6);
	#endif
	while (GetBit(ADCSRA_REG,4) == 0);
	return ADC_REG;
}

void M_ADC_Void_SetCallBackFun(void (*PtrFun)(void))
{
	PV_CallBack = PtrFun;
}

ISR(ADC_vect)
{
	if(PV_CallBack != NULL)
		PV_CallBack();
}


