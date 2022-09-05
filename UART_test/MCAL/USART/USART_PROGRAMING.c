/***********************************************************************************************************/
/***************************** Author : Mohamed diaa********************************************************/
/***************************** Layer : MCAL ****************************************************************/
/***************************** SWC : USART *******************************************************************/
/***************************** Version : 2.0 ***************************************************************/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "USART_CONFIG.h"
#include "USART_INTERFACE.h"
#include "USART_RIGSTER.h"
#include "USART_PRIVET.h"

void USART_voidInit(void)
{
	/*set BUAD rate*/
	CLR_BIT(UCSRA,UCSRA_U2X);
	UBRRL=51;

	u8 Local_u8Value=0;
	/*Using UCSRC register*/
	SET_BIT(Local_u8Value,UCSRC_URSEL);

	//*Asynchronous*/
	CLR_BIT(Local_u8Value,UCSRC_UMSEL);
	/*no parity*/
	CLR_BIT(Local_u8Value,UCSRC_UPM1);
	CLR_BIT(Local_u8Value,UCSRC_UPM0);


	/**one stop bit*/
	CLR_BIT(Local_u8Value,UCSRC_USBS);

	/*on char size 8-bit mode*/
	SET_BIT(Local_u8Value,UCSRC_UCSZ1);
	SET_BIT(Local_u8Value,UCSRC_UCSZ0);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);

	UCSRC=Local_u8Value;

	SET_BIT(UCSRB,UCSRB_TXEN);    //transmitter enable
	SET_BIT(UCSRB,UCSRB_RXEN);    //receiver   enable

}



u8 USART_u8Read()
{
	while(GET_BIT(UCSRA,UCSRA_RXC)==0);
	return UDR;
}

void USART_voidSend(u8 Copy_data)
{
	while(GET_BIT(UCSRA,UCSRA_UDRE)==0);
	UDR=Copy_data;

}

void USART_SendString(u8* Copy_data)
{
	u8 i=0;
	while(Copy_data[i]!='\0')
	{
		USART_voidSend(Copy_data[i]);
		i++;
	}
}

u8* USART_ReciveString()
{
	static u8 string[50]={0};
	for(u8 i=0;i<50;i++){string[i]=0;}			//reset the arr

	u8 flag=0,i=0;										//counter
	u8 x=USART_u8Read();					//to chick if Enter is get first
	while(x !=0x0D)								//Enter hex represintaion
	{
		string[i]=x;
		x=USART_u8Read();
		i++;

		if(x==0x08)							//delete hex represintaion
		{
			i-=2;
			x=USART_u8Read();
			while(x==0x08)
			{
				i--;
				x=USART_u8Read();
				flag=1;
			}

		}
		if(flag==1){i++;}
	}

	for(;i<50;i++){string[i]=0;}
	return string;
}

