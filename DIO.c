/*
 * Functions.c
 *
 * Created: 9/24/2019 8:41:11 PM
 *  Author: Mohamed I.Moselhy
 */

#include "Std_macros.h"
#include <avr/io.h>

DIO_setDirection(char port , char pin , char dir)
{
	switch (port)
	{
		case 'A':
		case 'a':
		if (dir == 1)
		{
			DDRA|=(1<<pin);
		}
		else
		{
			DDRA&=(~(1<<pin));
		}
		break;
		
		case 'B':
		case 'b':
		if (dir == 1)
		{
			DDRB|=(1<<pin);
		}
		else
		{
			DDRB&=(~(1<<pin));
		}
		break;
		
		case 'C':
		case 'c':
		if (dir == 1)
		{
			DDRC|=(1<<pin);
		}
		else
		{
			DDRC&=(~(1<<pin));
		}				
		break;
		
		case 'D':
		case 'd':
		if (dir == 1)
		{
			DDRD|=(1<<pin);
		}
		else
		{
			DDRD&=(~(1<<pin));
		}
		break;	
	}
}

DIO_write (char port , char pin , char val)
{
	switch (port)
	{
	case 'A':
	case 'a':
	if (val == 1)
	{
		PORTA|=(1<<pin);
	}
	else 
	{
		PORTA&=(~(1<<pin));
	}
	break; 

	case 'B':
	case 'b':
	if (val == 1)
	{
		PORTB|=(1<<pin);
	}
	else
	{
		PORTB&=(~(1<<pin));
	}
	
	break;	
	case 'C':
	case 'c':
	if (val == 1)
	{
		PORTC|=(1<<pin);
	}
	else
	{
		PORTC&=(~(1<<pin));
	}
	break;
	
	case 'D':
	case 'd':
	if (val == 1)
	{
		PORTD|=(1<<pin);
	}
	else
	{
		PORTD&=(~(1<<pin));
	}
	break;
	}
}

char DIO_read(char port , char pin)
{
	char x;
	switch (port)
	{
	case 'A':
	case 'a':
	{
		x=RED_BIT( PINA , pin );
	}
	break;
	
	case 'B':
	case 'b':
	{
		x=RED_BIT( PINB , pin );
	}
	break;

	case 'C':
	case 'c':
	{
		x=RED_BIT( PINC , pin );
	}
	break;

	case 'D':
	case 'd':
	{
		x=RED_BIT( PIND , pin );
	}
	break;
	
	}		
	return x;
}

DIO_toggle (char port , char pin)
{
	switch (port)
	{
		case 'A':
		case 'a':
			TOG_BIT(PORTA , pin);
		break;
		
		case 'B':
		case 'b':
		TOG_BIT(PORTB , pin);
		break;

		case 'C':
		case 'c':
		TOG_BIT(PORTC , pin);
		break;

		case 'D':
		case 'd':
		TOG_BIT(PORTD , pin);
		break;
			
	}
}

DIO_setPortDirection(char port  , char dir)
{
	switch (port)
	{
		case 'A':
		case 'a':
		{
			DDRA=dir;
		}
		break;
		
		case 'B':
		case 'b':
		{
			DDRB=dir;
		}
		break;
		
		case 'C':
		case 'c':
		{
			DDRC=dir;
		}
		break;
		
		case 'D':
		case 'd':
		{
			DDRD=dir;
		}
		break;
	}
}

DIO_writePortDirection (char port ,char val)
{
	switch(port)
	{
	case 'A' :
	case 'a' :
	{
		PORTA=val;
	}
	break;

	case 'B' :
	case 'b' :
	{
	PORTB=val;
	}	
	break;

	case 'C' :
	case 'c' :
	{
	PORTC=val;
	}	
	break;

	case 'D' :
	case 'd' :
	{
	PORTD=val;
	}	
	break;
	}		
}

DIO_togglePortDirection (char port)
{
	switch(port)
	{
		case 'A' :
		case 'a' :
		{
			PORTA=~PORTA;
		}
		break;

		case 'B' :
		case 'b' :
		{
			PORTB=~PORTB;
		}
		break;

		case 'C' :
		case 'c' :
		{
			PORTC=~PORTC;
		}
		break;

		case 'D' :
		case 'd' :
		{
			PORTD=~PORTD;
		}
		break;
	}
}

char DIO_readPortDirection (char port)
{
	char x;
	switch(port)
	{
		case 'A' :
		case 'a' :
		{
			x=PORTA;
		}
		break;

		case 'B' :
		case 'b' :
		{
			x=PORTB;
		}
		break;

		case 'C' :
		case 'c' :
		{
			x=PORTC;
		}
		break;

		case 'D' :
		case 'd' :
		{
			x=PORTD;
		}
		break;
	}
	return x;
}

DIO_pullupStatus (char port , char pin , char connectPullup)
{
	switch (port)
	{
		case 'A':
		case 'a':
		if (connectPullup==1)
		{
			SET_BIT(PORTA , pin);
		}
		else
		{
			CLR_BIT(PORTA , pin);
		}

		case 'B':
		case 'b':
		if (connectPullup==1)
		{
			SET_BIT(PORTB , pin);
		}
		else
		{
			CLR_BIT(PORTB , pin);
		}
		
		case 'C':
		case 'c':
		if (connectPullup==1)
		{
			SET_BIT(PORTC , pin);
		}
		else
		{
			CLR_BIT(PORTC , pin);
		}
		
		case 'D':
		case 'd':
		if (connectPullup==1)
		{
			SET_BIT(PORTD , pin);
		}
		else
		{
			CLR_BIT(PORTD , pin);
		}
	}
}

DIO_writeLowNibble(char port ,char value)
{
	value&=0x0f;
	
	switch(port)
	{
	case'A':
	case'a':
	PORTA&=0xf0;
	PORTA|=value;
	break;
	
	case'B':
	case'b':
	PORTB&=0xf0;
	PORTB|=value;
	break;
	
	case'C':
	case'c':
	PORTC&=0xf0;
	PORTC|=value;
	break;		
	
	case'D':
	case'd':
	PORTD&=0xf0;
	PORTD|=value;
	break;	
	}	
}

DIO_writeHighNibble(char port ,char value)
{
	value<<=4;
	
	switch(port)
	{
		case'A':
		case'a':
		PORTA&=0x0f;
		PORTA|=value;
		break;
		
		case'B':
		case'b':
		PORTB&=0x0f;
		PORTB|=value;
		break;
		
		case'C':
		case'c':
		PORTC&=0x0f;
		PORTC|=value;
		break;
		
		case'D':
		case'd':
		PORTD&=0x0f;
		PORTD|=value;
		break;
	}
}