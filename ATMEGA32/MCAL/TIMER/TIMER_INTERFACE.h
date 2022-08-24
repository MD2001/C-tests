/***********************************************************************************************************/
/***************************** Author : Mohamed diaa********************************************************/
/***************************** Layer : MCAL ****************************************************************/
/***************************** SWC : TIMER *****************************************************/
/***************************** Version : 1.0 ***************************************************************/
#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

void Timer_init();
u8 TIMER_SetCallBack(void (*Copy_pvCallBackFunc)(void));

void TIMER_delay_ms(u16 time_ms);
void TIMER_delay();
void TIMER_OC0State();

void TIMER_SetOCR0TO(u8 num);
void TIMER_SetTCNT0TO(u8 num);

#endif
