/*
 * Led_Header.h
 *
 * Created: 10/1/2019 9:28:00 PM
 *  Author: Lenovo
 */ 


#ifndef LED_HEADER_H_
#define LED_HEADER_H_

void LED_init(char port , char pin);
void LED_on(char port , char pin);
void LED_off(char port , char pin);
void LED_toggle(char port , char pin);
char LED_readStatus(char port , char pin);


#endif /* LED_HEADER_H_ */
