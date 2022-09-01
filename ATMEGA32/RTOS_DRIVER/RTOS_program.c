#include "../LIB/STD_TYPES.h"

#include "GIE.h"
#include "TIMER0_interface.h"

#include "RTOS_private.h"
#include "RTOS_interface.h"
#include "RTOS_config.h"


Task_Create  System_Tasks[Task_Num]={{NULL}};

void RTOS_voidStartRTOS()
{
	GIE_voidEnableGlobalInterrupt();
	MTIMER0_voidTimer0CTCSetCallBack(voidScheduler);
	MTIMER0_voidInit();
}

void RTOS_voidCreateTask(u16 Copy_u16Periodicity,u8 Copy_u8Priority,void (*Copy_pvTaskFunc)(void))
{
	if(Copy_pvTaskFunc!=NULL)
	{
		System_Tasks[Copy_u8Priority].priority=Copy_u8Priority;
		System_Tasks[Copy_u8Priority].Periodicity=Copy_u16Periodicity;
		System_Tasks[Copy_u8Priority].pvTaskFunction=Copy_pvTaskFunc;
	}
	else
	{
		/*do nothing */
	}
}




void voidScheduler()
{
	u16 static Local_u16Counter=0;
	u8 Local_u8Priority;
	Local_u16Counter++;
	
	for(Local_u8Priority=0;Local_u8Priority<Task_Num;Local_u8Priority++)
	{
		
			if(Local_u16Counter%System_Tasks[Local_u8Priority].Periodicity==0)
		{
				if(System_Tasks[Local_u8Priority].pvTaskFunction!=NULL)
					{
						System_Tasks[Local_u8Priority].pvTaskFunction();
					}
				else 
					{
					/*do nothing */
					}
		}
			else 
			{
				/*do nothing*/
			}

		
	
	
	}
}
