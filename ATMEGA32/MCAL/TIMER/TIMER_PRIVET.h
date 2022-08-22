/***********************************************************************************************************/
/***************************** Author : Mohamed diaa********************************************************/
/***************************** Layer : MCAL ****************************************************************/
/***************************** SWC : TIMER *****************************************************************/
/***************************** Version : 1.0 ***************************************************************/
#ifndef TIMER_PRIVET_H
#define TIMER_PRIVET_H


#define TCCR0  				*((volatile u8*)0x53)
#define TCCR0_FOC0			7
#define TCCR0_WGM00			6
#define TCCR0_COM01			5
#define TCCR0_COM00			4
#define TCCR0_WGM01			3
#define TCCR0_CS02			2
#define TCCR0_CS01			1
#define TCCR0_CS00			0

#define TCNT0 				*((volatile u8*)0x52)
#define OCR0 				*((volatile u8*)0x5C)
#define TIMSK 				*((volatile u8*)0x59)
#define TIMSK_OCIE0			1
#define TIMSK_TOIE0			0


#define	TIFR				*((volatile u8*)0x58)
#define	TIFR_OCF0			1
#define	TIFR_TOV0			0

#define Normal				1
#define PWM					2
#define CTC					3
#define Fast_PWM			4

#define No_clock_source		1
#define presquler_1			2
#define presquler_8			3
#define presquler_64		4
#define presquler_256		5
#define presquler_1024		6

#define disconnected		1
#define Toggle				2
#define Clear				3
#define Set					4
#endif
