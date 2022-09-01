#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

/****************************************************************
 name           : 	MTIMER0_voidInit                        
 description    : 	Sets Timer 0 mode  		                                         
 parameter      :   None		     
 options        :   Set from config file  
 return         : 	none                             
****************************************************************/
void MTIMER0_voidInit();



/****************************************************************
 name           : 	MTIMER0_voidTimer0CTCSetCallBack                        
 description    : 	Sets ISR function for on compare match mode		                                         
 parameter      :   Copy_pvCallBackFunc		       
 return         : 	none                             
****************************************************************/
void MTIMER0_voidTimer0CTCSetCallBack(void (*Copy_pvCallBackFunc)(void));

#endif 
