/***********************************************************************************************************/
/***************************** Author : Mohamed diaa********************************************************/
/***************************** Layer : HAL *****************************************************************/
/***************************** SWC : KPD *******************************************************************/
/***************************** Version : 1.0 ***************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_INTERFACE.h"
#include "KPD_PRIVETE.h"
#include "KPD_CONFIG.h"
#include "KPD_INTERFACE.h"


void KPD_Init()
{
			DIO_SetPinDirection(KPD_PORT,KPD_COULMN0_PIN,DIO_OUTPUT);
			DIO_SetPinDirection(KPD_PORT,KPD_COULMN1_PIN,DIO_OUTPUT);
			DIO_SetPinDirection(KPD_PORT,KPD_COULMN2_PIN,DIO_OUTPUT);
			DIO_SetPinDirection(KPD_PORT,KPD_COULMN3_PIN,DIO_OUTPUT);

			DIO_SetPinDirection(KPD_PORT,KPD_ROW0_PIN,DIO_INPUT);
			DIO_SetPinDirection(KPD_PORT,KPD_ROW1_PIN,DIO_INPUT);
			DIO_SetPinDirection(KPD_PORT,KPD_ROW2_PIN,DIO_INPUT);
			DIO_SetPinDirection(KPD_PORT,KPD_ROW3_PIN,DIO_INPUT);
			//DIO_SetPortValue(KPD_PORT,0b00001111);
			DIO_SetPortValue(KPD_PORT,0xff);
}

u8 KPD_u8GetPressedKye(void)
{

	/*Indication for the pressed key value*/
	u8 Local_u8PressedKey=KPD_NO_PRESSED_KEY;

	u8 Local_u8CoulmnArr[COULMN_NUM]={KPD_COULMN0_PIN,KPD_COULMN1_PIN,KPD_COULMN2_PIN,KPD_COULMN3_PIN};
	u8 Local_u8RowArr[COULMN_NUM]={KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};

	/*Array of values of key pad*/
	u8 Local_u8KPDArr[ROW_NUM][COULMN_NUM]= KPD_ARR_VAL;

	u8 Local_u8ColumnIndex,Local_u8RowIndex;

	for(Local_u8ColumnIndex=0;Local_u8ColumnIndex < COULMN_NUM; Local_u8ColumnIndex++)
	{

		DIO_SetPinValue(KPD_PORT,Local_u8CoulmnArr[Local_u8ColumnIndex],DIO_LOW);

		for(Local_u8RowIndex=0;Local_u8RowIndex<ROW_NUM;Local_u8RowIndex++)
		{
			if(DIO_GetPinValue(KPD_PORT,Local_u8RowArr[Local_u8RowIndex])==DIO_LOW)
			{
				Local_u8PressedKey=Local_u8KPDArr[Local_u8RowIndex][Local_u8ColumnIndex];
				while(DIO_GetPinValue(KPD_PORT,Local_u8RowArr[Local_u8RowIndex])==DIO_LOW)
				{
					Local_u8PressedKey=Local_u8KPDArr[Local_u8RowIndex][Local_u8ColumnIndex];
				}

				return Local_u8PressedKey;
			}
		}
		DIO_SetPinValue(KPD_PORT,Local_u8CoulmnArr[Local_u8ColumnIndex],DIO_HIGH);
	}
	return Local_u8PressedKey;
}
