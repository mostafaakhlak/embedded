/*
 * Reg.h
 *
 *  Created on: 07/06/2022
 *      Author: Mostafa Akhlak Mohamed
 */

#ifndef REG_H_
#define REG_H_

#include"Std.h"


#define DDRA_REG	*(volatile u8*)0x3A
#define PINA_REG	*(volatile u8*)0x39
#define PORTA_REG	*(volatile u8*)0x3B


#define DDRB_REG	*(volatile u8*)0x37
#define PINB_REG	*(volatile u8*)0x36
#define PORTB_REG	*(volatile u8*)0x38


#define DDRC_REG	*(volatile u8*)0x34
#define PINC_REG	*(volatile u8*)0x33
#define PORTC_REG	*(volatile u8*)0x35


#define DDRD_REG	*(volatile u8*)0x30
#define PIND_REG	*(volatile u8*)0x30
#define PORTD_REG	*(volatile u8*)0x31
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
/*******************************************TIMER0_REGESTERS***************************************************/
#define TCNT0_REG	*(volatile u8*)0x52
#define TCCR0_REG	*(volatile u8*)0x53
#define OCR0_REG	*(volatile u8*)0x5C
#define TIMSK_REG	*(volatile u8*)0x59
#define TIFR_REG	*(volatile u8*)0x58

/*******************************************TIMER0_REGESTERS***************************************************/
#define TCCR1A_REG	*(volatile u8*)0x4F
#define TCCR1B_REG	*(volatile u8*)0x4E
#define ICR_REG	*(volatile u16*)0x46


#endif /* REG_H_ */
