/***********************************************************************************************************/
/***************************** Author : Mohamed diaa********************************************************/
/***************************** Layer : MCAL ****************************************************************/
/***************************** SWC : TIMER *****************************************************/
/***************************** Version : 1.0 ***************************************************************/
#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H


void Timer1_init();
void Timer1_SetChannelACompaermach(u16 Copy_data);
void Timer1_SetICR(u16 Copy_data);

void Timer_init();
u8 TIMER_SetCallBack(void (*Copy_pvCallBackFunc)(void));

void TIMER_delay_ms(u16 time_ms);
void TIMER_delay();
void TIMER_OC0State();

void TIMER_SetOCR0TO(u8 num);
void TIMER_SetTCNT0TO(u8 num);

void ICU_Init();
void ICU_SetEdge(u8 Edge);
void ICU_DisableIntrupt();
void ICU_EnableIntrupt();
void TIMER0_FastPwmMode(u8 FAST_PWM_MODE);
u16 ICU_ReadICU();
u8 ICU_SetCallBack(void (*Copy_pvCallBackFunc)(void));

#define ICU_RISING_EDGE			1
#define ICU_FALLING_EDGE		2
#endif
