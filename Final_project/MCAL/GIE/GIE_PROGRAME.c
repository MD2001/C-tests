/***********************************************************************************************************/
/***************************** Author : Mohamed diaa********************************************************/
/***************************** Layer : MCAL ****************************************************************/
/***************************** SWC : GIE *******************************************************************/
/***************************** Version : 1.0 ***************************************************************/

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "GIE_INTERFACE.h"
#include "GIE_PRIVET.h"



void GIE_voidEnable(void)
{
	SET_BIT(SREG,SREG_I);
	}
void GIE_voidDesable(void)
{
	CLR_BIT(SREG,SREG_I);
	}