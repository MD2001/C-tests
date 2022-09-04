/***********************************************************************************************************/
/***************************** Author : Mohamed diaa********************************************************/
/***************************** Layer : HAL *****************************************************************/
/***************************** SWC : STERPER ***************************************************************/
/***************************** Version : 1.0 ***************************************************************/
#include "avr/delay.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_INTERFACE.h"
#include "STEPER_CONFIG.h"
#include "STEPER_INTERFACE.h"
#include "STEPER_PRIVET.h"



void STEPER_voidInit(void)
{

	DIO_SetPinDirection(BLUE_WIRE,DIO_OUTPUT);
	DIO_SetPinDirection(ORANGE_WIRE,DIO_OUTPUT);
	DIO_SetPinDirection(YELLOW_WIRE,DIO_OUTPUT);
	DIO_SetPinDirection(RED_WIRE,DIO_OUTPUT);

}
void STEPER_voidFullStep(u16 delay)
{

	DIO_SetPinValue(BLUE_WIRE,DIO_HIGH);
	DIO_SetPinValue(RED_WIRE,DIO_LOW);
	DIO_SetPinValue(YELLOW_WIRE,DIO_LOW);
	DIO_SetPinValue(ORANGE_WIRE,DIO_HIGH);
	_delay_ms(delay);
	DIO_SetPinValue(BLUE_WIRE,DIO_HIGH);
	DIO_SetPinValue(RED_WIRE,DIO_HIGH);
	DIO_SetPinValue(YELLOW_WIRE,DIO_LOW);
	DIO_SetPinValue(ORANGE_WIRE,DIO_LOW);
	_delay_ms(delay);
	DIO_SetPinValue(BLUE_WIRE,DIO_LOW);
	DIO_SetPinValue(RED_WIRE,DIO_HIGH);
	DIO_SetPinValue(YELLOW_WIRE,DIO_HIGH);
	DIO_SetPinValue(ORANGE_WIRE,DIO_LOW);
	_delay_ms(delay);
	DIO_SetPinValue(BLUE_WIRE,DIO_LOW);
	DIO_SetPinValue(RED_WIRE,DIO_LOW);
	DIO_SetPinValue(YELLOW_WIRE,DIO_HIGH);
	DIO_SetPinValue(ORANGE_WIRE,DIO_HIGH);
	_delay_ms(delay);
	DIO_SetPinValue(BLUE_WIRE,DIO_HIGH);
	DIO_SetPinValue(RED_WIRE,DIO_LOW);
	DIO_SetPinValue(YELLOW_WIRE,DIO_LOW);
	DIO_SetPinValue(ORANGE_WIRE,DIO_HIGH);
	_delay_ms(delay);
}

void STEPER_voidHalfStep(void)
{
	u16 delay=500;
	DIO_SetPinValue(BLUE_WIRE,DIO_HIGH);
	DIO_SetPinValue(RED_WIRE,DIO_LOW);
	DIO_SetPinValue(YELLOW_WIRE,DIO_LOW);
	DIO_SetPinValue(ORANGE_WIRE,DIO_HIGH);
	_delay_ms(delay);
	DIO_SetPinValue(BLUE_WIRE,DIO_HIGH);
	DIO_SetPinValue(RED_WIRE,DIO_LOW);
	DIO_SetPinValue(YELLOW_WIRE,DIO_LOW);
	DIO_SetPinValue(ORANGE_WIRE,DIO_LOW);
	_delay_ms(delay);
	DIO_SetPinValue(BLUE_WIRE,DIO_HIGH);
	DIO_SetPinValue(RED_WIRE,DIO_HIGH);
	DIO_SetPinValue(YELLOW_WIRE,DIO_LOW);
	DIO_SetPinValue(ORANGE_WIRE,DIO_LOW);
	_delay_ms(delay);
	DIO_SetPinValue(BLUE_WIRE,DIO_LOW);
	DIO_SetPinValue(RED_WIRE,DIO_HIGH);
	DIO_SetPinValue(YELLOW_WIRE,DIO_LOW);
	DIO_SetPinValue(ORANGE_WIRE,DIO_LOW);
	_delay_ms(delay);
	DIO_SetPinValue(BLUE_WIRE,DIO_LOW);
	DIO_SetPinValue(RED_WIRE,DIO_HIGH);
	DIO_SetPinValue(YELLOW_WIRE,DIO_HIGH);
	DIO_SetPinValue(ORANGE_WIRE,DIO_LOW);
	_delay_ms(delay);
	DIO_SetPinValue(BLUE_WIRE,DIO_LOW);
	DIO_SetPinValue(RED_WIRE,DIO_LOW);
	DIO_SetPinValue(YELLOW_WIRE,DIO_HIGH);
	DIO_SetPinValue(ORANGE_WIRE,DIO_LOW);
	_delay_ms(delay);
	DIO_SetPinValue(BLUE_WIRE,DIO_LOW);
	DIO_SetPinValue(RED_WIRE,DIO_LOW);
	DIO_SetPinValue(YELLOW_WIRE,DIO_HIGH);
	DIO_SetPinValue(ORANGE_WIRE,DIO_HIGH);
	_delay_ms(delay);
	DIO_SetPinValue(BLUE_WIRE,DIO_LOW);
	DIO_SetPinValue(RED_WIRE,DIO_LOW);
	DIO_SetPinValue(YELLOW_WIRE,DIO_LOW);
	DIO_SetPinValue(ORANGE_WIRE,DIO_HIGH);
	_delay_ms(delay);
	DIO_SetPinValue(BLUE_WIRE,DIO_HIGH);
	DIO_SetPinValue(RED_WIRE,DIO_LOW);
	DIO_SetPinValue(YELLOW_WIRE,DIO_LOW);
	DIO_SetPinValue(ORANGE_WIRE,DIO_HIGH);
	_delay_ms(delay);


}
