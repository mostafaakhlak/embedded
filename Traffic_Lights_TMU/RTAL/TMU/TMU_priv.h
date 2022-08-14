/*
 * TMU_priv.h
 *
 *  Created on: Aug 8, 2022
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef TMU_PRIV_H_
#define TMU_PRIV_H_

#define TIMER0			54
#define TIMER1			23
#define TIMER2			78


typedef struct
{
	void(*pFun)(void);
	u16 Periodicity;
}TCB_t;


/*TIMSK*/
#define TIMSK	*((volatile u8*) 0x59)

/*TIFR*/
#define TIFR	*((volatile u8*) 0x58)

/*TCCR*/
#define TCCR0	*((volatile u8*) 0x53)
#define TCCR1A	*((volatile u8*) 0x4f)
#define TCCR1B	*((volatile u8*) 0x4e)
#define TCCR2	*((volatile u8*) 0x45)

/*TCNT*/
#define TCNT0	*((volatile u8*) 0x52)

#define TCNT1H	*((volatile u8*) 0x4d)
#define TCNT1L	*((volatile u8*) 0x4c)

#define TCNT1	*((volatile u16*) 0x4c)

#define TCNT2	*((volatile u8*) 0x44)

/*OCR*/
#define OCR0	*((volatile u8*) 0x5c)
#define OCR1AH	*((volatile u8*) 0x4b)
#define OCR1AL	*((volatile u8*) 0x4a)

#define OCR1A	*((volatile u16*) 0x4a)

#define OCR1BH	*((volatile u8*) 0x49)
#define OCR1BL	*((volatile u8*) 0x48)

#define OCR1B	*((volatile u16*) 0x48)

#define OCR2	*((volatile u8*) 0x43)


#define ICR1L	*((volatile u8*) 0x46)
#define ICR1H	*((volatile u8*) 0x47)


#endif /* TMU_PRIV_H_ */
