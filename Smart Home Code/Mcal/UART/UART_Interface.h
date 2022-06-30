/*
 * UART_Interface.h
 *
 *  Created on: Jun 26, 2022
 *      Author: musta
 */

#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_

void M_UART_void_Init(void);
void M_UART_void_SendByte(u8 copy_u8Byte);
void M_UART_void_receiveByte(u8 * copy_u8ptr);
void M_UART_void_sendString(u8 * str);

#endif /* MCAL_UART_UART_INTERFACE_H_ */
