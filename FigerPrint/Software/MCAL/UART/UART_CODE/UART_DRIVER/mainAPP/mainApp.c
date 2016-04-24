/*
 * mainApp.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: mahmoud
 */
#include"../headerfiles/types.h"
#include"../headerfiles/UART/UART_Interface.h"
#include"../headerfiles/DelayFiles/Delay_prog.c"
int main (void)
{
	u8 local_u8sendAndReciving=0x55;
	UART_VoidInit();
while(1){
	UART_VoidSending(local_u8sendAndReciving);
	UART_VoidResiving(&local_u8sendAndReciving);
	Delay(200);

}//end of while loop
return 0;
}//end of main
