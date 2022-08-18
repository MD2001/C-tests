/***********************************************************************************************************/
/***************************** Author : Mohamed diaa********************************************************/
/***************************** Layer : MCAL ****************************************************************/
/***************************** SWC : EXTERNAL INTERUPT *****************************************************/
/***************************** Version : 1.0 ***************************************************************/

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

#error "WRONG : SENCE CONTROL CONFIGRATION"

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
