/***********************************************************************************************************/
/***************************** Author : Mohamed diaa********************************************************/
/***************************** Layer : MCAL ****************************************************************/
/***************************** SWC : USART *******************************************************************/
/***************************** Version : 2.0 ***************************************************************/
#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

#include "../../LIB/STD_TYPES.h"

u8 USART_u8Read();
void USART_voidSend(u8 Copy_data);
void USART_voidInit(void);
#endif
