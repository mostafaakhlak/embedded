/*
 * EEPROM_Prog.c
 *
 *  Created on: Jun 29, 2022
 *      Author: musta
 */

#include "Std.h"
#include "EEPROM_Interface.h"
#include "EEPROM_Config.h"
#include "EEPROM_Private.h"
#include "TWI_Interface.h"

void H_EEPROM_Void_Init(void)
{
	M_TWI_Void_Init();
}
void H_EEPROM_Void_WriteByte(u16 Copy_U16ByteAdd,u8 Copy_U8Data)
{

	u8 _3MSB = 0;
	//step 1 : send start and check ack
	M_TWI_Void_SendStart();
	if(M_TWI_U8_GetStatus() != TWI_MT_START_SENT)
	{
		return;
	}
	//step 2 : send 1st address frame(address + r/w)(address = 0b1010 A10 A9 A8 R/w)
	_3MSB = (u8)((Copy_U16ByteAdd & _3MSB_MASK ) >> 7);
	M_TWI_Void_SendByte(EEPROM_ADD_MASK | _3MSB);
	if(M_TWI_U8_GetStatus() != TWI_MT_SLA_WRITE_ACK)
	{
		return;
	}
	//step 3 : send 2nd address frame(A7->A0)
	M_TWI_Void_SendByte((u8) Copy_U16ByteAdd);
	if(M_TWI_U8_GetStatus() != TWI_MT_DATA_SENT_ACK)
	{
		return;
	}
	//step 4 : send data
	M_TWI_Void_SendByte(Copy_U8Data);
	if(M_TWI_U8_GetStatus() != TWI_MT_DATA_SENT_ACK)
	{
		return;
	}
	//step 5 : stop
	M_TWI_Void_SendStop();
}
void H_EEPROM_Void_ReadByte(u16 Copy_U16ByteAdd , u8 * Copy_U8Ptr)
{
	u8 _3MSB = 0;
	//step 1 : send start and check ack
	M_TWI_Void_SendStart();
	if(M_TWI_U8_GetStatus() != TWI_MT_START_SENT)
	{
		return;
	}
	//step 2 : send 1st address frame(address + r/w)(address = 0b1010 A10 A9 A8 R/w)
	_3MSB = (u8)((Copy_U16ByteAdd & _3MSB_MASK ) >> 7);
	M_TWI_Void_SendByte(EEPROM_ADD_MASK | _3MSB);
	if(M_TWI_U8_GetStatus() != TWI_MT_SLA_WRITE_ACK)
	{
		return;
	}
	//step 3 : send 2nd address frame(A7->A0)
	M_TWI_Void_SendByte((u8) Copy_U16ByteAdd);
	if(M_TWI_U8_GetStatus() != TWI_MT_DATA_SENT_ACK)
	{
		return;
	}

	//step 4 : Repeated start
	M_TWI_Void_SendStart();
	if(M_TWI_U8_GetStatus() != TWI_MR_REPEATED_START_SENT)
	{
		return;
	}
	//step 5 : Send fixed address + R
	M_TWI_Void_SendByte(EEPROM_ADD_MASK | READ_BIT);
	if(M_TWI_U8_GetStatus() != TWI_MR_SLA_READ_ACK)
	{
		return;
	}
	//step 6 : Receive data
	* Copy_U8Ptr = M_TWI_U8_RecieveByte_Ack();
	if(M_TWI_U8_GetStatus() != TWI_MR_DATA_READ_ACK)
	{
		return;
	}
	//step 7 : stop
	M_TWI_Void_SendStop();
}
