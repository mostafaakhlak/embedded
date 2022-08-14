/*
 * ADC_Private.h
 *
 *  Created on: Aug 4, 2022
 *      Author: Mustafa Akhlak
 */

#ifndef MCAL_ADC__ADC_PRIVATE_H_
#define MCAL_ADC__ADC_PRIVATE_H_

/*****************************************************_ADC_BASE_ADDRESS_***************************************************************************/

#define ADC_BASE_ADDESS			(0x40012000)
#define ADC_CCR_BASE_ADDRESS	(0x40012000 + 0x304)

/*****************************************************_ADC_REGESTERS_UNIONS_***************************************************************************/
typedef struct  				//Status Register
{
	volatile u32 AWD	:1;
	volatile u32 EOC	:1;
	volatile u32 JEOC	:1;
	volatile u32 JSTRT	:1;
	volatile u32 STRT	:1;
	volatile u32 OVR	:1;
}ADC_SR;

typedef struct				//Control Register 1
{
	volatile u32 AWDCH		:5;
	volatile u32 EOCIE		:1;
	volatile u32 AWDIE		:1;
	volatile u32 JEOCIE		:1;
	volatile u32 SCAN		:1;
	volatile u32 AWDSG_L	:1;
	volatile u32 JAUTO		:1;
	volatile u32 DISC_EN	:1;
	volatile u32 JDISCE_N	:1;
	volatile u32 DISCNUM	:3;
	volatile u32 Reserved	:6;
	volatile u32 JAWDEN		:1;
	volatile u32 AWDEN		:1;
	volatile u32 RES		:2;
	volatile u32 OVRIE		:1;
}ADC_CR1;


typedef struct				//Control Register 2
{
	volatile u32 ADON		:1;
	volatile u32 CONT		:1;
	volatile u32 Reserved0	:6;
	volatile u32 DMA		:1;
	volatile u32 DDS		:1;
	volatile u32 EOCS		:1;
	volatile u32 ALIGN		:1;
	volatile u32 Reserved1	:4;
	volatile u32 JEXTSEL	:4;
	volatile u32 JEXTEN		:2;
	volatile u32 JSWSTART	:1;
	volatile u32 reserved2	:1;
	volatile u32 EXTSEL		:4;
	volatile u32 EXTEN		:2;
	volatile u32 SWSTART	:1;
}ADC_CR2;


typedef union				//Sample time register 1  /*from channel 10 to 18*/
{
	struct REG1
	{
		volatile u32 SMP10		:3;
		volatile u32 SMP11		:3;
		volatile u32 SMP12		:3;
		volatile u32 SMP13		:3;
		volatile u32 SMP14		:3;
		volatile u32 SMP15		:3;
		volatile u32 SMP16		:3;
		volatile u32 SMP17		:3;
		volatile u32 SMP18		:3;
	}SMPR1_REG;
	volatile u32 SMPR1_t	  ;
}ADC_SMPR1;

typedef union				//Sample time register 1  /*from channel 0 to 9*/
{
	struct REG2
	{
		volatile u32 SMP0		:3;
		volatile u32 SMP1		:3;
		volatile u32 SMP2		:3;
		volatile u32 SMP3		:3;
		volatile u32 SMP4		:3;
		volatile u32 SMP5		:3;
		volatile u32 SMP6		:3;
		volatile u32 SMP7		:3;
		volatile u32 SMP8		:3;
		volatile u32 SMP9		:3;
	}SMPR2_REG;
	volatile u32 SMPR2_t	  ;
}ADC_SMPR2;


typedef union				//Regular sequence register 1  /*from channel 13 to 16*/
{
	struct REG3
	{
		volatile u32 SQ13		:5;
		volatile u32 SQ14		:5;
		volatile u32 SQ15		:5;
		volatile u32 SQ16		:5;
		volatile u32 SQ_L	 	:4;
	}SQR1_REG;
	volatile u32 SQR1		  ;
}ADC_SQR1;

typedef union				//Regular sequence register 2  /*from channel 7 to 12*/
{
	struct REG4
	{
		volatile u32 SQ7		:5;
		volatile u32 SQ8		:5;
		volatile u32 SQ9		:5;
		volatile u32 SQ10		:5;
		volatile u32 SQ11	 	:5;
		volatile u32 SQ12	 	:5;
	}SQR2_REG;
	volatile u32 SQR2		  ;
}ADC_SQR2;


typedef union				//Regular sequence register 3  /*from channel 1 to 6*/
{
	struct REG5
	{
		volatile u32 SQ1		:5;
		volatile u32 SQ2		:5;
		volatile u32 SQ3		:5;
		volatile u32 SQ4		:5;
		volatile u32 SQ5	 	:5;
		volatile u32 SQ6	 	:5;
	}SQR3_REG;
	volatile u32 SQR3		  ;
}ADC_SQR3;


typedef union				//Injected sequence register
{
	struct REG6
	{
		volatile u32 JSQ1		:5;
		volatile u32 JSQ2		:5;
		volatile u32 JSQ3		:5;
		volatile u32 JSQ4		:5;
		volatile u32 JSQ_L	 	:2;
	}JSQR_REG;

	volatile u32 JSQR		  ;
}ADC_JSQR;


/*****************************************************_ADC_STRUCTS_***************************************************************************/
typedef struct
{
	ADC_SR 		SR				;
	ADC_CR1		CR1				;
	ADC_CR2		CR2				;
	ADC_SMPR1	SMPR1		 	;
	ADC_SMPR2	SMPR2			;
	volatile u32 ADC_JOFR[4]	;
	volatile u32 ADC_HTR		;
	volatile u32 ADC_LTR		;
	ADC_SQR1	SQR1			;
	ADC_SQR2	SQR2			;
	ADC_SQR3	SQR3			;
	ADC_JSQR	JSQR			;
	volatile u32 ADC_JDR[4]		;
	volatile u32 ADC_DR			;
}ADC_REG;

typedef struct
{
	volatile u32 Reserved0	:16	;
	volatile u32 ADCPRE		:2	;
	volatile u32 Reserved1	:4	;
	volatile u32 VBATE		:1	;
	volatile u32 TSVREFE	:1	;
}ADC_CCR;

/*****************************************************_ADC_POINTERS_***************************************************************************/

#define MADC_REG			((ADC_REG*)(ADC_BASE_ADDESS))
#define MADC_CCR			((ADC_CCR*)(ADC_CCR_BASE_ADDRESS))

/********************************************************_ADC_MACROS_************************************************************************************/
#define 	_12_BIT_RESOLUTION  		(0b00)
#define 	_10_BIT_RESOLUTION			(0b01)
#define 	_8_BIT_RESOLUTION			(0b10)
#define 	_6_BIT_RESOLUTION 	 	 	(0b11)


#define 	ENABLE_SCAN					(1U)
#define 	DISABLE_SCAN				(0U)

#define 	ENABLED						(1U)
#define 	DISABLED					(0U)

#define  	PRESCALLER_2				(0b00)
#define 	PRESCALLER_4				(0b01)
#define  	PRESCALLER_6				(0b10)
#define  	PRESCALLER_8				(0b11)

#define 	SINGLE_MODE					(0U)
#define 	CONTINUEOUS_MODE			(1U)



#endif /* MCAL_ADC__ADC_PRIVATE_H_ */
