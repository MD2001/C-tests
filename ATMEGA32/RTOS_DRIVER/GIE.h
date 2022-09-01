#ifndef _GIE_H
#define _GIE_H


#define SREG           *((volatile u8*)0x5F)   /*AVR STATUS REGISTER*/
#define SREG_GIE       7                       /*GLOBAL INTERRUPT ENABLE*/

void GIE_voidEnableGlobalInterrupt();

#endif