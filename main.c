/*
 * main.c
 *
 * Created: 04-Nov-19 4:58:47 PM
 *  Author: Lenovo
 */ 


#include "PROTOTYPE.h"

volatile unsigned char i,x,y,z;

int main(void)
{
	sevenSegmentInit('A');
	
	sei();
	MCUCR |= (1<<ISC01)|(1<<ISC00);
	MCUCR |= (1<<ISC11)|(1<<ISC10);
	MCUCSR |= (1<<ISC2);
	
	GICR|=(1<<INT0)|(1<<INT1)|(1<<INT2);  
	
	BUT_init('B',2);
	BUT_init('D',2);
	BUT_init('D',3);
	
	LED_init('B',0);
	LED_init('B',1);
	LED_init('B',3);
	
    while(1)
    {
		for (i=0;i<=9;i++)
		{
			sevenSegmentWrite('A',i);
			_delay_ms(1000);
		}			   
    }
}

ISR(INT0_vect)
{
	for (x=0;x<10;x++)
	{
		LED_on('B',0);
		_delay_ms(250);
		LED_off('B',0);
		_delay_ms(250);	
	}
}
ISR(INT1_vect)
{
	sei();
	GICR|=(1<<INT0);  
	for (y=0;y<10;y++)
	{
		LED_on('B',1);
		_delay_ms(250);
		LED_off('B',1);
		_delay_ms(250);
	}	
}
ISR(INT2_vect)
{
	sei();
	GICR|=(1<<INT0)|(1<<INT1);  
	for (z=0;z<10;z++)
	{
		LED_on('B',3);
		_delay_ms(250);
		LED_off('B',3);
		_delay_ms(250);
	}	
}