/*
 * TWI_Prog.c
 *
 *  Created on: Jun 28, 2022
 *      Author: musta
 */

#include "Std.h"
#include "BitMath.h"
#include "Reg.h"
#include "TWI_Config.h"
#include "TWI_Interface.h"
#include "TWI_Private.h"

void M_TWI_Void_Init(void)
{
	//SCLK = 400KHz,FCPU = 8MHz,PRESCALER = 1;
	TWBR_REG = 0x02;
	//set prescaler to 1
	TWSR_REG = 0;
	//enable TWI,Enable ACK
	SetBit(TWCR_REG,2);
	SetBit(TWCR_REG,6);
}
void M_TWI_Void_SendStart(void)
{
	SetBit(TWCR_REG,5);
	SetBit(TWCR_REG,7);
	while(! GetBit(TWCR_REG,7));
}
void M_TWI_Void_SendStop(void)
{
	SetBit(TWCR_REG,4);
	SetBit(TWCR_REG,7);
}
void M_TWI_Void_SendByte(u8 Copt_u8Data)
{
	TWDR_REG = Copt_u8Data;
	SetBit(TWCR_REG,7);
	while(! GetBit(TWCR_REG,7));
}
u8 M_TWI_U8_RecieveByte_Ack(void)
{
	SetBit(TWCR_REG,2);
	SetBit(TWCR_REG,6);
	SetBit(TWCR_REG,7);
	while(! GetBit(TWCR_REG,7));
	return TWDR_REG;
}
u8 M_TWI_U8_RecieveByte_NAck(void)
{
	SetBit(TWCR_REG,2);
	SetBit(TWCR_REG,7);
	while(! GetBit(TWCR_REG,7));
	return TWDR_REG;
}
u8 M_TWI_U8_GetStatus(void)
{
	return (TWSR_REG & TWI_SR_MASK);
}
