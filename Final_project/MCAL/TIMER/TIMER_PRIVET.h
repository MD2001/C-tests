/***********************************************************************************************************/
/***************************** Author : Mohamed diaa********************************************************/
/***************************** Layer : MCAL ****************************************************************/
/***************************** SWC : TIMER *****************************************************************/
/***************************** Version : 1.0 ***************************************************************/
#ifndef TIMER_PRIVET_H
#define TIMER_PRIVET_H





#define TCCR2				*((volatile u8*)0x45)
#define TCCR2_WGM20			6
#define TCCR2_COM21			5
#define TCCR2_COM20			4
#define TCCR2_WGM21			3
#define TCCR2_CS22			2
#define TCCR2_CS21			1
#define TCCR2_CS20			0


#define TCNT2				*((volatile u8*)0x44)
#define OCR2				*((volatile u8*)0x43)







#define TCCR1A				*((volatile u8*)0x4F)
#define TCCR1A_WGM10		0
#define TCCR1A_WGM11		1
#define TCCR1A_COM1A1		7
#define TCCR1A_COM1A0		6
#define TCCR1B_WGM13		4
#define TCCR1B_WGM12		3


#define TCCR1B				*((volatile u8*)0x4E)		/*Timer1 control register B*/
#define TCCR1B_ICES1		6							/*Input caputer edge select*/
#define TCCR1B_CS12			2
#define TCCR1B_CS11			1
#define TCCR1B_CS10			0
#define ICR1 				*((volatile u16*)0x46)     /*ICU register*/
#define OCR1A				*((volatile u16*)0x4A)

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
#define TIMSK_OCIE2			7
#define TIMSK_TOIE2			6
#define TIMSK_TICIE1		5							/*Timer1 Input caputer intrupt enable*/
#define TIMSK_OCIE1A		4
#define TIMSK_OCIE1B		3
#define TIMSK_TOIE1			2
#define TIMSK_OCIE0			1
#define TIMSK_TOIE0			0


#define	TIFR				*((volatile u8*)0x58)
#define	TIFR_OCF2			7
#define	TIFR_TOV2			6
#define	TIFR_ICF1			5
#define	TIFR_OCF1A			4
#define	TIFR_OCF1B			3
#define	TIFR_TOV1			2
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

#define	NonInvertingMode	1
#define	InvertingMode		2

#define disconnected		1
#define Toggle				2
#define Clear				3
#define Set					4
#endif
