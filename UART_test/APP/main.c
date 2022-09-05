
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
#include <avr/delay.h>
int main(void)
{
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN0,DIO_INPUT);		//RXD pin
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN1,DIO_OUTPUT);		//TXD pin
	LCD_Init();
	USART_voidInit();


	USART_SendString("Enter your name: ");
	u8 * z=USART_ReciveString();
	LCD_WriteString(z);
	LCD_GoToXY(1,0);
	LCD_WriteString("DONE");

	while(1)
	{

	}

	return 0;
}
