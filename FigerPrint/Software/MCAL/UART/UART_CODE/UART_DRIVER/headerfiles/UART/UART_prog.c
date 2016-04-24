/*
 * UART_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: mahmoud
 */

/*******************************************************************/
/****************  INCLUDES ****************************************/
/*******************************************************************/
#include"../types.h"
#include "../util.h"
#include"UART_Config.h"
#include"UART_Private.h"
#include "../InteruptVector.h"


/*******************************************************************/
/************** configuration Dependant operation ******************/
/*******************************************************************/

#define EIGHTBBITS 8

/*******************************************************************/
/************** configuration checking operations ******************/
/*******************************************************************/
#if UART_u8Transmitting==0

#elif UART_u8Transmitting==1
#else
	#error UART_u8Transmitting at uart configuration .h   must be 0 or 1
#endif


#if UART_u8Ressiving==0

#elif UART_u8Ressiving==1
#else
	#error UART_u8Ressiving at uart configuration .h   must be 0 or 1
#endif

#if (UART_u8BUDRATE>=0&UART_u8BUDRATE<=2)
#else
	#error UART_u8BUDRATE at uart configuration .h   must be 0 to 2
#endif


#if (SYTEMOSCILLATOR>=0&SYTEMOSCILLATOR<=2)
#else
	#error SYTEMOSCILLATOR at uart configuration .h   must be 0 to 2
#endif


#if   UART_u8DATABITS==5
	#define UART_PROG_U8UCSZ0 0
	#define UART_PROG_U8UCSZ1 0
	#define UART_PROG_U8UCSZ2 0

#elif UART_u8DATABITS==6
	#define UART_PROG_U8UCSZ0 1
	#define UART_PROG_U8UCSZ1 0
	#define UART_PROG_U8UCSZ2 0
#elif UART_u8DATABITS==7
	#define UART_PROG_U8UCSZ0 0
	#define UART_PROG_U8UCSZ1 1
	#define UART_PROG_U8UCSZ2 0
#elif UART_u8DATABITS==8
	#define UART_PROG_U8UCSZ0 1
	#define UART_PROG_U8UCSZ1 1
	#define UART_PROG_U8UCSZ2 0
#elif UART_u8DATABITS==9
	#define UART_PROG_U8UCSZ0 1
	#define UART_PROG_U8UCSZ1 1
	#define UART_PROG_U8UCSZ2 1
#else
	#error UART_u8DATABITS at uart configuration .h   must be 5 to 9
#endif


#if UART_u8STOPBITS==1
	#define UART_u8STOPBITSLOCAL 0
#elif UART_u8STOPBITS==2
	#define UART_u8STOPBITS 1
#else
	#error UART_u8STOPBITS at uart configuration .h   must be 1 or 2
#endif

#if UART_u8PARITY==0
	#define UART_u8PARITY0 0
	#define UART_u8PARITY1 0

#elif UART_u8PARITY==1
	#define UART_u8PARITY0 0
	#define UART_u8PARITY1 1
#elif UART_u8PARITY==2
	#define UART_u8PARITY0 1
	#define UART_u8PARITY1 1
#else
	#error UART_u8PARITY at uart configuration .h   must be 1 or 2
#endif

#if (UART_u8RXINTERUPTENABLE==0|UART_u8RXINTERUPTENABLE==1)
#else
	#error UART_u8RXINTERUPTENABLE at uart configuration .h   must be 0 0r 1
#endif

#if (UART_u8TXINTERUPTENABLE==0|UART_u8TXINTERUPTENABLE==1)
#else
	#error UART_u8TXINTERUPTENABLE at uart configuration .h   must be 0 0r 1
#endif

#if (UART_u8DATAEMPTYINTERUPTENABLE==0|UART_u8DATAEMPTYINTERUPTENABLE==1)
#else
	#error UART_u8DATAEMPTYINTERUPTENABLE at uart configuration .h   must be 0 0r 1
#endif
/*******************************************************************/
/************** configuration Dependant operation ******************/
/*******************************************************************/
#if UART_u8u2x==0
const u16 baudRate[3][3]={{103,25,1},
						  {207,51,3},
						  {287,71,5}};

#elif UART_u8u2x==1
const u16 baudRate[3][3]={{207,51,3},
					      {416,103,8},
					      {575,143,11}};

#else
#error UART_u8u2x at uart configuration .h   must be 1 or 2
#endif


/*******************************************************************/
/****************   Public API**************************************/
/*******************************************************************/


static void (* UART_TXInteruptPointer)(void);
static void (* UART_RXInteruptPointer)(void);
static void (* UART_BufferEmptyInteruptPointer)(void);

