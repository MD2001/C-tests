
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
#include "../MCAL/ADC/ADC_INTERFACE.h"
#include <String.h>
#include <avr/delay.h>
int main(void)
{
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN0,DIO_INPUT);		//RXD pin
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN1,DIO_OUTPUT);		//TXD pin
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN5,DIO_OUTPUT);		//OCA1 pin
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN5,DIO_OUTPUT);		//room3
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN6,DIO_OUTPUT);		//room2
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN7,DIO_OUTPUT);		//room1
	DIO_SetPinValue(DIO_PORTA,DIO_PIN5,DIO_LOW);			//room3 value
	DIO_SetPinValue(DIO_PORTA,DIO_PIN6,DIO_LOW); 			//room2	value
	DIO_SetPinValue(DIO_PORTA,DIO_PIN7,DIO_LOW); 			//room1 value
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN0,DIO_INPUT);		//LDR pin
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN1,DIO_INPUT);		//LM35 pin
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN3,DIO_OUTPUT);		//Motot pin
	Timer_init();											// timer0 init
	ADC_Init();												//ADC init
	LCD_Init();												//LCD init
	USART_voidInit();										//UART init
	Timer1_init();											//timer1 init
	Timer1_SetICR(20000);									//timner 1 top value 20000
	Timer1_SetChannelACompaermach(2000);					//timer 1 compare mach value 2000
	TIMER_SetOCR0TO(200);

	u16 ADC_LM35=0;
	u8 ADC_Motor=0,access=0, counter=1,id=0;

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
				USART_voidSend(0x0D);
				counter++;
			}
		}
	}

	USART_SendString("options: ");
	USART_voidSend(0x0D);
	USART_SendString("4-open door");
	Timer1_SetChannelACompaermach(750);

	while(1)
	{
		ADC_LM35=ADC_Read(0);
		ADC_Motor=ADC_Read(1);
		LCD_WriteCommand(lcd_clr);
		LCD_WriteString("Bright: ");
		LCD_voidDisplayIntegar(ADC_LM35);
		LCD_GoToXY(1,0);
		LCD_WriteString("Degres: ");
		LCD_voidDisplayIntegar(ADC_Motor);
		_delay_ms(2000);
		if((ADC_LM35<=607)&&(ADC_LM35>100))
		{
			DIO_SetPinValue(DIO_PORTA,DIO_PIN5,DIO_HIGH); //room3
			DIO_SetPinValue(DIO_PORTA,DIO_PIN6,DIO_LOW); //room2
			DIO_SetPinValue(DIO_PORTA,DIO_PIN7,DIO_LOW); //room1
		}
		else if((ADC_LM35<=666)&&(ADC_LM35>607))
		{
			DIO_SetPinValue(DIO_PORTA,DIO_PIN5,DIO_HIGH); //room3
			DIO_SetPinValue(DIO_PORTA,DIO_PIN6,DIO_HIGH); //room2
			DIO_SetPinValue(DIO_PORTA,DIO_PIN7,DIO_LOW); //room1
		}
		else if((ADC_LM35<=709)&&(ADC_LM35>666))
		{
			DIO_SetPinValue(DIO_PORTA,DIO_PIN5,DIO_HIGH); //room3
			DIO_SetPinValue(DIO_PORTA,DIO_PIN6,DIO_HIGH); //room2
			DIO_SetPinValue(DIO_PORTA,DIO_PIN7,DIO_HIGH); //room1a
		}
		else
		{
			DIO_SetPinValue(DIO_PORTA,DIO_PIN5,DIO_LOW); //room3
			DIO_SetPinValue(DIO_PORTA,DIO_PIN6,DIO_LOW); //room2
			DIO_SetPinValue(DIO_PORTA,DIO_PIN7,DIO_LOW); //room1
		}



		if((ADC_Motor<=100)&&(ADC_Motor>0))
			{
			TIMER_SetOCR0TO(50);
			}
			else if((ADC_Motor<=200)&&(ADC_Motor>100))
			{
				TIMER_SetOCR0TO(100);
			}
			else if((ADC_Motor<=305)&&(ADC_Motor>200))
			{
				TIMER_SetOCR0TO(200);
			}
			else
			{
				TIMER_SetOCR0TO(250);
			}


	}

	return 0;
}
