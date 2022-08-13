#include "../../LIB/BIT_MATH.h"
#include "DIO_INTERFACE.h"
#include "DIO_PRIVET.h"
void DIO_SetpinDirection(u8 Port, u8 Pin,u8 Direction)
{
	switch (Port)
	{
		case PORTA:
			switch(Direction)
			{
			case INPUT:
				CLR_BIT(DDRA_RG,Pin);
				break;
			case OUTPUT:
				SET_BIT(DDRA_RG,Pin);
				break;
			}
			break;

			case PORTB:
			switch(Direction)
			{
			case INPUT:
				CLR_BIT(DDRB_RG,Pin);
				break;
			case OUTPUT:
				SET_BIT(DDRB_RG,Pin);
				break;
			}
			break;


			case PORTC:
				switch(Direction)
				{
				case INPUT:
					CLR_BIT(DDRC_RG,Pin);
					break;
				case OUTPUT:
					SET_BIT(DDRC_RG,Pin);
					break;
				}
				break;




			case PORTD:
			switch(Direction)
			{
			case INPUT:
				CLR_BIT(DDRD_RG,Pin);
				break;
			case OUTPUT:
				SET_BIT(DDRD_RG,Pin);
				break;
			}
			break;


	 }
}



void DIO_SetPinValue(u8 Port,u8 Pin,u8 Value)
{


switch (Port)
	{
		case PORTA:
			switch(Value)
			{
			case LOW:
				CLR_BIT(PORTA_RG,Pin);
				break;
			case HIGH:
				SET_BIT(PORTA_RG,Pin);
				break;
			}
			break;


			case PORTB:
				switch(Value)
				{
				case LOW:
					CLR_BIT(PORTB_RG,Pin);
					break;
				case HIGH:
					SET_BIT(PORTB_RG,Pin);
					break;
				}
				break;

				case PORTC:
					switch(Value)
					{
					case LOW:
						CLR_BIT(PORTC_RG,Pin);
						break;
					case HIGH:
						SET_BIT(PORTC_RG,Pin);
						break;
					}
					break;
					case PORTD:
						switch(Value)
						{
						case LOW:
							CLR_BIT(PORTD_RG,Pin);
							break;
						case HIGH:
							SET_BIT(PORTD_RG,Pin);
							break;
						}
						break;
	}




}


u32 DIO_GetPinValue(u8 Port,u8 Pin)
{
switch(Port)
{
	case PORTA: return GET_BIT(PORTA_RG,Pin);
	case PORTB: return GET_BIT(PORTB_RG,Pin);
	case PORTC: return GET_BIT(PORTC_RG,Pin);
	case PORTD: return GET_BIT(PORTD_RG,Pin);
}
}

