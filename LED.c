/*
 * LED.c
 *
 * Created: 10/1/2019 9:24:46 PM
 *  Author: Lenovo
 */ 

#include "DIO_Header.h"
void LED_init(char port , char pin)
{
	DIO_setDirection(port , pin ,1);
}

void LED_on(char port , char pin)
{
	DIO_write(port , pin ,1);
}

void LED_off(char port , char pin)
{
	DIO_write(port , pin ,0);
}

void LED_toggle(char port , char pin)
{
	DIO_toggle(port , pin );
}

char LED_readStatus(char port , char pin)
{
	return DIO_read(port , pin);
}
