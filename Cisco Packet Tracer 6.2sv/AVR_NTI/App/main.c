/*
 * main.c
 *
 *  Created on: 07/06/2022
 *      Author: Mostafa Akhlak Mohamed
 */

/*********************************_SELECT_F_CPU_************************************************************/
#define F_CPU					16000000UL
/********************************_INCLUDES_*****************************************************************/
#include"Led.h"
#include"Buzzer.h"
#include<util/delay.h>


int main()
{
	H_Buzzer_Void_BuzzerInit();
	H_Buzzer_Void_BuzzerTriple();
	return 0;
}
