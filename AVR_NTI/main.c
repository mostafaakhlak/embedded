/*
 * main.c
 *
 *  Created on: 07/06/2022
 *      Author: Mostafa Akhlak Mohamed
 */


#include"Reg.h"
#include"std.h"
#include"BitMath.h"
#include"DIO/DIO.h"



int main()
{
	while(1)
	{
	PinMode(PC2,OUTPUT);
	PinWrite(PC2,HIGH);
	for(int i=0;i<100000;i++);
	PinWrite(PC2,LOW);
	PinMode(PC3,OUTPUT);
	PinWrite(PC3,HIGH);
	}
	return 0;
}
