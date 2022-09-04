/***********************************************************************************************************/
/***************************** Author : Mohamed diaa********************************************************/
/***************************** Layer : MCAL ****************************************************************/
/***************************** SWC : USART *******************************************************************/
/***************************** Version : 2.0 ***************************************************************/
#ifndef USART_RIGSTER_H
#define  USART_RIGSTER_H


#define UDR               *((volatile u8*)0x2C)     //USART I/O data register(transmitter)
//#define UDR               *((volatile u8*)0x2C)    //USART I/O data register(receiver)

#define UCSRA               *((volatile u8*)0x2B)    //USART control and status A register
#define UCSRA_RXC           7
#define UCSRA_TXC           6
#define UCSRA_UDRE          5
#define UCSRA_FE            4
#define UCSRA_DOR           3
#define UCSRA_PE            2
#define UCSRA_U2X           1
#define UCSRA_MPCM          0

#define UCSRB               *((volatile u8*)0x2A)    //USART control and status B register
#define UCSRB_RXCIE         7
#define UCSRB_TXCIE         6
#define UCSRB_UDRIE         5
#define UCSRB_RXEN          4
#define UCSRB_TXEN          3
#define UCSRB_UCSZ2         2
#define UCSRB_RXB8          1
#define UCSRB_TXB8          0

#define UCSRC               *((volatile u8*)0x40)    //USART control and status C register
#define UCSRC_URSEL         7
#define UCSRC_UMSEL         6
#define UCSRC_UPM1          5
#define UCSRC_UPM0          4
#define UCSRC_USBS          3
#define UCSRC_UCSZ1         2
#define UCSRC_UCSZ0         1
#define UCSRC_UCPOL         0

#define UBRRL               *((volatile u8*)0x29)    //USART baud rate register(low byte)
#define UBRRH               *((volatile u8*)0x40)    //USART baud rate register(high byte)

#endif
