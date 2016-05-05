/*
 * UART_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: mahmoud
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

extern void UART_VoidInit(void);
extern void UART_VoidSending(u8 copy_u8ValToSend);
extern void UART_VoidResiving(u8* copy_u8ValToRecive);
extern void UART_voidcheckfor_Interupts(u8 *copy_u8ptrto3Flags_RX_TX_EMPTY);
extern void UART_voidwriteToUDR(u8 copy_u8valToSend);
extern void UART_voidReadFromUDR(u8 *copy_u8valInUDR);

extern void UART_voidFlushMemory(void);
extern void UART_voidSetTX_ISR(void (*Copy_PtrToTXISR)(void));
extern void UART_voidSetRX_ISR(void (*Copy_PtrToRXISR)(void));
extern void UART_voidSetBufferEmpty_ISR(void (*Copy_PtrToBufferEmptyISR)(void));

#endif /* UART_INTERFACE_H_ */
