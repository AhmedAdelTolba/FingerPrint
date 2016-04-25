#include"../../../Shared_Libraries/Types.h"
#include "../../../MCAL/DIO/DIO_CODE/DIO_interface.h"
#include "../LCD_CODE/LCD_Interface.h"
#include"../../../Shared_Libraries/delay.h"

int main(void)
    {

    DIO_VoidInit();
    LCD_VoidInit();

    while (1)
	{

	LCD_VoidString((u8*)"Nadine");
	Delay_ms_Max1s(500);
	LCD_VoidClearScreen();
	LCD_VoidString((u8*) "Adel");
	Delay_ms_Max1s(500);
	LCD_VoidClearScreen();
	LCD_VoidString((u8*) "Menshawy");
	Delay_ms_Max1s(500);
	LCD_VoidClearScreen();
	LCD_VoidString((u8*) "youssef");
	Delay_ms_Max1s(500);
	LCD_VoidClearScreen();
	LCD_VoidString((u8*) "Marim");
	Delay_ms_Max1s(500);
	LCD_VoidClearScreen();

	}

    return 0;
    }
