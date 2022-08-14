/*=======================================================================================
============================   The Foundation Of Function   =============================
=========================================================================================*/

/*===========   INCLUDE LIB   ===========*/
		 #include "LIB/Std_Types.h"
		 #include "LIB/Bit_Math.h"
/*======================================*/
/*===========  INCLUDE MCAL  ===========*/
		#include "MCAL/UART/UART_Private.h"
		#include "MCAL/UART/UART.h"
		#include "MCAL/UART/UART_Config.h"
/*======================================*/
/*===========  INCLUDE HAL   ===========*/


/*======================================*/

/*===========  INCLUDEAPP   ===========*/

/*=====================================*/
void UART6_vInit(void)
{
	UART6->CR1=0;
	/*Enable UART*/
	UART6->CR1 |= USART_CR1_UE;
	/*Mode*/
	/*Check Mode and apply Configuration*/

	/*Parity Mode*/
#if UART6_PARITY_MODE == UART_PARITY_DISABLE
	UART6->CR1 &=~ USART_CR1_PCE;
#elif UART6_PARITY_MODE == UART_PARITY_ODD
	UART6->CR1.PCE=1;
	UART6->CR1.PS=1;
#elif UART6_PARITY_MODE == UART_PARITY_EVEN
	UART6->CR1.PCE=1;
	UART6->CR1.PS=0;
#endif

	/*Stop Bits*/
#if UART6_STOP_BITS		== ONE_STOP_BIT
	UART6->CR2 &=~ USART_CR2_STOP;
#elif UART6_STOP_BITS		== HALF_STOP_BIT
	UART6->CR2.STOP=1;
#elif UART6_STOP_BITS		== ONE_HALF_STOP_BITS
	UART6->CR2.STOP=3;
#elif UART6_STOP_BITS		== TWO_STOP_BITS
	UART6->CR2.STOP=2;
#endif

	/*Character size*/
#if UART6_WORD		==	EIGHT_DATA_BITS
	//UART6->CR1.M=0;
#elif UART6_WORD		==	NINE_DATA_BITS
	UART6->CR1.M=1;
#endif

	/*Baud Rate*/
	/*9600*/
	UART6->BRR = 0;
	UART6->BRR = (0x3)| (0x68<<4);

	/*Enable Tx*/
	UART6->CR1|=USART_CR1_TE;
	/*Enable Rx*/
	UART6->CR1|=USART_CR1_RE;
}
u8 UART6_vSendReceive(u8 Copy_u8Data)
{
	u8 L_u16ReceiveData;
	/*Wait till the transmisson complete*/
		while(!(UART6->SR & USART_SR_TXE));
		UART6->DR = Copy_u8Data;

		/*Wait till the transmisson complete*/
			while(!(UART6->SR & USART_SR_RXNE));
			L_u16ReceiveData = UART6->DR;
			/*return data*/
			return L_u16ReceiveData;
}
u8 UART6_vReceive(void)
{
	u8 L_u16ReceiveData;

	/*Wait till the transmisson complete*/
		while(!(UART6->SR & USART_SR_RXNE));
		L_u16ReceiveData = UART6->DR;
		/*return data*/
		return L_u16ReceiveData;
}
