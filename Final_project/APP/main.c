
/***********************************************************************************************************/
/***************************** Author : Mohamed diaa********************************************************/
/***************************** Layer : MCAL ****************************************************************/
/***************************** SWC : USART *******************************************************************/
/***************************** Version : 2.0 ***************************************************************/
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../HAL/LCD/LCD_INTERFACE.h"
#include "../MCAL/DIO/DIO_INTERFACE.h"
#include "../MCAL/USART/USART_INTERFACE.h"
#include "../MCAL/TIMER/TIMER_INTERFACE.h"
#include <String.h>
#include <avr/delay.h>
int main(void)
{
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN0,DIO_INPUT);		//RXD pin
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN1,DIO_OUTPUT);		//TXD pin
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN5,DIO_OUTPUT);		//OCA1 pin
	LCD_Init();
	USART_voidInit();
	u8 id=0;

	u8 * z=NULL;
	while(id==0)
	{
		USART_SendString("Enter your name: ");
		z=USART_ReciveString();
		if((strcmp(z,"mohmaed")==0)||(strcmp(z,"mohmaed"+0x08)==0)){id=1;}
		else if((strcmp(z,"omar")==0)||(strcmp(z,"omar"+0x08)==0)){id=2; }
		else if((strcmp(z,"ahmed")==0)||(strcmp(z,"ahmed"+0x08)==0)){id=3; }
		else{
			LCD_GoToXY(0,0);
			LCD_WriteString("try agine");
			_delay_ms(500);
		}
	}

	LCD_WriteCommand(lcd_clr);
	LCD_voidDisplayIntegar(id);

	while(1)
	{

	}

	return 0;
}
