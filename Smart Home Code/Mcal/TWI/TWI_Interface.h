/*
 * TWI_Interface.h
 *
 *  Created on: Jun 28, 2022
 *      Author: musta
 */

#ifndef MCAL_TWI_TWI_INTERFACE_H_
#define MCAL_TWI_TWI_INTERFACE_H_

//this code will activate IIC driver to talk to Ext EEPROM
//Atmega32 is master

/**************************************************************_MACROS_**************************************************************************/


/****************Master as Transmitter**************************/

#define TWI_MT_START_SENT						0x08
#define TWI_MT_REPEATED_START_SENT				0x10
#define TWI_MT_SLA_WRITE_ACK					0x18
#define TWI_MT_SLA_WRITE_NACK					0x20
#define TWI_MT_DATA_SENT_ACK					0x28
#define TWI_MT_DATA_SENT_NACK					0x30
#define TWI_MT_DATA_ARBITRATION_LOST			0x38

/*****************Master as Receiver****************************/


#define TWI_MR_START_SENT						0x08
#define TWI_MR_REPEATED_START_SENT				0x10
#define TWI_MR_SLA_READ_ACK						0x40
#define TWI_MR_SLA_READ_NACK					0x48
#define TWI_MR_DATA_READ_ACK					0x50
#define TWI_MR_DATA_READ_NACK					0x58
#define TWI_MR_DATA_ARBITRATION_LOST			0x38

/**************************************************************_PROTOTYPES_**************************************************************************/


void M_TWI_Void_Init(void);
void M_TWI_Void_SendStart(void);
void M_TWI_Void_SendStop(void);
void M_TWI_Void_SendByte(u8 Copt_u8Data);
u8 M_TWI_U8_RecieveByte_Ack(void);
u8 M_TWI_U8_RecieveByte_NAck(void);
u8 M_TWI_U8_GetStatus(void);



#endif /* MCAL_TWI_TWI_INTERFACE_H_ */
