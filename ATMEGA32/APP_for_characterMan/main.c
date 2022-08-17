#include "../MCAL/DIO/DIO_INTERFACE.h"
#include "../HAL/LCD/LCD_INTERFACE.h"
#include "../HAL/Key Pad/KPD_INTERFACE.h"
#include "../HAL/Key Pad/KPD_CONFIG.h"
#include "../HAL/Key Pad/KPD_PRIVETE.h"
#include "../HAL/Steper/STEPER_INTERFACE.h"
#include <avr/delay.h>


int main(void)
{
	u8 arr[8]={
			0b11100,
			0b01100,
			0b01110,
			0b10101,
			0b01010,
			0b10001,
			0b10001,
	};


	LCD_Init();
	LCD_voidDisplaySpecialChar(arr,0x01,0,0);

	while(1)
	{


	}

	return 0;
}


