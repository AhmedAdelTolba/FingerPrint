#include "../../../MCAL/DIO/DIO_CODE/DIO_interface.h"
#include "../LCD_CODE/LCD_Interface.h"
const u8 Name_n[6]={'n','a','d','i','n','e'};
const u8 Name_a[4]={'a','d','e','l'};
const u8 Name_m[8]={'m','e','n','s','h','a','w','y'};
const u8 Name_ma[6]={'m','a','r','i','a','m'};
const u8 Name_y[7]={'y','o','u','s','s','e','f'};


void main(void)
{

	DIO_VoidInit();
	voidInit( void);


while(1)
{

	LCD_VoidString("nadine");
	LCD_VoidClearScreen();
	LCD_VoidString("mariam");
	LCD_VoidClearScreen();
	LCD_VoidString("adel");
	LCD_VoidClearScreen();
	LCD_VoidString("youssef");
	LCD_VoidClearScreen();
	LCD_VoidString("menshawy");
	LCD_VoidClearScreen();

}
}
