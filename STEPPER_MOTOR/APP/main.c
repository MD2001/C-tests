#include "../HAL/Steper/STEPER_INTERFACE.h"
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../HAL/LCD/LCD_INTERFACE.h"
#include "../MCAL/DIO/DIO_INTERFACE.h"
#include <avr/delay.h>


int main(void)
{

	STEPER_voidInit();


	while(1)
	{

	STEPER_voidFullStep(1500); //delay for speed of motor


	}
	return 0;
}
