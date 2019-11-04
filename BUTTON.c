/*
 * BUTTON.c
 *
 * Created: 10/1/2019 9:29:11 PM
 *  Author: Lenovo
 */ 

#include "DIO_Header.h"

void BUT_init(char port , char pin)
{
	DIO_setDirection(port , pin , 0);
}

char BUT_read(char port , char pin)
{
	return DIO_read(port , pin);
}
