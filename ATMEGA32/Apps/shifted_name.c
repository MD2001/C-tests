#include "../MCAL/DIO/DIO_INTERFACE.h"
#include "../HAL/LCD/LCD_INTERFACE.h"
#include "avr/delay.h"


int main(void)
{

	LCD_Init();
	u8 r_iteration,l_iteration;
	while(1)
	{
		for(r_iteration=0;r_iteration<9;r_iteration++)
			{
				LCD_SendCommand(0x01);
				_delay_ms(2);
				LCD_GoToXY(0,r_iteration);
				LCD_WriteString("Mohamed");
				_delay_ms(500);
			}
		for( l_iteration=r_iteration;l_iteration>0;l_iteration--)
			{
				LCD_SendCommand(0x01);
				_delay_ms(2);
				LCD_GoToXY(0,l_iteration);
				LCD_WriteString("Mohamed");
				_delay_ms(500);
			}
 
	}

	return 0;
}


