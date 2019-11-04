/*
 * Header.h
 *
 * Created: 9/24/2019 8:42:55 PM
 *  Author: Mohamed I.Moselhy
 */ 


#ifndef HEADER_H_
#define HEADER_H_

DIO_write (char port , char pin , char val);

DIO_setDirection(char port , char pin , char dir);

char DIO_read(char port , char pin);

DIO_toggle (char port , char pin);

DIO_setPortDirection(char port  , char dir);

DIO_writePortDirection (char port ,char val);

DIO_togglePortDirection (char port);

char DIO_readPortDirection (char port);

DIO_pullupStatus (char port , char pin , char connectPullup);

DIO_writeLowNibble(char port ,char value);

DIO_writeHighNibble(char port ,char value);
#endif /* HEADER_H_ */
