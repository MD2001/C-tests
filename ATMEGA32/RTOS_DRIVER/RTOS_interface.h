#ifndef _RTOS_INTERFACE_H
#define _RTOS_INTERFACE_H

void RTOS_voidStartRTOS();

void RTOS_voidCreateTask(u16 Copy_u16Periodicity,u8 Copy_u8Priority,void (*Copy_pvTaskFunc)(void));

#define Task_Num   3









#endif