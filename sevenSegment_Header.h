/*
 * sevenSegment_Header.h
 *
 * Created: 19-Oct-19 6:51:41 PM
 *  Author: Lenovo
 */ 


#ifndef SEVENSEGMENT_HEADER_H_
#define SEVENSEGMENT_HEADER_H_

void sevenSegmentInit(char port);
void sevenSegmentWrite (char port , char number);
void bcdToSevenSegmentInit(char port , char startPin);
void bcdToSevenSegmentWriteLow (char port , char number);
void bcdToSevenSegmentWriteHigh (char port , char number);

#endif /* SEVENSEGMENT_HEADER_H_ */