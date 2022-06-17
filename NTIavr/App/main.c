/*
 * main.c
 *
 *  Created on: 07/06/2022
 *      Author: Mostafa Akhlak Mohamed
 */

#include<avr/interrupt.h>
#include"Buzzer.h"
#include"Led.h"
#include"SSD.h"
#include"PushButton.h"
#include"LCD.h"
#include"KeyPad.h"
#include"util/delay.h"
#include"ExtInt.h"
#include"ADC.h"

void A_ExtInt0Exc(void);

int main()
{
	M_ADC_Void_ADCInit();
	H_LCD_Void_LCDInit();
	f32 x=0;

	while(1)
		{
		 	 x=M_ADC_U16_ADCRead();
		 	 H_LCD_Void_LCDWriteString("Temp =");
		 	 H_LCD_Void_LCDWriteNumber(x/4);
		 	 H_LCD_Void_LCDWriteCharacter('C');
		 	 _delay_ms(1000);
		 	 H_LCD_Void_LCDClr();

		}


	return 0;
}

void A_ExtInt0Exc(void)
{
	H_Led_Void_LedOn(BLU_LED);
	H_Buzzer_Void_BuzzerOn();
	_delay_ms(1000);
	H_Led_Void_LedOff(BLU_LED);
	H_Buzzer_Void_BuzzerOff();
}
