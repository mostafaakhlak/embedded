/***************************************************************************************
 *************************** - NVIC_Private.h				 ***************************
***************************   -Created: 4/8/2022			 ***************************
***************************   -Author: Magdy			     ***************************
***************************   -Version : _1_				 ***************************
***************************   -Note :
									*-
									*-
 **************************************************************************************/

/**************************************************************************************

*	 - Developer can't Edit in it
*	  - Register _ Defination
*	  - Design :
					- #define	:	NO
					- Union		:	NO
					- Struct	:	YES

**************************************************************************************/
#ifndef MCAL_NVIC_NVIC_PRIVATE_H_
#define MCAL_NVIC_NVIC_PRIVATE_H_

#define NVIC_BASE_ADDRESS					0xE000E100

typedef struct
{
	volatile u32 ISER[8U];
	 u32 RESERVED0[24U]  ;
	volatile u32 ICER[8U];
	 u32 RESERVED1[24U]  ;
	volatile u32 ISPR[8U];
	 u32 RESERVED2[24U]  ;
	volatile u32 ICPR[8U];
	 u32 RESERVED3[24U]  ;
	volatile u32 IABR[8U];
	 u32 RESERVED4[56U]  ;
	volatile u8 IPR[240U];
	 u32 RESERVED5[644U] ;
	volatile u32 STIR;
}NVIC_TypeDef;

#define NVIC				((NVIC_TypeDef*)(NVIC_BASE_ADDRESS))
#endif /* MCAL_NVIC_NVIC_PRIVATE_H_ */
