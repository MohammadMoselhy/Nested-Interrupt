/*
 * SevenSegment.c
 *
 * Created: 19-Oct-19 6:44:54 PM
 *  Author: Lenovo
 */ 


void sevenSegmentInit(char port)
{
	DIO_setPortDirection(port , 0xff);
}

void sevenSegmentWrite (char port , char number)
{
	unsigned char arr[]={ 0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x47,0x7f,0x6f};
	DIO_writePortDirection(port , arr[number]);
}

void bcdToSevenSegmentInit(char port , char startPin)
{
	DIO_setDirection(port , 0 , 1);
	DIO_setDirection(port , 1 , 1);
	DIO_setDirection(port , 2 , 1);
	DIO_setDirection(port , 3 , 1);
}

void bcdToSevenSegmentWriteLow (char port , char number)
{
	DIO_writeLowNibble(port , number);
}

void bcdToSevenSegmentWriteHigh (char port , char number)
{
	DIO_writeHighNibble(port , number);
}