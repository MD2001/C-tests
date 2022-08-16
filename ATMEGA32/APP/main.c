#include "../MCAL/DIO/DIO_INTERFACE.h"
#include "../HAL/LCD/LCD_INTERFACE.h"
#include "../HAL/Key Pad/KPD_INTERFACE.h"
#include "../HAL/Key Pad/KPD_CONFIG.h"
#include "../HAL/Key Pad/KPD_PRIVETE.h"
#include <avr/delay.h>

int main(void)
{
	KPD_Init();
	LCD_Init();

	u8	local_u8Key;


	while(1)
	{

		local_u8Key=KPD_u8GetPressedKye();

		while(local_u8Key==0xff)
		{
			local_u8Key=KPD_u8GetPressedKye();
		}
		if(local_u8Key==1)
		{
			LCD_WriteCommand(0x01);
		}
		else
		{
			LCD_WriteData(local_u8Key);
		}
	}

	return 0;
}


