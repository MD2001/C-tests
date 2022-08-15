/*
 * LCD_PROGARMMING.c
 *
 *  Created on: Aug 15, 2022
 *      Author: Original
 */

#include "STD_TYPES.h"
#include "DIO_INTERFACE.h"
#include "avr/delay.h"

void LCD_SendCommand(u8 command)
{
	DIO_SetPinValue(PORTB,PIN0,LOW); //RS
	DIO_SetPortValue(PORTA,command);
	DIO_SetPinValue(PORTB,PIN1,HIGH);
	_delay_ms(1);
	DIO_SetPinValue(PORTB,PIN1,LOW);
}
void LCD_SendData(u8 data)
{
	DIO_SetPinValue(PORTB,PIN0,HIGH); //RS
		DIO_SetPortValue(PORTA,data);
		DIO_SetPinValue(PORTB,PIN1,HIGH);
		_delay_ms(1);
		DIO_SetPinValue(PORTB,PIN1,LOW);
}
void LCD_Init(void){
	DIO_SetpinDirection(PORTB,PIN0,OUTPUT);
	DIO_SetpinDirection(PORTB,PIN1,OUTPUT);
	DIO_SetPortDirection(PORTA,0xFF);

	_delay_ms(100);

	LCD_SendCommand(0x38);
	_delay_ms(1);
	LCD_SendCommand(0x0C);
	_delay_ms(1);
	LCD_SendCommand(0x01);
	_delay_ms(2);


}


void LCD_WriteString(char *ptr)
{
	u8 i=0;
	while(ptr[i]!='\0')
	{
	LCD_SendData(ptr[i]);
	i++;
	}
}




