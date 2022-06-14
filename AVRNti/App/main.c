/*
 * main.c
 *
 *  Created on: 07/06/2022
 *      Author: Mostafa Akhlak Mohamed
 */


#include"Relay.h"
#include"util/delay.h"


int main()
{
	H_Relay_Void_RelayInit(RELAY2);
	while(1)
	{
		H_Relay_Void_RelayOff(RELAY2);
		_delay_ms(500);
	}
	return 0;
}
