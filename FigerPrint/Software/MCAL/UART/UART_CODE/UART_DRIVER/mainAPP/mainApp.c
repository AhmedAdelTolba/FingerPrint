/*
 * mainApp.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: mahmoud
 */
#include"../headerfiles/types.h"
#include"../headerfiles/UART/UART_Interface.h"
#include"../headerfiles/DelayFiles/Delay_prog.c"
#include "../headerfiles/InteruptVector.h"
//for tx Interupt testing only
#define PORTA                     *((volatile u8*)(0x3B))
#define DDRA                      *((volatile u8*)(0x3A))
void txINT(void){
	static u8 local_u8oldVal=0xff;
	local_u8oldVal^=0xff;
	PORTA=local_u8oldVal;
}
void RxINT(void){
	 u8 local_u8sendAndReciving;
	UART_voidReadFromUDR(&local_u8sendAndReciving);
	UART_voidwriteToUDR(local_u8sendAndReciving);
}
int main (void)
{
	DDRA=0xff;
	UART_voidSetRX_ISR(RxINT);
	UART_voidSetTX_ISR( txINT);
	UART_VoidInit();
	INTERUPTVECTOR_SETGLOPALINTERUPT;
while(1){
    	//UART_VoidSending(local_u8sendAndReciving);
	//UART_VoidResiving(&local_u8sendAndReciving);
	Delay(200);

}//end of while loop
return 0;
}//end of main
