
/***********************************************************************************************************/
/***************************** Author : Mohamed diaa********************************************************/
/***************************** Layer : MCAL ****************************************************************/
/***************************** SWC : USART *******************************************************************/
/***************************** Version : 2.0 ***************************************************************/
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/GIE/GIE_INTERFACE.h"
#include "../HAL/LCD/LCD_INTERFACE.h"
#include "../MCAL/DIO/DIO_INTERFACE.h"
#include "../MCAL/USART/USART_INTERFACE.h"
#include "../MCAL/TIMER/TIMER_INTERFACE.h"
#include "../MCAL/ADC/ADC_INTERFACE.h"
#include <String.h>
#include <avr/delay.h>
static u16 ADC_LM35;
static u8 ADC_Motor;
u8 arr[8]={
		0b01100,
		0b10000,
		0b01100,
		0b00000,
		0b00000,
		0b00000,
		0b00000,
		0b00000,
};

int main(void)
{
	//Enable glable Interupts
	//GIE_voidEnable();
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
	//Timer2_init();											//timer2 init
	//TIMER2_SetCallBack(&action);							//timer2 callback
	ADC_LM35=0;
	ADC_Motor=0;
	u8 USAERT_chice='0';
	u8 access=0, counter=0,id=0;

	u8 * z=NULL;
	u8* pass=NULL;
	while((pass==NULL))
	{

		USART_SendString("Enter your name: ");
		z=USART_ReciveString();
		if((strcmp(z,"mohmaed")==0)||(strcmp(z,"mohmaed"+0x08)==0)){id=1;}
		else if((strcmp(z,"ahmed")==0)||(strcmp(z,"ahmed"+0x08)==0)){id=3;}
		else{
			LCD_GoToXY(0,0);
			LCD_WriteString("try agine");
		}
		while((access==0)&&(id!=0))
		{
			USART_SendString("Enter your pass: ");
			pass=USART_ReciveString();
			if(((strcmp(pass,"1111")==0)||(strcmp(pass,"1111"+0x08)==0))&&(id==1)){
				access++;
				LCD_GoToXY(0,0);
				LCD_WriteString("welcome back");
				LCD_GoToXY(1,0);
				LCD_WriteString("mohamed");
			}

			else if(((strcmp(pass,"3333")==0)||(strcmp(pass,"3333"+0x08)==0))&&(id==3)){
				access++;
				LCD_GoToXY(0,0);
				LCD_WriteString("welcome back");
				LCD_GoToXY(1,0);
				LCD_WriteString("ahmed");

			}
			else
			{

				USART_SendString("try agine!!");
				USART_voidSend(0x0D);
				counter++;
				pass=NULL;
				access=0;
				if(counter==3){id=0;}
			}
		}
	}
	_delay_ms(2000);

	while(1)
	{
		ADC_LM35=ADC_Read(0);
		ADC_Motor=ADC_Read(1);
		LCD_WriteCommand(lcd_clr);
		LCD_WriteString("Degres: ");
		LCD_voidDisplayIntegar(ADC_Motor*0.4868);
		LCD_voidDisplaySpecialChar(arr,0x01,0,10);
		if((ADC_LM35<=456))
		{
			DIO_SetPinValue(DIO_PORTA,DIO_PIN5,DIO_HIGH); //room3
			DIO_SetPinValue(DIO_PORTA,DIO_PIN6,DIO_HIGH); //room2
			DIO_SetPinValue(DIO_PORTA,DIO_PIN7,DIO_HIGH); //room1
		}
		else if((ADC_LM35<=519)&&(ADC_LM35>456))
		{
			DIO_SetPinValue(DIO_PORTA,DIO_PIN5,DIO_HIGH); //room3
			DIO_SetPinValue(DIO_PORTA,DIO_PIN6,DIO_HIGH); //room2
			DIO_SetPinValue(DIO_PORTA,DIO_PIN7,DIO_LOW); //room1
		}
		else if((ADC_LM35<=567)&&(ADC_LM35>519))
		{
			DIO_SetPinValue(DIO_PORTA,DIO_PIN5,DIO_HIGH); //room3
			DIO_SetPinValue(DIO_PORTA,DIO_PIN6,DIO_LOW); //room2
			DIO_SetPinValue(DIO_PORTA,DIO_PIN7,DIO_LOW); //room1
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

		switch(USAERT_chice)
		{
		case '0':
			USART_SendString("options: ");
			USART_voidSend(0x0D);
			USART_SendString("-close door: 1 ");
			USART_voidSend(0x0D);
			USART_SendString("-refresh data: 3 ");
			USART_voidSend(0x0D);
			Timer1_SetChannelACompaermach(2000);
			break;
		case '1':
			USART_SendString("options: ");
			USART_voidSend(0x0D);
			USART_SendString("-open door: 0 ");
			USART_voidSend(0x0D);
			USART_SendString("-refresh data: 3 ");
			USART_voidSend(0x0D);
			Timer1_SetChannelACompaermach(999);
			break;
		case '3':
			USART_SendString("options: ");
			USART_voidSend(0x0D);
			USART_SendString("-open door: 0 ");
			USART_voidSend(0x0D);
			USART_SendString("-refresh data: 3 ");
			USART_voidSend(0x0D);
			break;
		default:
			USART_SendString("not valid option");
			USART_voidSend(0x0D);
			break;
		}
		USART_SendString("Enter your option:");
		USAERT_chice=USART_u8Read();
		while(USART_u8Read()!=0x0D);


	}

	return 0;
}





