/***************************************************************************************
 *************************** - GPIO.h				 ***************************
***************************   -Created: 4/15/2022			 ***************************
***************************   -Author: Magdy			     ***************************
***************************   -Version : _1_				 ***************************
***************************   -Note :
									*-
									*-
 **************************************************************************************/

/*=====================================================================================
		* What i sell To Customer
		*  The Archictect Give The API
						- The Name Of Function
						- What is The Input
						- What Is The Output
						- Macro

======================================================================================*/
#ifndef MCAL_GPIO_GPIO_H_
#define MCAL_GPIO_GPIO_H_
#include "LIB/Std_Types.h"

#define CLERA_PORT		0xffff0000
typedef enum
{
	GPIO_A=0,
	GPIO_B=1,
	GPIO_C=2,
	GPIO_D=3,
	GPIO_E=4,
	GPIO_H=5
}GPIO_PortNum;
typedef enum
{
	Pin0=0,
	Pin1=1,
	Pin2=2,
	Pin3=3,
	Pin4=4,
	Pin5=5,
	Pin6=6,
	Pin7=7,
	Pin8=8,
	Pin9=9,
	Pin10=10,
	Pin11=11,
	Pin12=12,
	Pin13=13,
	Pin14=14,
	Pin15=15
}GPIO_PinNum;
typedef enum
{
	LowState=0,
	HighState=1
}GPIO_State;

typedef enum
{
	GPIO_Input=0,
	GPIO_Output=1,
	GPIO_ALF=2,
	GPIO_Analog=3
}GPIO_Mode;

typedef enum
{
	PushPull=0,
	OpenDrain=1
}GPIO_Output_Type;

typedef enum
{
	LowSpeed=0,         /*!< IO works at 2 MHz, please refer to the product datasheet */
	MediumSpeed=1,      /*!< range 12,5 MHz to 50 MHz, please refer to the product datasheet */
	HighSpeed=2,        /*!< range 25 MHz to 100 MHz, please refer to the product datasheet  */
	VeryHighSpeed=3     /*!< range 50 MHz to 200 MHz, please refer to the product datasheet  */
}GPIO_Speed;


typedef enum
{
	Float=0,       /*!< No Pull-up or Pull-down activation  */
	Pull_Up=1,     /*!< Pull-up activation                  */
	Pull_Down=2    /*!< Pull-down activation                */
}GPIO_PUPD;
typedef enum
{
	AF0=0,
	AF1=1,
	AF2=2,
	AF3=3,
	AF4=4,
	AF5=5,
	AF6=6,
	AF7=7,
	AF8=8,
	AF9=9,
	AF10=10,
	AF11=11,
	AF12=12,
	AF13=13,
	AF14=14,
	AF15=15
}GPIO_AF;

/*Configure GPIO pin*/
/*===============   1-Function Set The Mode Of Pin	 ===============*/
void GPIO_vSetMode(GPIO_PortNum	Copy_u8GPIOPortNum,GPIO_PinNum Copy_u8Pin,GPIO_Mode	Copy_u8Mode);
/*===============   2-Function Set The Type Of OutPut (OpenDrain = 0 , PushPull = 1)  ===============*/
void GPIO_vSetType(GPIO_PortNum	Copy_u8GPIOPortNum,GPIO_PinNum Copy_u8Pin,GPIO_Output_Type	Copy_u8Type);
/*===============	3-Function Set The Speed Of output pin  (LOW , Meduim , High ,VeryHaigh	===============*/
void GPIO_vSetSpeed(GPIO_PortNum	Copy_u8GPIOPortNum,GPIO_PinNum Copy_u8Pin,GPIO_Speed	Copy_u8Speed);
/*===============   4-Function Set The PULL ( Almost Input ) ( OFF , UP , DOWN )  ===============*/
void GPIO_vSetPullUpPullDown(GPIO_PortNum	Copy_u8GPIOPortNum,GPIO_PinNum Copy_u8Pin,GPIO_PUPD	Copy_u8PullUpPullDown);
/*===============   5-Function To Set ALTF   ===============*/
void GPIO_vSetAlternateFunction(GPIO_PortNum	Copy_u8GPIOPortNum,GPIO_PinNum Copy_u8Pin,GPIO_AF	Copy_u8AF);
/*For Output */
/*===============   6-Function To Write Data At ODR	Value = HIGH , LOW  ===============*/
void GPIO_vWritePinValue(GPIO_PortNum	Copy_u8GPIOPortNum,GPIO_PinNum Copy_u8Pin,GPIO_State Copy_u8State);
/*===============   7-Function To Write Data At ODR	Value = 1 byte	    ===============*/
void GPIO_vWriteByte(GPIO_PortNum	Copy_u8GPIOPortNum,u16  Copy_u16Data);
/*===============   8-Function To clear the whole port				    ===============*/
void GPIO_vClearPort(GPIO_PortNum	Copy_u8GPIOPortNum);
/*For Input*/
/*===============   9-Function To Read Data From IDR  ===============*/
void GPIO_vGetPinValue(GPIO_PortNum	Copy_u8GPIOPortNum,GPIO_PinNum Copy_u8Pin,u8 *Copy_pu8ReadValue);
u8 MGPIO_u8ReadData(u8 Copy_u8PORT ,u8 Copy_u8PIN);
/*for Locking*/
/*===============   10-Function To Locked   ===============*/
void GPIO_vLockPin(GPIO_PortNum	Copy_u8GPIOPortNum,GPIO_PinNum Copy_u8Pin);

#endif /* MCAL_GPIO_GPIO_H_ */
