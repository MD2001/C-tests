#include "../MCAL/DIO/DIO_INTERFACE.h"
#include "../MCAL/TIMER/TIMER_INTERFACE.h"
#include "../MCAL/TIMER/TIMER_PRIVET.h"
#include "../HAL/LCD/LCD_INTERFACE.h"
#include "../MCAL/UART/USART_interface.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/GIE/GIE_INTERFACE.h"
#include <avr/delay.h>


u8 array_ROCK[]={
		0b00100,
		0b01110,
		0b11111,
		0b11111,
		0b11111,
		0b01110,
		0b00100,
		0b00000,
};

u8 array_PAPER[]={
		0b11111,
		0b11111,
		0b11111,
		0b11111,
		0b11111,
		0b11111,
		0b11111,
		0b11111,
};

u8 array_SCISSORS[]={
		0b01010,
		0b10101,
		0b01010,
		0b00100,
		0b01100,
		0b11011,
		0b10001,
		0b10001,


};

int main(void)
{
	USART_Init();
	LCD_Init();

	DIO_SetPinDirection(DIO_PORTD,DIO_PIN0,DIO_INPUT);
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN1,DIO_OUTPUT);

	USART_SendString("Enter to run {R or  S or P} : "); //send string in
	u8 x=0;
	u8 one=0,two=0;
	while(1)
	{
		x=USART_u8Receive();
		switch(x)
		{
		case 'R':LCD_voidDisplaySpecialChar(array_ROCK,0x02,0,0); one ='R'; break;
		case 'P':LCD_voidDisplaySpecialChar(array_PAPER,0x03,0,0);one ='P'; break;
		case 'S':LCD_voidDisplaySpecialChar(array_SCISSORS,0x04,0,0);one ='S'; break;
		default : USART_SendString("\n***** Wrong try agine ****");
		}
		x=USART_u8Receive();
		LCD_GoToXY(0,1);
		LCD_WriteString(" vs ");
		switch(x)
		{
		case 'R':LCD_voidDisplaySpecialChar(array_ROCK,0x02,0,5);two = 'R'; break;
		case 'P':LCD_voidDisplaySpecialChar(array_PAPER,0x03,0,5);two = 'p'; break;
		case 'S':LCD_voidDisplaySpecialChar(array_SCISSORS,0x04,0,5);two = 'S'; break;
		default : USART_SendString("\n***** Wrong try agine ****");
		}

		if(two == one )
		{
			LCD_GoToXY(1,0);
			LCD_WriteString("Draw");
		}
		else if((two=='P'&&one=='R')||(two=='R'&&one=='p'))
		{
			LCD_GoToXY(1,0);
			LCD_WriteString("P is winner");

		}
		else if((two=='P'&&one=='S')||(two=='S'&&one=='p'))
		{
			LCD_GoToXY(1,0);
			LCD_WriteString("S is winner");

		}
		else if((two=='S'&&one=='R')||(two=='S'&&one=='p'))
		{
			LCD_GoToXY(1,0);
			LCD_WriteString("R is winner");

		}


		_delay_ms(1500);
		LCD_WriteCommand(lcd_clr);
		x=0;
		one=0;
		two=0;

	}




	return 0;
}
