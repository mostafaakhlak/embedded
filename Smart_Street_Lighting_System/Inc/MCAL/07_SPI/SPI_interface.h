/******************************************************************
   -	.h
   - Created: /5/2022
   - Author: Magdy 
   - Version : V01
 *****************************************************************/
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include "MCAL/07_SPI/SPI_private.h"



void SPI_vInit(void);
u8 SPI_u8SendRecive(SPI_t* SPI_ptrIndex,u8 Copy_u8Data);







#endif
