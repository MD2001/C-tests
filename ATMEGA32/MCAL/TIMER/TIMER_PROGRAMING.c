/***********************************************************************************************************/
/***************************** Author : Mohamed diaa********************************************************/
/***************************** Layer : MCAL ****************************************************************/
/***************************** SWC : TIMER *****************************************************/
/***************************** Version : 1.0 ***************************************************************/

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "TIMER_CONFIG.h"
#include "TIMER_INTERFACE.h"
#include "TIMER_PRIVET.h"

#define NULL    ((void *) 0)
static void (*TIMER0_pvCallBackFunc)(void)=NULL;

void Timer_init()
{
	/*Chooses Mode*/
#if Mode == Normal
	CLR_BIT(TCCR0,TCCR0_WGM01);
	CLR_BIT(TCCR0,TCCR0_WGM00);
#elif Mode == PWM
	CLR_BIT(TCCR0,TCCR0_WGM01);
	SET_BIT(TCCR0,TCCR0_WGM00);
#elif Mode == CTC
	SET_BIT(TCCR0,TCCR0_WGM01);
	CLR_BIT(TCCR0,TCCR0_WGM00);
#elif Mode == Fast_PWM
	SET_BIT(TCCR0,TCCR0_WGM01);
	SET_BIT(TCCR0,TCCR0_WGM00);
#else
#error "Warning : the mode not selected correct"
#endif


	/*Chooses Prescalouer*/
#if CLOCK == No_clock_source
	CLR_BIT(TCCR0,TCCR0_CS02);
	CLR_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS00);
#elif CLOCK == presquler_1
	CLR_BIT(TCCR0,TCCR0_CS02);
	CLR_BIT(TCCR0,TCCR0_CS01);
	SET_BIT(TCCR0,TCCR0_CS00);
#elif CLOCK == presquler_8
	CLR_BIT(TCCR0,TCCR0_CS02);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS00);
#elif CLOCK == presquler_64
	CLR_BIT(TCCR0,TCCR0_CS02);
	SET_BIT(TCCR0,TCCR0_CS01);
	SET_BIT(TCCR0,TCCR0_CS00);
#elif CLOCK == presquler_256
	SET_BIT(TCCR0,TCCR0_CS02);
	CLR_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS00);
#elif CLOCK == presquler_1024
	SET_BIT(TCCR0,TCCR0_CS02);
	CLR_BIT(TCCR0,TCCR0_CS01);
	SET_BIT(TCCR0,TCCR0_CS00);
#else
#error "Warning : the Clock not selected correct"


#endif

	/*Output compara mach interuput enable*/
	SET_BIT(TIMSK,TIMSK_OCIE0);


	/*Set compare mach value*/
	OCR0=250;
}

void TIMER_OC0State()
{
#if OC0State ==  disconnected
	CLR_BIT(TCCR0,TCCR0_COM01);
	CLR_BIT(TCCR0,TCCR0_COM00);
#elif OC0State == Toggle
	CLR_BIT(TCCR0,TCCR0_COM01);
	SET_BIT(TCCR0,TCCR0_COM00);
#elif OC0State == Clear
	SET_BIT(TCCR0,TCCR0_COM01);
	CLR_BIT(TCCR0,TCCR0_COM00);
#elif OC0State == Set
	SET_BIT(TCCR0,TCCR0_COM01);
	SET_BIT(TCCR0,TCCR0_COM00);
#else
#error "Warning :OC0State is not correct "
#endif
}
void TIMER_SetOCR0TO(u8 num)
{
	OCR0=num;
}
void TIMER_SetTCNT0TO(u8 num)
{
	TCNT0=num;
}


void TIMER_SetCallBack(void (*Copy_pvCallBackFunc)(void))
{
	//u8 Local_u8ErrorStauts=NULL;
	if(Copy_pvCallBackFunc != NULL)
	{
		TIMER0_pvCallBackFunc=Copy_pvCallBackFunc;

	}
	else
	{

	}
}

void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	if(TIMER0_pvCallBackFunc != NULL)
	{
		TIMER0_pvCallBackFunc();
	}

}
