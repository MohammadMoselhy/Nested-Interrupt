/*
 * STD_macros.h
 *
 * Created: 9/17/2019 12:03:08 PM
 *  Author: Mohamed I.Moselhy
 */ 


#ifndef STD_MACROS_H_
#define STD_MACROS_H_
	
#define SET_BIT(reg,bit) reg|=(1<<bit) 
#define CLR_BIT(reg,bit) reg&=(~(1<<bit))
#define TOG_BIT(reg,bit) reg^=(1<<bit)
#define RED_BIT(reg,bit) ((reg&(1<<bit))>>bit)



#endif /* STD_MACROS_H_ */
