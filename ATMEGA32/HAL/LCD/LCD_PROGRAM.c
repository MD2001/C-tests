/***********************************************************************************************************/
/***************************** Author : Mohamed diaa********************************************************/
/***************************** Layer : HAL *****************************************************************/
/***************************** SWC : LCD *******************************************************************/
/***************************** Version : 1.2 ***************************************************************/
#include "avr/delay.h"

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_INTERFACE.h"

#include "LCD_PRIVET.h"
#include "LCD_INTERFACE.h"



void LCD_Init(void)
{
	DIO_SetPinDirection(RS,DIO_OUTPUT); //RS
	DIO_SetPinDirection(EN,DIO_OUTPUT); //EN

	DIO_SetPortDirection(LCD_PORT,0xFF);
	_delay_ms(100);

	LCD_WriteCommand(0x38);
	_delay_ms(1);
	LCD_WriteCommand(0x0C);
	_delay_ms(1);
	LCD_WriteCommand(0x01);
	_delay_ms(2);
	LCD_WriteCommand(0x06);
}

void LCD_WriteCommand(u8 Command)
{
	/* Rs = 0*/
	DIO_SetPinValue(RS,DIO_LOW);
	/* Rw = 0*/

	DIO_SetPortValue(LCD_PORT,Command);
	/*Set Enable */
	DIO_SetPinValue(EN,DIO_HIGH); //EN
	_delay_ms(1);
	DIO_SetPinValue(EN,DIO_LOW);
	_delay_ms(5);
}
void LCD_WriteData(u8 Data)
{
	/* Rs = 0*/
	DIO_SetPinValue(RS,DIO_HIGH);
	/* Rw = 0*/

	DIO_SetPortValue(LCD_PORT,Data);
	/*Set Enable */
	DIO_SetPinValue(EN,DIO_HIGH); //EN
	_delay_ms(1);
	DIO_SetPinValue(EN,DIO_LOW);
	_delay_ms(5);
}




void LCD_WriteString(char *Ptr)
{
	u8 i = 0;
	while(Ptr[i] != '\0')
	{
		LCD_WriteData(Ptr[i]);
		i++;
	}
}




void LCD_GoToXY(u8 X_Pos , u8 Y_Pos)
{
	u8 Local_Adress;

	if (X_Pos==0)
	{
		Local_Adress=Y_Pos;

	}

	else if (X_Pos==1)
	{
		Local_Adress = Y_Pos+ 0x40 ;
	}

	/* set the calculated address into DDRAM */
	LCD_WriteCommand(Local_Adress+128);


}


void LCD_voidDisplayIntegar(u32 COPY_u32Number)
{
	u8 LOCAL_u8Num[10]={0};
	s16 i=0;
	u32 LOCAL_u32Remainder;
	if(COPY_u32Number==0)
	{
		LCD_WriteData('0');
	}

	if(COPY_u32Number>0)
	{
		while(COPY_u32Number!=0)
		{
			LOCAL_u32Remainder=COPY_u32Number%10;
			LOCAL_u8Num[i]=LOCAL_u32Remainder;
			COPY_u32Number=COPY_u32Number/10;
			i++;
		}
        i--;
		while(i>=0)
		{
			LCD_WriteData(LOCAL_u8Num[i]+48);
			i--;
		}
	}
}


void LCD_voidDisplaySpecialChar(u8* Ptr_u8PtrChar,u8 CGRam_index,u8 Copy_u8RowNum,u8 Copy_u8ColNum)
{
	LCD_GoToXY( Copy_u8RowNum, Copy_u8ColNum);
	LCD_WriteData(CGRam_index);
	u8 Local_u8address;
	u8 Local_u8Index;
	if (CGRam_index < 8)
	{
		Local_u8address= CGRam_index * 8;
		Local_u8address=SET_BIT(Local_u8address,6);
		LCD_WriteCommand(Local_u8address);
		for(Local_u8Index = 0;Local_u8Index < 8;Local_u8Index++)
		{
			LCD_WriteData(Ptr_u8PtrChar[Local_u8Index]);
		}
	}
	LCD_WriteCommand(0x02);

}



