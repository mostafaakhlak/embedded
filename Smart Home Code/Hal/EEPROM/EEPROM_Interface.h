/*
 * EEPROM_Interface.h
 *
 *  Created on: Jun 29, 2022
 *      Author: musta
 */

#ifndef HAL_EEPROM_EEPROM_INTERFACE_H_
#define HAL_EEPROM_EEPROM_INTERFACE_H_


void H_EEPROM_Void_Init(void);
void H_EEPROM_Void_WriteByte(u16 Copy_U16ByteAdd,u8 Copy_U8Data);
void H_EEPROM_Void_ReadByte(u16 Copy_U16ByteAdd , u8 * Copy_U8Ptr);

#endif /* HAL_EEPROM_EEPROM_INTERFACE_H_ */
