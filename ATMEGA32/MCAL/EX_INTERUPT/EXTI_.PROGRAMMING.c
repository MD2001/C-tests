/***********************************************************************************************************/
/***************************** Author : Mohamed diaa********************************************************/
/***************************** Layer : MCAL ****************************************************************/
/***************************** SWC : EXTERNAL INTERUPT *****************************************************/
/***************************** Version : 1.1 ***************************************************************/

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "EXTI_CONFIG.h"
#include "EXTI_INTERFACE.h"
#include "EXTI_PRIVET.h"


void EXTI_voidInt0Init(void)
{
	/*Check sequence control of pin  INIT0*/

#if INIT0_SENCE == LOW_LEVEL

	CLR_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);

#elif INIT0_SENCE == ON_CHANEGE

	SET_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);

#elif INIT0_SENCE == FALLING_EDGE
	CLR_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);
#elif INIT0_SENCE == RISNG_EDGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);
#else

#error "WRONG : INIT0 SENCE CONTROL CONFIGRATION"

#endif



	/*Intitle state*/



#if INT0_INITIAL_STATE == ENABLED

	SET_BIT(GICR,GICR_INT0);
#elif  INT0_INITIAL_STATE == DISABLED

	CLR_BIT(GICR,GICR_INT0);
#else
#error "WRONG : INT0_INITIAL_STATE CONFIGRATION"

#endif



}



void EXTI_voidInt1Init(void)
{
	/*Check sequence control of pin  INIT1*/
#if INIT1_SENCE == LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC11);
	CLR_BIT(MCUCR,MCUCR_ISC10);
#elif INIT1_SENCE == ON_CHANEGE
	CLR_BIT(MCUCR,MCUCR_ISC11);
	SET_BIT(MCUCR,MCUCR_ISC10);
#elif INIT1_SENCE == FALLING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC11);
	CLR_BIT(MCUCR,MCUCR_ISC10);
#elif INIT1_SENCE ==  RISNG_EDGE
	SET_BIT(MCUCR,MCUCR_ISC11);
	SET_BIT(MCUCR,MCUCR_ISC10);
#else
#error "WRONG : INIT1 SENCE CONTROL CONFIGRATION"

#endif

	/*Entitle state*/

#if INT1_INITIAL_STATE == ENABLED

	SET_BIT(GICR,GICR_INT1);
#elif  INT1_INITIAL_STATE == DISABLED

	CLR_BIT(GICR,GICR_INT1);
#else
#error "WRONG : INT1_INITIAL_STATE CONFIGRATION"

#endif
}


void EXTI_voidInt2Init()
{
#if INIT2_SENCE == FALLING_EDGE
		CLR_BIT(MCUCSR,MCUCSR_ISC2);
#elif	INIT2_SENCE ==  RISNG_EDGE
		SET_BIT(MCUCSR,MCUCSR_ISC2);
#else
#error "WRONG : INIT2 SENCE CONTROL CONFIGRATION"

#endif

#if INT2_INITIAL_STATE == ENABLED
		SET_BIT(GICR,GICR_INT2);
#elif INT2_INITIAL_STATE == DISABLED
		SET_BIT(GICR,GICR_INT2);
#else
#error "WRONG : INT1_INITIAL_STATE CONFIGRATION"
#endif



}
