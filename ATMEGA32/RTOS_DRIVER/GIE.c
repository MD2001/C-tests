#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "GIE.h"

void GIE_voidEnableGlobalInterrupt()
{
	SET_BIT(SREG,SREG_GIE);
}