/*comment!:initialization function to inatialize the baud rate and UART configured  characteristic*/
extern void UART_VoidInit(void) {
	//INITIALIZE THE BAUD RATE
	//Getting the value to load in the UBBRH & UBBRL to
	//apply the baud rate from the baudRate[][] array its row os the system clk
	//&its col is the  baud rate & the baudrate[][] array itself depend on the u2x ()
	u16 local_u16UBBRVal = baudRate[SYTEMOSCILLATOR][UART_u8BUDRATE];
	u8 local_u8UBRRVvalLow, local_u8UBRRVvalHigh;
	//extraxt the low 8bit of the   local_u16UBBRVal
	local_u8UBRRVvalLow = (local_u16UBBRVal);
	//extraxt the HIGH 8bti of the   local_u16UBBRVal
	local_u8UBRRVvalHigh = (local_u16UBBRVal >> EIGHTBBITS);
	//try to clr the register select in the ubbrh to choose ubbrh
	//not the ucsrc :)
	//and check that its realy cleared
	do {
		UART_u8UBRRH = Clrbit(UART_u8UBRRH, UART_u8UBRRH_URSEL);
	} while (GetBit(UART_u8UBRRH, UART_u8UBRRH_URSEL));
	//assign the val to UART_u8UBRRH
	UART_u8UBRRH = local_u8UBRRVvalHigh;
	//assign the val to UART_u8UBRRH
	//and clr the ursel bit
	UART_u8UBRRL = Clrbit(local_u8UBRRVvalLow, UART_u8UBRRH_URSEL);
	//Initializing the uart controll and status register (a,b,c)
	//initializing UCSRA
	UART_u8UCSRA = conc(0, 0, 0, 0, 0, 0, UART_u8u2x, 0);
	//initializing UCSRB
	UART_u8UCSRB = conc(UART_u8RXINTERUPTENABLE, UART_u8TXINTERUPTENABLE,
			UART_u8DATAEMPTYINTERUPTENABLE, UART_u8Ressiving,
			UART_u8Transmitting, UART_PROG_U8UCSZ2, 0, 0);
	//try to set the register select in the UART_u8UCSRC to choose UART_u8UCSRC
	//not the ubrrh :)
	//and check that its been set
	do {
		UART_u8UCSRC = Setbit(UART_u8UCSRC, UART_u8UCSRC_URSEL);
	} while (!GetBit(UART_u8UCSRC, UART_u8UCSRC_URSEL));
	//initializing UCSRC
	UART_u8UCSRC = conc(1, 0, UART_u8PARITY1, UART_u8PARITY0,
			UART_u8STOPBITSLOCAL, UART_PROG_U8UCSZ1, UART_PROG_U8UCSZ0, 0);
}
//preprosessor to chek if the UART_u8DATABITS <9
#if (UART_u8DATABITS==5||UART_u8DATABITS==6||UART_u8DATABITS==7||UART_u8DATABITS==8)
/*comment!:sending  8 bit UART_VoidSending is blocking Syncronus API */

extern void UART_VoidSending(u8 copy_u8ValToSend) {
	/* Wait for empty transmit buffer */
	while (!( UART_u8UCSRA & (1 << UART_u8UCSRARXC_UDRE)))
		;
	/* Put data into buffer, sends the data */
	UART_u8UDR = copy_u8ValToSend;
}
/*comment!:Resiving  8 bit UART_VoidResiving is blocking Syncronus API*/
extern void UART_VoidResiving(u8 *copy_u8ValToRecive){
	/* Wait for data to be received */
	while ( !(UART_u8UCSRA & (1<<UART_u8UCSRARXC_RXC)) ){}
	/* Get and return received data from buffer */
	*copy_u8ValToRecive=UART_u8UDR;
}
#elif UART_u8DATABITS==9
//TODO to Implement receiving and transmitting 9bit for future use
#endif
/*comment!: UART_voidFlushMemory is used to flush the UDR buffer */
extern void UART_voidFlushMemory(void){
	u8 local_u8dummy;
	//empty the ressiving buffer
	while ( UART_u8UCSRA & (1 << UART_u8UCSRARXC_RXC)) {
		local_u8dummy = UART_u8UDR;
	}

}
extern void UART_voidcheckfor_Interupts(u8 *copy_u8ptrto3Flags_RX_TX_EMPTY){

}
/*comment!:UART_voidwriteToUDR write directly to UDR for using it in ISR in high level   */
extern void UART_voidwriteToUDR(u8 copy_u8valToSend){

	UART_u8UDR=copy_u8valToSend;

}
/*comment!:UART_voidReadFromUDR to read  directly from UDR for using it in ISR in high level   */
extern void UART_voidReadFromUDR(u8 *copy_u8valInUDR){

	*copy_u8valInUDR=UART_u8UDR;
}


/*comment!: UART_voidSetTX_ISR call back function to set the ISR */

extern void UART_voidSetTX_ISR(void (*Copy_PtrToTXISR)(void))
{
	UART_TXInteruptPointer=Copy_PtrToTXISR;
}
/*comment!: UART_voidSetRX_ISR call back function to set the ISR */

extern void UART_voidSetRX_ISR(void (*Copy_PtrToRXISR)(void))
{
	UART_RXInteruptPointer=Copy_PtrToRXISR;
}

/*comment!: UART_voidSetBufferEmpty_ISR call back function to set the ISR */
extern void UART_voidSetBufferEmpty_ISR(void (*Copy_PtrToBufferEmptyISR)(void))
{
	UART_BufferEmptyInteruptPointer=Copy_PtrToBufferEmptyISR;
}




/*******************************************************************/
/****************  Private API**************************************/
/*******************************************************************/
//reciver
ISR(__vector_13) {
	UART_RXInteruptPointer();
}
//udr
ISR(__vector_14) {
	UART_BufferEmptyInteruptPointer();
}
//transmiter
ISR(__vector_15) {
	UART_TXInteruptPointer();
}


