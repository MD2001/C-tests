/***********************************************************************************************************/
/***************************** Author : Mohamed diaa********************************************************/
/***************************** Layer : MCAL ****************************************************************/
/***************************** SWC : ADC *******************************************************************/
/***************************** Version : 1.0 ***************************************************************/


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "ADC_CONFIG.h"
#include "ADC_INTERFACE.h"
#include "ADC_PRIVET.h"




void ADC_Init(void)
{
	// ADC Enable
	SET_BIT(ADCSRA,ADCSRA_ADEN);

	// Prescaler Configuration as 128
	SET_BIT(ADCSRA,ADCSRA_ADPS2);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS0);
	// Referance Voltage as AVCC with external capacitor
	CLR_BIT(ADMUX,ADMUX_REFS1);
	SET_BIT(ADMUX,ADMUX_REFS0);

	CLR_BIT(ADMUX,ADMUX_ADLAR);
}

u16 ADC_Read (u8 channel)
{
	// ADC Channel Selection
	channel &= 0x07;
	ADMUX &= 0xE0;
	ADMUX |= channel;


	SET_BIT(ADCSRA,ADCSRA_ADSC);

	while(GET_BIT(ADCSRA,ADCSRA_ADIF)==0);

	SET_BIT(ADCSRA,ADCSRA_ADIF);

	return ADC;

}
