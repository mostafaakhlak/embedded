/*
 * UART_Prog.c
 *
 *  Created on: Jun 26, 2022
 *      Author: musta
 */


#include "Std.h"
#include "BitMath.h"
#include "Reg.h"
#include "UART_private.h"
#include "UART_config.h"
#include "UART_Interface.h"

void M_UART_void_Init(void)
{
   // step 1 : Enable Tx , Rx
	SetBit(UART_UCSRB,TXEN  );
	SetBit(UART_UCSRB,RXEN  );
	//step 2 : choose data bits length
	 //choose register C
	SetBit(UART_UCSRC,URSEL);
	// config data bits
	ClrBit(UART_UCSRB,UCSZ2);
	UART_UCSRC &= UART_DATA_BITS_MASK;
	UART_UCSRC |= UART_DATA_BITS << 1;

	//step 3 : parity config
	UART_UCSRC &= UART_PARITY_MASK;
	UART_UCSRC |= UART_PARITY_MODE << 4;
	//step 4 : config as Asynchrounce
	ClrBit(UART_UCSRC, UMSEL);

	//step 5 : config stop bits
#if(UART_STOP_BITS  == UART_STOP_BITS_1)
	ClrBit(UART_UCSRC,USBS);
#elif(UART_STOP_BITS  == UART_STOP_BITS_2)
	SetBit(UART_UCSRC,USBS);
#endif
	//step 6: config Baud Rate
	//Accsess UBRRH & clr register
	UART_UBRRH  = 0;
	UART_UBRRH |= UART_BAUD_RATE >> 8;

	UART_UBRRL = UART_BAUD_RATE;

}
void M_UART_void_SendByte(u8 copy_u8Byte)
{
   while(GetBit(UART_UCSRA ,UDRE) == 0);//busy waiting until flag is raised
   UART_UDR  = copy_u8Byte;
}
void M_UART_void_receiveByte(u8 * copy_u8ptr)
{
	while(GetBit(UART_UCSRA ,RXC) == 0);
	*copy_u8ptr = UART_UDR;
}
void M_UART_void_sendString(u8 * str)
{
	u32 i = 0;
   while(str[i] != '\0')
   {
	   M_UART_void_SendByte(str[i]);
	 i++;
   }
}
