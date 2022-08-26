/***********************************************************************************************************/
/***************************** Author : Mohamed diaa********************************************************/
/***************************** Layer : HAL *****************************************************************/
/***************************** SWC : KPD *******************************************************************/
/***************************** Version : 1.0 ***************************************************************/
/*File Guard*/
#ifndef KYP_CONFIG_H
#define KYP_CONFIG_H

#define KPD_NO_PRESSED_KEY    0xff
 
#define KPD_PORT   		      DIO_PORTD

#define KPD_ARR_VAL     	  { {1,'0','=','+' }, {'1','2','3','-'} , {'4','5','6','*'} , {'7','8','9','/'} }
#define KPD_ROWS      		  4
#define KPD_COULMNS        	  4


#define KPD_COULMN0_PIN  DIO_PIN0
#define KPD_COULMN1_PIN  DIO_PIN1
#define KPD_COULMN2_PIN  DIO_PIN2
#define KPD_COULMN3_PIN  DIO_PIN3

#define KPD_ROW0_PIN     DIO_PIN4
#define KPD_ROW1_PIN     DIO_PIN5
#define KPD_ROW2_PIN     DIO_PIN6
#define KPD_ROW3_PIN     DIO_PIN7

#endif
