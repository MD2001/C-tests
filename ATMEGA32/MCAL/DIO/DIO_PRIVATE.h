/***********************************************************************************************************/
/***************************** Author : Mohamed diaa********************************************************/
/***************************** Layer : MCAL *****************************************************************/
/***************************** SWC : DIO *******************************************************************/
/***************************** Version : 2.0 ***************************************************************/
#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

#define PORTA_REG      *((volatile u8 *)0x3B)
#define DDRA_REG       *((volatile u8 *)0x3A)
#define PINA_REG       *((volatile u8 *)0x39)
				       
#define PORTB_REG      *((volatile u8 *)0x38)
#define DDRB_REG       *((volatile u8 *)0x37)
#define PINB_REG       *((volatile u8 *)0x36)
					   
#define PORTC_REG      *((volatile u8 *)0x35)
#define DDRC_REG       *((volatile u8 *)0x34)
#define PINC_REG       *((volatile u8 *)0x33)
					   
#define PORTD_REG      *((volatile u8 *)0x32)
#define DDRD_REG       *((volatile u8 *)0x31)
#define PIND_REG       *((volatile u8 *)0x30)

#define conc(b7,b6,b5,b4,b3,b2,b1,b0)		conc_helper(b7,b6,b5,b4,b3,b2,b1,b0)
#define conc_helper(b7,b6,b5,b4,b3,b2,b1,b0)		0b##b7##b6##b5##b4##b3##b2##b1##b0

#define PORTA_DIR		conc(PORTA_PIN7_DIR,PORTA_PIN6_DIR,PORTA_PIN5_DIR,PORTA_PIN4_DIR,PORTA_PIN3_DIR,PORTA_PIN2_DIR,PORTA_PIN1_DIR,PORTA_PIN0_DIR)
#define PORTB_DIR		conc(PORTB_PIN7_DIR,PORTB_PIN6_DIR,PORTB_PIN5_DIR,PORTB_PIN4_DIR,PORTB_PIN3_DIR,PORTB_PIN2_DIR,PORTB_PIN1_DIR,PORTB_PIN0_DIR)
#define PORTC_DIR		conc(PORTC_PIN7_DIR,PORTC_PIN6_DIR,PORTC_PIN5_DIR,PORTC_PIN4_DIR,PORTC_PIN3_DIR,PORTC_PIN2_DIR,PORTC_PIN1_DIR,PORTC_PIN0_DIR)
#define PORTD_DIR		conc(PORTD_PIN7_DIR,PORTD_PIN6_DIR,PORTD_PIN5_DIR,PORTD_PIN4_DIR,PORTD_PIN3_DIR,PORTD_PIN2_DIR,PORTD_PIN1_DIR,PORTD_PIN0_DIR)

#define PORTA_INITALE_VALUE		conc(PORTA_PIN7_INITALE_VALUE,PORTA_PIN6_INITALE_VALUE,PORTA_PIN5_INITALE_VALUE,PORTA_PIN4_INITALE_VALUE,PORTA_PIN3_INITALE_VALUE,PORTA_PIN2_INITALE_VALUE,PORTA_PIN1_INITALE_VALUE,PORTA_PIN0_INITALE_VALUE)
#define PORTB_INITALE_VALUE		conc(PORTB_PIN7_INITALE_VALUE,PORTB_PIN6_INITALE_VALUE,PORTB_PIN5_INITALE_VALUE,PORTB_PIN4_INITALE_VALUE,PORTB_PIN3_INITALE_VALUE,PORTB_PIN2_INITALE_VALUE,PORTB_PIN1_INITALE_VALUE,PORTB_PIN0_INITALE_VALUE)
#define PORTC_INITALE_VALUE		conc(PORTC_PIN7_INITALE_VALUE,PORTC_PIN6_INITALE_VALUE,PORTC_PIN5_INITALE_VALUE,PORTC_PIN4_INITALE_VALUE,PORTC_PIN3_INITALE_VALUE,PORTC_PIN2_INITALE_VALUE,PORTC_PIN1_INITALE_VALUE,PORTC_PIN0_INITALE_VALUE)
#define PORTD_INITALE_VALUE		conc(PORTD_PIN7_INITALE_VALUE,PORTD_PIN6_INITALE_VALUE,PORTD_PIN5_INITALE_VALUE,PORTD_PIN4_INITALE_VALUE,PORTD_PIN3_INITALE_VALUE,PORTD_PIN2_INITALE_VALUE,PORTD_PIN1_INITALE_VALUE,PORTD_PIN0_INITALE_VALUE)

#define input  0
#define output 1

#define floating_input	0
#define output_low		0
#define puledup_input	1
#define output_high		1	



#endif
