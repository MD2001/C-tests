#ifndef _RTOS_private_H
#define _RTOS_private_H


typedef struct
{
	u16 Periodicity;
	u8  priority;
	void (*pvTaskFunction)(void);
}Task_Create;









void voidScheduler();

#endif