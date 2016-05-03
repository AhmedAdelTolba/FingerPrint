/*
 * UART_Private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: mahmoud
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

/*******************************************************************/
/****************    UART REGISTER *********************************/
/*******************************************************************/
#define UART_u8UDR		*((volatile u8*) 0x2C)//UART DATA REGISTER
#define UART_u8UCSRA	*((volatile u8*) 0X2B)//UART CONTROLL & Status Register A
#define UART_u8UCSRB	*((volatile u8*) 0X2A)//UART CONTROLL & Status Register B
#define UART_u8UCSRC	*((volatile u8*) 0X40)//UART CONTROLL & Status Register C
#define UART_u8UBRRH	*((volatile u8*) 0X40)//UART Baud Rate Register High
#define UART_u8UBRRL	*((volatile u8*) 0X29)//UART Baud Rate Register High

/*******************************************************************/
/****************   UCSRA BIT MAP **********************************/
/*******************************************************************/
#define UART_u8UCSRARXC_RXC		7//UART Receive complete
#define UART_u8UCSRARXC_TXC		6//UART Transmitter complete
#define UART_u8UCSRARXC_UDRE	5//UART Data Register Empty
#define UART_u8UCSRARXC_FE		4//UART Frame Error
#define UART_u8UCSRARXC_DOR		3//UARt data Over Run
#define UART_u8UCSRARXC_PE		2//UART Parity  Error
#define UART_u8UCSRARXC_U2X		1//UART double baud rate speed
#define UART_u8UCSRARXC_MPCM	0//UART master Processor communication Module
/*******************************************************************/
/****************   UCSRB BIT MAP **********************************/
/*******************************************************************/
#define UART_u8UCSRB_RXIE		7//UART receive Interrupt Enable
#define UART_u8UCSRB_TXIE		6//UART Transmitter Interrupt Enable
#define UART_u8UCSRB_UDRIE		5//UART data register is empty Interrupt
#define UART_u8UCSRB_RXEN		4//UART receive enable
#define UART_u8UCSRB_TXEN		3//UART transmitte enable
#define UART_u8UCSRB_UCSZ2		2//UART data character size
#define UART_u8UCSRB_RXB8		1//UART Recive data 9
#define UART_u8UCSRB_TXB8		0//UART transmitte data 9

/*******************************************************************/
/****************   UCSRC BIT MAP **********************************/
/*******************************************************************/

#define UART_u8UCSRC_URSEL		7//UART Register Select
#define UART_u8UCSRC_UMSEL		6//UART mode selactoer (sync ,async)
#define UART_u8UCSRC_UPM1		5//UART parity selection 1
#define UART_u8UCSRC_UPM0		4//UART	parity selection 0
#define UART_u8UCSRC_USBS		3//UART stop Bits  1, 2 bits
#define UART_u8UCSRC_UCSZ1		2//UART data bit number selector 1
#define UART_u8UCSRC_UCSZ0		1//UART data bit number selector 0
#define UART_u8UCSRC_UCPOL		0//UARTclk Polarity


/*******************************************************************/
/****************  UBRRH BIT MAP **********************************/
/*******************************************************************/
#define UART_u8UBRRH_URSEL		7//UBRRH Register Select


/*******************************************************************/
/**************** Concatenation helper *****************************/
/*******************************************************************/
#define conc(x7,x6,x5,x4,x3,x2,x1,x0)    helper(x0,x1,x2,x3,x4,x5,x6,x7)
#define helper(y0,y1,y2,y3,y4,y5,y6,y7) 0b##y7##y6##y5##y4##y3##y2##y1##y0


#endif /* UART_PRIVATE_H_ */
