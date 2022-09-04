#include "../MCAL/USART/USART_INTERFACE.h"

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../HAL/LCD/LCD_INTERFACE.h"
#include "../MCAL/DIO/DIO_INTERFACE.h"
#include <avr/delay.h>
int main(void)
{
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN0,DIO_INPUT);		//RXD pin
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN1,DIO_OUTPUT);		//TXD pin
	LCD_Init();
	USART_voidInit();

	LCD_WriteData('5');
	_delay_ms(500);
	LCD_GoToXY(0,0);
	LCD_WriteData('4');
	_delay_ms(500);
	LCD_GoToXY(0,0);
	LCD_WriteData('3');
	_delay_ms(500);
	LCD_GoToXY(0,0);
	LCD_WriteData('2');
	_delay_ms(500);
	LCD_GoToXY(0,0);
	LCD_WriteData('1');
	_delay_ms(500);
	LCD_GoToXY(0,0);
	LCD_WriteData('0');
	_delay_ms(500);
	LCD_WriteCommand(lcd_clr);
	u8 x='0';
	x=USART_u8Read();

	while(1)
	{
		x=USART_u8Read();
		LCD_GoToXY(0,0);
		LCD_WriteData(x);

	}
	return 0;
}
