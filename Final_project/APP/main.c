
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
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN5,DIO_OUTPUT);		//room3
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN6,DIO_OUTPUT);		//room2
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN7,DIO_OUTPUT);		//room1
	LCD_Init();
	USART_voidInit();
	Timer1_init();
	Timer1_SetICR(20000);
	Timer1_SetChannelACompaermach(2500);

	u8 access=0, counter=1,id=0;

	u8 * z=NULL;
	u8* pass=NULL;
	while((id==0)&&(pass==NULL))
	{
		USART_SendString("Enter your name: ");
		z=USART_ReciveString();
		if((strcmp(z,"mohmaed")==0)||(strcmp(z,"mohmaed"+0x08)==0)){id=1;}
		else if((strcmp(z,"omar")==0)||(strcmp(z,"omar"+0x08)==0)){id=2;}
		else if((strcmp(z,"ahmed")==0)||(strcmp(z,"ahmed"+0x08)==0)){id=3;}
		else{
			LCD_GoToXY(0,0);
			LCD_WriteString("try agine");
			_delay_ms(500);
		}
		while((counter!=3) &&(access==0))
		{
			USART_SendString("Enter your pass: ");
			pass=USART_ReciveString();
			if(((strcmp(pass,"1111")==0)||(strcmp(pass,"1111"+0x08)==0))&&(id==1)){
				access++;
				counter=3;
				LCD_WriteString("welcome back");
				LCD_GoToXY(1,0);
				LCD_WriteString("mohamed");
			}
			else if(((strcmp(pass,"2222")==0)||(strcmp(pass,"2222"+0x08)==0))&&(id==2)){
				access++;
				counter=3;
				LCD_WriteString("welcome back");
				LCD_GoToXY(1,0);
				LCD_WriteString("omar");
			}
			else if(((strcmp(pass,"3333")==0)||(strcmp(pass,"3333"+0x08)==0))&&(id==3)){
				access++;
				counter=3;
				LCD_WriteString("welcome back");
				LCD_GoToXY(1,0);
				LCD_WriteString("ahmed");
			}
			else
			{

				USART_SendString("try agine: ");

				counter++;
			}
		}
	}

	USART_SendString("options: ");
	USART_voidSend(0x0D);		// press Enter
	USART_SendString("1-light room1" );
	USART_voidSend(0x0D);
	USART_SendString("2-light room2");
	USART_voidSend(0x0D);
	USART_SendString("3-light room3");
	USART_voidSend(0x0D);
	USART_SendString("4-open door");
	Timer1_SetChannelACompaermach(750);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN5,DIO_HIGH); //room3
	DIO_SetPinValue(DIO_PORTB,DIO_PIN6,DIO_HIGH); //room2
	DIO_SetPinValue(DIO_PORTB,DIO_PIN7,DIO_HIGH); //room1
	while(1)
	{

	}

	return 0;
}
