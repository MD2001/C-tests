#include "../MCAL/DIO/DIO_INTERFACE.h"
#include "../HAL/LCD/LCD_INTERFACE.h"
#include "../HAL/Key Pad/KPD_INTERFACE.h"
#include "../HAL/Key Pad/KPD_CONFIG.h"
#include "../HAL/Key Pad/KPD_PRIVETE.h"
#include "../HAL/Steper/STEPER_INTERFACE.h"
#include "../MCAL/EX_INTERUPT/EXTI_INTERFACE.h"
#include "../MCAL/GIE/GIE_INTERFACE.h"
#include <avr/delay.h>


int main(void)
{
	EXTI_voidInt0Init();
	GIE_voidEnable();

	DIO_SetPinDirection(DIO_PORTD,DIO_PIN2,DIO_INPUT);
	DIO_SetPinValue(DIO_PORTD,DIO_PIN2,DIO_HIGH);


	DIO_SetPinDirection(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);
	DIO_SetPinValue(DIO_PORTA,DIO_PIN0,DIO_LOW);

	while(1)
	{
		_delay_ms(2000);
		DIO_SetPinValue(DIO_PORTA,DIO_PIN0,DIO_LOW);
	}
	return 0;
}


void __vector_1 (void)__attribute__((signal));
void __vector_1 (void)
{
	DIO_SetPinValue(DIO_PORTA,DIO_PIN0,DIO_HIGH);
}
