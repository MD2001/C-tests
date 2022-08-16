#include "avr/delay.h"

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_INTERFACE.h"

#include "LCD_PRIVET.h"
#include "LCD_INTERFACE.h"



void LCD_Init(void)
{
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN1,DIO_OUTPUT);
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN2,DIO_OUTPUT);

	DIO_SetPortDirection(DIO_PORTA,0xFF);
	_delay_ms(100);
	//LCD_WriteCommand(0x38);

	LCD_WriteCommand(0x38);
	LCD_WriteCommand(0x0C);

	LCD_WriteCommand(0x01);	
	LCD_WriteCommand(0x06);
}

void LCD_WriteCommand(u8 Command)
{
	/* Rs = 0*/
	DIO_SetPinValue(DIO_PORTB,DIO_PIN1,DIO_LOW);
	/* Rw = 0*/

	DIO_SetPortValue(DIO_PORTA,Command);
	/*Set Enable */
	DIO_SetPinValue(DIO_PORTB,DIO_PIN2,DIO_HIGH); //EN
	_delay_ms(1);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN2,DIO_LOW);
	_delay_ms(5);
}
void LCD_WriteData(u8 Data)
{
	/* Rs = 0*/
	DIO_SetPinValue(DIO_PORTB,DIO_PIN1,DIO_HIGH);
	/* Rw = 0*/

	DIO_SetPortValue(DIO_PORTA,Data);
	/*Set Enable */
	DIO_SetPinValue(DIO_PORTB,DIO_PIN2,DIO_HIGH); //EN
	_delay_ms(1);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN2,DIO_LOW);
	_delay_ms(5);
}




void LCD_WriteString(char *Ptr)
{
	u8 i = 0;
	while(Ptr[i] != '\0')
	{
		LCD_WriteData(Ptr[i]);
		i++;
	}
}




void LCD_GoToXY(u8 X_Pos , u8 Y_Pos)
{
	u8 Local_Adress;

	if (X_Pos==0)
	{
		Local_Adress=Y_Pos;

	}

	else if (X_Pos==1)
	{
		Local_Adress = Y_Pos+ 0x40 ;
	}

	/* set the calculated address into DDRAM */
	LCD_WriteCommand(Local_Adress+128);


}



