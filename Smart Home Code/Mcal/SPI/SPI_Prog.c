/*
 * SPI_Prog.c
 *
 *  Created on: Jun 27, 2022
 *      Author: musta
 */

#include "Std.h"
#include "BitMath.h"
#include "Reg.h"
#include "SPI_Config.h"
#include "SPI_Interface.h"
#include "SPI_Private.h"
#include "avr/interrupt.h"
#include "stdlib.h"



void M_SPI_Void_MasterInit(void)
{
	//Step1:Enable SPI , Enable Master
	SetBit(SPCR_REG,6);

	SetBit(SPCR_REG,4);

	//Step2:Config data order
#if	(SPI_DATA_ORDER == SPI_DATA_ORDER_LSB_FIRST)

		SetBit(SPCR_REG,5);


#elif (SPI_DATA_ORDER == SPI_DATA_ORDER_MSB_FIRST)

		ClrBit(SPCR_REG,5);

#endif

	//Step3:Config polarity
#if	(SPI_CLK_POLARITY == SPI_CLK_POLARITY_IDLE_HIGH)

		SetBit(SPCR_REG,3);


#elif (SPI_CLK_POLARITY == SPI_CLK_POLARITY_IDLE_LOW)

		ClrBit(SPCR_REG,3);

#endif

	//Step4:Config phase
#if	(SPI_CLK_PHASE == SPI_CLK_PHASE_SAMPLE_LAST)

			SetBit(SPCR_REG,2);


#elif (SPI_CLK_PHASE == SPI_CLK_PHASE_SAMPLE_FIRST)

			ClrBit(SPCR_REG,2);

#endif

	//Step5:Config normal or double speed
#if	(SPI_CLK_SPEED_MODE == SPIT_CLK_SPEED_MODE_DOUBLE)

				SetBit(SPCR_REG,2);


#elif (SPI_CLK_SPEED_MODE == SPIT_CLK_SPEED_MODE_NORMAL)

				ClrBit(SPCR_REG,2);

#endif

	//Step6:Config CLK rate

	SPCR_REG &= SPI_CLK_RATE_MASK;
	SPCR_REG |= SPI_CLK_RATE;
}
void M_SPI_Void_SlaveInit(void)
{
	//Step1:Enable SPI , Enable Master
	SetBit(SPCR_REG,6);

	ClrBit(SPCR_REG,4);

	//Step2:Config data order
#if	(SPI_DATA_ORDER == SPI_DATA_ORDER_LSB_FIRST)

		SetBit(SPCR_REG,5);


#elif (SPI_DATA_ORDER == SPI_DATA_ORDER_MSB_FIRST)

		ClrBit(SPCR_REG,5);

#endif

	//Step3:Config polarity
#if	(SPI_CLK_POLARITY == SPI_CLK_POLARITY_IDLE_HIGH)

		SetBit(SPCR_REG,3);


#elif (SPI_CLK_POLARITY == SPI_CLK_POLARITY_IDLE_LOW)

		ClrBit(SPCR_REG,3);

#endif

	//Step4:Config phase
#if	(SPI_CLK_PHASE == SPI_CLK_PHASE_SAMPLE_LAST)

			SetBit(SPCR_REG,2);


#elif (SPI_CLK_PHASE == SPI_CLK_PHASE_SAMPLE_FIRST)

			ClrBit(SPCR_REG,2);

#endif

}
u8 M_SPI_U8_TransferByte(u8 Copy_u8Data)
{

	SPDR_REG = Copy_u8Data;

	while(GetBit(SPSR_REG,7) == 0); //busy waiting (polling)

	return SPDR_REG;
}
