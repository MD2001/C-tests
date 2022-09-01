#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"

#include "TIMER0_interface.h"
#include "TIMER0_private.h"
#include "TIMER0_config.h"

     /*Define Pointer to TIMER0 ISR functions*/
 void (*Global_pvTimerOverFlowCallBack)(void)= NULL;
 void (*Global_pvTimerCTCCallBack)(void)= NULL;
	 
void MTIMER0_voidInit()
{
	/*Choose CTC Mode*/
	CLR_BIT(TCCR0, TCCR0_WGM00);
	SET_BIT(TCCR0, TCCR0_WGM01);
	
	/*OUTPUT COMPARE MATCH INTERRUPT ENABLE*/
	SET_BIT(TIMSK, TIMSK_OCIE);

	/*Set compare match value to 250*/
	OCR0=125;

	/*Set PRESCALAR 1*/
	SET_BIT(TCCR0, TCCR0_CS00);
	SET_BIT(TCCR0, TCCR0_CS01);
	CLR_BIT(TCCR0, TCCR0_CS02);
	
}





void MTIMER0_voidTimer0CTCSetCallBack(void (*Copy_pvCallBackFunc)(void))
{
	if(Copy_pvCallBackFunc != NULL) /*checking if function exists*/
	{
		Global_pvTimerCTCCallBack= Copy_pvCallBackFunc; /*ADDS ISR Function*/
	}
	else
	{
		/*do nothing*/
	}

}



//ON COMPARE ISR
void  __vector_10 (void)	__attribute__((signal));
void  __vector_10 (void)
{
	if(Global_pvTimerCTCCallBack != NULL)
	{
		Global_pvTimerCTCCallBack();
	}
	else
	{
		/*Do nothing*/
	}

}
