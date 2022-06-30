/*
 * SPI_Private.h
 *
 *  Created on: Jun 27, 2022
 *      Author: musta
 */

#ifndef MCAL_SPI_SPI_PRIVATE_H_
#define MCAL_SPI_SPI_PRIVATE_H_

#define SPI_DATA_ORDER_LSB_FIRST		0
#define SPI_DATA_ORDER_MSB_FIRST		1


#define  SPI_CLK_POLARITY_IDLE_LOW		0
#define  SPI_CLK_POLARITY_IDLE_HIGH		1

#define  SPI_CLK_PHASE_SAMPLE_FIRST		0
#define  SPI_CLK_PHASE_SAMPLE_LAST		1

#define  SPIT_CLK_SPEED_MODE_NORMAL		0
#define  SPIT_CLK_SPEED_MODE_DOUBLE		1


#define  SPI_CLK_RATE_NORMAL_MODE_4		0
#define  SPI_CLK_RATE_NORMAL_MODE_16	1
#define  SPI_CLK_RATE_NORMAL_MODE_64	2
#define  SPI_CLK_RATE_NORMAL_MODE_128	3

#define  SPI_CLK_RATE_DOUBLE_MODE_2		0
#define  SPI_CLK_RATE_DOUBLE_MODE_8		1
#define  SPI_CLK_RATE_DOUBLE_MODE_32	2
#define  SPI_CLK_RATE_DOUBLE_MODE_64	3


#define SPI_CLK_RATE_MASK				0b11111100

#endif /* MCAL_SPI_SPI_PRIVATE_H_ */
