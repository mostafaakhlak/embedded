/*
 * main.c
 *
 *  Created on: 07/06/2022
 *      Author: Mostafa Akhlak Mohamed
 */


#include"Reg.h"
#include"std.h"
#include"BitMath.h"



int main()
{
	SetBit(DDRC,1);	//to make PC2 as output
	SetBit(PORTC,1);	//to make PC2 as high
	SetBit(DDRC,0);	//to make PC2 as output
	SetBit(PORTC,0);	//to make PC2 as high
	SetBit(DDRC,2);	//to make PC2 as output
	SetBit(PORTC,2);	//to make PC2 as high
	return 0;
}
