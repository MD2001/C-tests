/***********************************************************************************************************/
/***************************** Author : Mohamed diaa********************************************************/
/***************************** Layer : MCAL ****************************************************************/
/***************************** SWC : TIMER *****************************************************************/
/***************************** Version : 1.0 ***************************************************************/

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../GIE/GIE_INTERFACE.h"
#include "TIMER_CONFIG.h"
#include "TIMER_INTERFACE.h"
#include "TIMER_PRIVET.h"


static void (*TIMER0_pvCallBackFunc)(void)=NULL;
static void (*ICU_pvCallBackFunc)(void) =NULL;

static u16 ms=0;



static void time_for_1ms()
{
	static u8 counter=0;
	counter++;
	if(counter == 4)
	{
		counter=0;
		ms++;
		TCNT0=20;
	}
}
void Timer1_Init()
{

}
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
	TIMER0_FastPwmMode(NonInvertingMode);
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
	OCR0=75;
}

void TIMER0_FastPwmMode(u8 FAST_PWM_MODE)
{
	if(FAST_PWM_MODE ==NonInvertingMode)
	{
		SET_BIT(TCCR0,TCCR0_COM01);
		CLR_BIT(TCCR0,TCCR0_COM00);
	}
	else if(FAST_PWM_MODE ==InvertingMode)
	{
		SET_BIT(TCCR0,TCCR0_COM01);
		SET_BIT(TCCR0,TCCR0_COM00);
	}
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

void TIMER_delay_ms(u16 time_ms)
{
	/*set to normal mode and set presquler to 8*/
	/*
	 * Normal mood:
	 *  CLR_BIT(TCCR0,TCCR0_WGM01);
		CLR_BIT(TCCR0,TCCR0_WGM00);

		presquler 8 :
		CLR_BIT(TCCR0,TCCR0_CS02);
		SET_BIT(TCCR0,TCCR0_CS01);
		CLR_BIT(TCCR0,TCCR0_CS00);

	 * **/

	GIE_voidEnable();
	/*To Enable Interubt*/
	TCCR0 |=0b00000010;
	TCNT0=20;
	TIMER_SetCallBack(&time_for_1ms);

	/*Enable overflow interupt*/
	SET_BIT(TIMSK,TIMSK_TOIE0);

	while(ms != time_ms)
	{}
	ms =0;
}





u8 TIMER_SetCallBack(void (*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorStauts=OK;
	if(Copy_pvCallBackFunc != NULL)
	{
		TIMER0_pvCallBackFunc=Copy_pvCallBackFunc;

	}
	else
	{

	}
	return Local_u8ErrorStauts;
}

void ICU_Init()
{

	///**Set to rising eddge*/
	SET_BIT(TCCR1B,TCCR1B_ICES1);
	/*Enable interupt*/
	SET_BIT(TIMSK,TIMSK_TICIE1);


}

void ICU_SetEdge(u8 Edge)
{
	if(Edge==ICU_RISING_EDGE)
	{
		SET_BIT(TCCR1B,TCCR1B_ICES1);
	}
	else if(Edge==ICU_FALLING_EDGE)
	{
		CLR_BIT(TCCR1B,TCCR1B_ICES1);
	}

}

void ICU_EnableIntrupt()
{
	SET_BIT(TIMSK,TIMSK_TICIE1);
}

void ICU_DisableIntrupt()
{
	CLR_BIT(TIMSK,TIMSK_TICIE1);
}

u16 ICU_ReadICU()
{
	return ICR1;
}

u8 ICU_SetCallBack(void (*Copy_pvCallBackFunc)(void))
{

	u8 Local_u8ErrorStauts=OK;

	if(Copy_pvCallBackFunc!=NULL)
	{
		ICU_pvCallBackFunc=Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorStauts=NOT_OK;
	}
	return Local_u8ErrorStauts;

}

void __vector_11 (void) __attribute__((signal));
void __vector_11 (void)
{
	if(TIMER0_pvCallBackFunc != NULL)
	{
		TIMER0_pvCallBackFunc();
	}

}
/////////////////////////////////////////////////////////////////
void Timer1_init()
{
	/*Fast PWM non-inverting mode*/
	SET_BIT(TCCR1A,TCCR1A_COM1A1);
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);

	/*Set to fast PWM mode*/
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);

	/*Set Clock*/
	CLR_BIT(TCCR1B,TCCR1B_CS10);
	CLR_BIT(TCCR1B,TCCR1B_CS12);
	SET_BIT(TCCR1B,TCCR1B_CS11);

}


void Timer1_SetICR(u16 Copy_data)
{
	ICR1=Copy_data;
	}

void Timer1_SetChannelACompaermach(u16 Copy_data)
{
	OCR1A=Copy_data;
}
////////////////////////////////////////////////////////////////


void __vector_6 (void) __attribute__((signal));
void __vector_6 (void)
{
	if(ICU_pvCallBackFunc != NULL)
	{
		ICU_pvCallBackFunc();
	}

}
