/***********************************************************************************************************/
/***************************** Author : Mohamed diaa********************************************************/
/***************************** Layer : APP ****************************************************************/
/***************************** SWC : main *****************************************************************/
/***************************** Version : 5.03.6 ***************************************************************/

#include "../MCAL/DIO/DIO_INTERFACE.h"
#include "../MCAL/TIMER/TIMER_INTERFACE.h"
#include "../MCAL/TIMER/TIMER_PRIVET.h"
#include "../HAL/LCD/LCD_INTERFACE.h"
#include "../MCAL/UART/USART_interface.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/GIE/GIE_INTERFACE.h"
#include "../RTOS_DRIVER/RTOS_interface.h"
#include "../MCAL/DIO/DIO_PRIVATE.h"

void LED1();
void LED2();
void LED3();

int main(void)
{
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN1,DIO_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN2,DIO_OUTPUT);

		RTOS_voidCreateTask(500,0,&LED1);
		RTOS_voidCreateTask(200,1,&LED2);
		RTOS_voidCreateTask(300,2,&LED3);

		RTOS_voidStartRTOS();
	while(1){


	}

}


void LED1()
{
	TOG_BIT(PORTA_REG,DIO_PIN0);
}
void LED2()
{
	TOG_BIT(PORTA_REG,DIO_PIN1);
}
void LED3()
{
	TOG_BIT(PORTA_REG,DIO_PIN2);
}


