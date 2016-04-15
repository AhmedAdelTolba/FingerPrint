/*
 * DIO_prog.c

 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */
#include "../../../Shared_Libraries/Types.h"
#include "../../../Shared_Libraries/delay.h"
#include "../../../Shared_Libraries/DIO-utilites.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

static volatile u8* const DIO_u8RWDirArr[DIO_u8PORTNUMBERS] = { DDRA, DDRB,
DDRC, DDRD };
static volatile u8* const DIO_u8ReadPortArr[DIO_u8PORTNUMBERS] = { PINA, PINB,
PINC, PIND };
static volatile u8* const DIO_u8WritePortArr[DIO_u8PORTNUMBERS] = { PORTA,
PORTB, PORTC, PORTD };

void DIO_voidInit(void) {
	*DDRA |= DIO_u8PORTA_DIR;
	*DDRB |= DIO_u8PORTB_DIR;
	*DDRC |= DIO_u8PORTC_DIR;
	*DDRD |= DIO_u8PORTD_DIR;

	*PORTA = (*PORTA & ~DIO_u8PORTA_DIR) | (DIO_u8PORTA_DIR & DIO_u8PORTA_VAL);
	*PORTB = (*PORTB & ~DIO_u8PORTB_DIR) | (DIO_u8PORTB_DIR & DIO_u8PORTB_VAL);
	*PORTC = (*PORTC & ~DIO_u8PORTC_DIR) | (DIO_u8PORTC_DIR & DIO_u8PORTC_VAL);
	*PORTD = (*PORTD & ~DIO_u8PORTD_DIR) | (DIO_u8PORTD_DIR & DIO_u8PORTD_VAL);

	return;
}

u8 DIO_u8ReadPortDir(u8 Copy_u8PortIdx, u8* Copy_u8PtrToDir) {
	u8 Local_u8ReturnFlag = OK;
	if (Copy_u8PortIdx > DIO_u8PORTNUMBERS - 1 || Copy_u8PortIdx < 0) {
		Local_u8ReturnFlag = ERROR;
	} else {
		*Copy_u8PtrToDir = *DIO_u8RWDirArr[Copy_u8PortIdx];
		Local_u8ReturnFlag = OK;
	}
	return Local_u8ReturnFlag;

}

u8 DIO_u8WritePortDir(u8 Copy_u8PortIdx, u8 Copy_u8PortDir) {

	u8 Local_u8ReturnFlag = OK;
	if (Copy_u8PortIdx > DIO_u8PORTNUMBERS - 1 || Copy_u8PortIdx < 0) {
		Local_u8ReturnFlag = ERROR;
	} else {
		*DIO_u8RWDirArr[Copy_u8PortIdx] = Copy_u8PortDir;
		Local_u8ReturnFlag = OK;
	}
	return Local_u8ReturnFlag;

}

u8 DIO_u8ReadPortVal(u8 Copy_u8PortIdx, u8* Copy_u8PtrToVal) {

	u8 Local_u8ReturnFlag = OK;
	if (Copy_u8PortIdx > DIO_u8PORTNUMBERS - 1 || Copy_u8PortIdx < 0) {
		Local_u8ReturnFlag = ERROR;
	} else {
		*Copy_u8PtrToVal = *DIO_u8ReadPortArr[Copy_u8PortIdx];
		Local_u8ReturnFlag = OK;
	}
	return Local_u8ReturnFlag;

}

u8 DIO_u8WritePortVal(u8 Copy_u8PortIdx, u8 Copy_u8PortVal) {

	u8 Local_u8ReturnFlag = OK;
	if (Copy_u8PortIdx > DIO_u8PORTNUMBERS - 1 || Copy_u8PortIdx < 0) {
		Local_u8ReturnFlag = ERROR;
	} else {
		*DIO_u8WritePortArr[Copy_u8PortIdx] = Copy_u8PortVal;
		Local_u8ReturnFlag = OK;
	}
	return Local_u8ReturnFlag;
}
u8 DIO_u8ReadPinDir(u8 Copy_u8ChIdx, u8* Copy_u8PtrToDir) {
	u8 Local_u8ReturnFlag = OK;
	if (Copy_u8ChIdx > DIO_u8PINNUMBERS - 1 || Copy_u8ChIdx < 0) {
		Local_u8ReturnFlag = ERROR;
	} else {

		*Copy_u8PtrToDir = GET_BIT(*DIO_u8RWDirArr[Copy_u8ChIdx/DIO_u8PORTSIZE],
				(Copy_u8ChIdx%DIO_u8PORTSIZE));
		Local_u8ReturnFlag = OK;
	}

	return Local_u8ReturnFlag;

}
u8 DIO_u8WritePinDir(u8 Copy_u8ChIdx, u8 Copy_u8PinDir) {
	u8 Local_u8ReturnFlag = OK;
	if (Copy_u8ChIdx > DIO_u8PINNUMBERS - 1 || Copy_u8ChIdx < 0) {
		Local_u8ReturnFlag = ERROR;
	} else {
		ASSIGN_BIT(*DIO_u8RWDirArr[Copy_u8ChIdx/DIO_u8PORTSIZE],
				(Copy_u8ChIdx%DIO_u8PORTSIZE), Copy_u8PinDir);
		Local_u8ReturnFlag = OK;
	}

	return Local_u8ReturnFlag;
}

u8 DIO_u8ReadPinVal(u8 Copy_u8ChIdx, u8* Copy_u8PtrToVal) {
	u8 Local_u8ReturnFlag = OK;
	if (Copy_u8ChIdx > DIO_u8PINNUMBERS - 1 || Copy_u8ChIdx < 0) {
		Local_u8ReturnFlag = ERROR;
	} else {

		*Copy_u8PtrToVal = GET_BIT(
				*DIO_u8ReadPortArr[Copy_u8ChIdx/DIO_u8PORTSIZE],
				(Copy_u8ChIdx%DIO_u8PORTSIZE));
		Local_u8ReturnFlag = OK;
	}

	return Local_u8ReturnFlag;
}

extern u8 DIO_u8WritePinVal(u8 Copy_u8PinIdx,u8 Copy_u8PinToVal )
{
		u8 Local_u8Status,Local_u8Port,Local_u8Pin;
		if(Copy_u8PinIdx < 32)
		{
			Local_u8Port=Copy_u8PinIdx / 8;
			Local_u8Pin= Copy_u8PinIdx % 8;
			if(Copy_u8PinToVal==DIO_u8LOW)
			{
				Clr_Bit(*DIO_u8WritePortArr[Local_u8Port],Local_u8Pin);
			}
			else
			{
				Set_Bit(*DIO_u8WritePortArr[Local_u8Port],Local_u8Pin);
			}
			Local_u8Status=Ok;
		}
		else
		{
			Local_u8Status=Error;
		}
		return Local_u8Status;

}
