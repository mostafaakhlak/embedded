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
/*******************************************EXTINT_REGESTERS**************************************************************************/
#define MCUCR_REG	*(volatile u8*)0x55
#define GICR_REG	*(volatile u8*)0x5B
#define SREG_REG	*(volatile u8*)0x5F
/*******************************************ADC_REGESTERS*****************************************************************************/
#define ADMUX_REG	*(volatile u8*)0x27
#define ADCSRA_REG	*(volatile u8*)0x26
#define ADCL_REG	*(volatile u8*)0x24
#define ADCH_REG	*(volatile u8*)0x25
#define ADC_REG		*(volatile u16*)0x24
/*******************************************TIMER0_REGESTERS**************************************************************************/
#define TCNT0_REG	*(volatile u8*)0x52
#define TCCR0_REG	*(volatile u8*)0x53
#define OCR0_REG	*(volatile u8*)0x5C
#define TIMSK_REG	*(volatile u8*)0x59
#define TIFR_REG	*(volatile u8*)0x58

/*******************************************TIMER0_REGESTERS**************************************************************************/
#define TCCR1A_REG	*(volatile u8*)0x4F
#define TCCR1B_REG	*(volatile u8*)0x4E
#define ICR_REG		*(volatile u16*)0x46

/*******************************************************_UART_REGISTERS_**************************************************************/
#define UART_UDR    (*(volatile u8*)0x2C)
#define UART_UCSRA  (*(volatile u8*)0x2B)
#define UART_UCSRB  (*(volatile u8*)0x2A)
#define UART_UCSRC  (*(volatile u8*)0x40)
#define UART_UBRRH  (*(volatile u8*)0x40)
#define UART_UBRRL  (*(volatile u8*)0x29)

//UART_UCSRA  bits
#define RXC   7 // flag of Rx complete
#define TXC   6
#define UDRE  5 // flag of (Tx)DR empty
#define FE    4 // Frame error
#define DOR   3 // data over run
#define PE    2 // parity error
#define U2X   1
#define MPCM  0

//UART_UCSRB  bits
#define RXCIE   7
#define TXCIE   6
#define UDRIE   5
#define RXEN    4
#define TXEN    3
#define UCSZ2   2
#define RXB8    1
#define TXB8    0

//UART_UCSRC  bits
#define URSEL    7
#define UMSEL    6
#define UPM1     5
#define UPM0     4
#define USBS     3
#define UCSZ1    2
#define UCSZ0    1
#define UCPOL    0

/*******************************************************_SPI_REGISTERS_***************************************************************/
#define SPCR_REG    (*(volatile u8*)0x2D)
#define SPSR_REG 	(*(volatile u8*)0x2E)
#define SPDR_REG	(*(volatile u8*)0x2F)


/*******************************************************_TWI_REGISTERS_***************************************************************/

#define TWDR_REG    (*(volatile u8*)0x23)
#define TWSR_REG 	(*(volatile u8*)0x21)
#define TWCR_REG	(*(volatile u8*)0x56)
#define TWAR_REG    (*(volatile u8*)0x22)
#define TWBR_REG 	(*(volatile u8*)0x20)

/******************************************************_WDT_REGISTER_*****************************************************************/
#define WDTCR_REG 	(*(volatile u8*)0x41)

#endif /* REG_H_ */
