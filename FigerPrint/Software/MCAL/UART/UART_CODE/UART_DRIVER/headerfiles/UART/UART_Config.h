/*
 * UART_Config.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: mahmoud
 */

#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_


/*******************************************************************/
/********************UART CONFIGURATION ****************************/
/*******************************************************************/

//ENABLING/DISAPLING transmitting
#define UART_u8Transmitting 1
//ENABLING/DISAPLING rECIVING
#define UART_u8Ressiving 1
//baud rate   selection  DEFAULT 1 ------->9600
/*
 * 0	----> 2400
 * 1	----> 9600
 * 2	----> 115200
 */
#define UART_u8BUDRATE 1

//SYSTEM OSCILLATOR  default  4MHZ
//its impotant note to make the baud rate calc accurate
/*
 * 0	----> 4mhz
 * 1	----> 8MHZ
 * 2	----> 11.0592MHZ
 */
#define SYTEMOSCILLATOR 0

//THE NO COUNT  DATA BITS IN THE FRAME RANGE FROM 5 TO 9
//DEFAULT 8
#define UART_u8DATABITS 8

//choose  if 1 stop bits or 2 stop bits
//default 1
#define UART_u8STOPBITS 1

// CHOOSE THE PARITY CHECK 0 no parity 1 ODD 2 EVEN
#define UART_u8PARITY 1


///INTERUPT CONFIGURATION CONTROLL 0 dISAPLLED 1 ENABLED
#define UART_u8RXINTERUPTENABLE 			0
#define UART_u8TXINTERUPTENABLE				0
#define UART_u8DATAEMPTYINTERUPTENABLE		0
//doubling the baud rate u2x 1 is doubled 0 is not
#define UART_u8u2x 0

#endif /* UART_CONFIG_H_ */
