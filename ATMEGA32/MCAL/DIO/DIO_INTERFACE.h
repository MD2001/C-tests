#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#include "DIO_PRIVET.h"
#include "../../LIB/STD_TYPES.h"
enum PORT
{
	PORTA=0,
	PORTB=1,
	PORTC=2,
	PORTD=3,
};

enum DIRECATION
{

	INPUT=0,
	OUTPUT=1
};

enum PIN
{
PIN0=0,
PIN1=1,
PIN2=2,
PIN3=3,
PIN4=4,
PIN5=5,
PIN6=6,
PIN7=7,
};

enum VALUE
{
LOW=0,
HIGH=1
};

void DIO_SetpinDirection(u8 Port, u8 Pin,u8 Direction);
void DIO_SetPinValue(u8 Port,u8 Pin,u8 Value);
u32 DIO_GetPinValue(u8 Port,u8 Pin);



#endif
