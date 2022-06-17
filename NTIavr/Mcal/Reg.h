/*
 * Reg.h
 *
 *  Created on: 07/06/2022
 *      Author: Mostafa Akhlak Mohamed
 */

#ifndef REG_H_
#define REG_H_

#include"Std.h"


#define DDRA	*(volatile u8*)0x3A
#define PINA	*(volatile u8*)0x39
#define PORTA	*(volatile u8*)0x3B


#define DDRB	*(volatile u8*)0x37
#define PINB	*(volatile u8*)0x36
#define PORTB	*(volatile u8*)0x38


#define DDRC	*(volatile u8*)0x34
#define PINC	*(volatile u8*)0x33
#define PORTC	*(volatile u8*)0x35


#define DDRD	*(volatile u8*)0x30
#define PIND	*(volatile u8*)0x30
#define PORTD	*(volatile u8*)0x31
/*******************************************EXTINT_REGESTERS***************************************************/
#define MCUCR_REG	*(volatile u8*)0x55
#define GICR_REG	*(volatile u8*)0x5B
#define SREG_REG	*(volatile u8*)0x5F
/*******************************************ADC_REGESTERS***************************************************/
#define ADMUX_REG	*(volatile u8*)0x27
#define ADCSRA_REG	*(volatile u8*)0x26
#define ADCL_REG	*(volatile u8*)0x24
#define ADCH_REG	*(volatile u8*)0x25
#define ADC_REG		*(volatile u16*)0x24


#endif /* REG_H_ */
