/*
 * LCD_Prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */
#include "../../../Shared_Libraries/Types.h"
#include "../../../Shared_Libraries/delay.h"
#include "LCD_Private.h"
#include "LCD_Config.h"
#include "LCD_interface.h"
#include "../../../MCAL/DIO/DIO_CODE/DIO_interface.h"
/*****************************************************************/
void LCD_VoidCmd(u8 LCD_u8Command)
{
	//LCD_u8Port=LCD_u8Command;
	LCD_WaitLcd();
	#if (LCD_u8LcdMode == LCD_u8Bit8)
	DIO_u8WritePinVal(LCD_u8Reset,DIO_u8LOW );

	DIO_u8WritePinVal(LCD_u8D0,(LCD_u8Command&Lcd_u8Bit0 ));
	DIO_u8WritePinVal(LCD_u8D1,(LCD_u8Command&Lcd_u8Bit1 ));
	DIO_u8WritePinVal(LCD_u8D2,(LCD_u8Command&Lcd_u8Bit2 ));
	DIO_u8WritePinVal(LCD_u8D3,(LCD_u8Command&Lcd_u8Bit3 ));
	DIO_u8WritePinVal(LCD_u8D4,(LCD_u8Command&Lcd_u8Bit4 ));
	DIO_u8WritePinVal(LCD_u8D5,(LCD_u8Command&Lcd_u8Bit5 ));
	DIO_u8WritePinVal(LCD_u8D6,(LCD_u8Command&Lcd_u8Bit6 ));
	DIO_u8WritePinVal(LCD_u8D7,(LCD_u8Command&Lcd_u8Bit7 ));

	LCD_EnableLcd();

	//Delay_ms_Max1s(50);

	#else

	DIO_u8WritePinVal(LCD_u8Reset,DIO_u8LOW );

	//LCD_MaskLcdPins();

	DIO_u8WritePinVal(LCD_u8D0,(LCD_u8Command&Lcd_u8Bit4 )  );
	DIO_u8WritePinVal(LCD_u8D1,(LCD_u8Command&Lcd_u8Bit5 )  );
	DIO_u8WritePinVal(LCD_u8D2,(LCD_u8Command&Lcd_u8Bit6 )  );
	DIO_u8WritePinVal(LCD_u8D3,(LCD_u8Command&Lcd_u8Bit7 )  );

	LCD_EnableLcd();

	//LCD_MaskLcdPins();

	DIO_u8WritePinVal(LCD_u8D0,(LCD_u8Command&Lcd_u8Bit0 )   );
	DIO_u8WritePinVal(LCD_u8D1,(LCD_u8Command&Lcd_u8Bit1 )   );
	DIO_u8WritePinVal(LCD_u8D2,(LCD_u8Command&Lcd_u8Bit2 )   );
	DIO_u8WritePinVal(LCD_u8D3,(LCD_u8Command&Lcd_u8Bit3 )   );

	LCD_EnableLcd();

	//Delay_ms_Max1s(50);
	#endif

	return;
}
/*****************************************************************/
/*
void LCD_ClearLcd(void)
{
	LCD_VoidCmd(0x01);
}
*/
/*****************************************************************/
void LCD_EnableLcd(void)
{
	DIO_u8WritePinVal(LCD_u8Enable,DIO_u8HIGH );
	Delay_ms_Max1s(1);
	DIO_u8WritePinVal(LCD_u8Enable,DIO_u8LOW );
	Delay_ms_Max1s(1);
}
/*****************************************************************/

/*
 void //LCD_MaskLcdPins(void)
{
	DIO_u8WritePinVal(LCD_u8D0,DIO_u8LOW);
	DIO_u8WritePinVal(LCD_u8D1,DIO_u8LOW);
	DIO_u8WritePinVal(LCD_u8D2,DIO_u8LOW);
	DIO_u8WritePinVal(LCD_u8D3,DIO_u8LOW);
}
*/
/*****************************************************************/
void LCD_VoidData(u8 LCD_u8Data)
{
	LCD_WaitLcd();
	#if (LCD_u8LcdMode == LCD_u8Bit8)

	DIO_u8WritePinVal(LCD_u8Reset,DIO_u8HIGH );

	DIO_u8WritePinVal(LCD_u8D0,(LCD_u8Data&Lcd_u8Bit0 )  );
	DIO_u8WritePinVal(LCD_u8D1,(LCD_u8Data&Lcd_u8Bit1 )  );
	DIO_u8WritePinVal(LCD_u8D2,(LCD_u8Data&Lcd_u8Bit2 )  );
	DIO_u8WritePinVal(LCD_u8D3,(LCD_u8Data&Lcd_u8Bit3 )  );
	DIO_u8WritePinVal(LCD_u8D4,(LCD_u8Data&Lcd_u8Bit4 )  );
	DIO_u8WritePinVal(LCD_u8D5,(LCD_u8Data&Lcd_u8Bit5 )  );
	DIO_u8WritePinVal(LCD_u8D6,(LCD_u8Data&Lcd_u8Bit6 )  );
	DIO_u8WritePinVal(LCD_u8D7,(LCD_u8Data&Lcd_u8Bit7 )  );

	//ctrl = (1<<rs)|(0<<rw)|(1<<en); // RW as LOW and RS, EN as HIGH
	LCD_EnableLcd();
	//Delay_ms_Max1s(50); // delay to get things executed

	#else

	DIO_u8WritePinVal(LCD_u8Reset,DIO_u8HIGH );

	//LCD_MaskLcdPins();

	DIO_u8WritePinVal(LCD_u8D0,(LCD_u8Data&Lcd_u8Bit4 )   );
	DIO_u8WritePinVal(LCD_u8D1,(LCD_u8Data&Lcd_u8Bit5 )   );
	DIO_u8WritePinVal(LCD_u8D2,(LCD_u8Data&Lcd_u8Bit6 )   );
	DIO_u8WritePinVal(LCD_u8D3,(LCD_u8Data&Lcd_u8Bit7 )   );

	LCD_EnableLcd();

	//LCD_MaskLcdPins();

	DIO_u8WritePinVal(LCD_u8D0,(LCD_u8Data&Lcd_u8Bit0 )   );
	DIO_u8WritePinVal(LCD_u8D1,(LCD_u8Data&Lcd_u8Bit1 )   );
	DIO_u8WritePinVal(LCD_u8D2,(LCD_u8Data&Lcd_u8Bit2 )   );
	DIO_u8WritePinVal(LCD_u8D3,(LCD_u8Data&Lcd_u8Bit3 )   );

	LCD_EnableLcd();

	//Delay_ms_Max1s(50);
	#endif

	return ;
}
/*****************************************************************/
void LCD_WaitLcd(void)
{
	u8 Local_u8ValBusyFlag;
	#if (LCD_u8LcdMode == LCD_u8Bit4)

	DIO_u8WritePinDir(LCD_u8D0,DIO_u8INPUT);//lcdd7=i/p .
	DIO_u8WritePinDir(LCD_u8D1,DIO_u8INPUT);//lazm el 4 yb2o i/p 3shan ama b2lb enable mn high l low bib3t lcd btb3t high
	DIO_u8WritePinDir(LCD_u8D2,DIO_u8INPUT);//lazm el 4 yb2o i/p 3shan ama b2lb enable mn high l low bib3t lcd btb3t high
	DIO_u8WritePinDir(LCD_u8D3,DIO_u8INPUT);//lazm el 4 yb2o i/p 3shan ama b2lb enable mn high l low bib3t lcd btb3t high
	DIO_u8WritePinVal(LCD_u8ReadWrite,DIO_u8HIGH);//rw=1.
	#elif (LCD_u8LcdMode == LCD_u8Bit8)
	DIO_u8WritePinDir(LCD_u8D0,DIO_u8INPUT);
	DIO_u8WritePinDir(LCD_u8D1,DIO_u8INPUT);
	DIO_u8WritePinDir(LCD_u8D2,DIO_u8INPUT);
	DIO_u8WritePinDir(LCD_u8D3,DIO_u8INPUT);
	DIO_u8WritePinDir(LCD_u8D4,DIO_u8INPUT);
	DIO_u8WritePinDir(LCD_u8D5,DIO_u8INPUT);
	DIO_u8WritePinDir(LCD_u8D6,DIO_u8INPUT);
	DIO_u8WritePinDir(LCD_u8D7,DIO_u8INPUT);
	DIO_u8WritePinVal(LCD_u8ReadWrite,DIO_u8HIGH);//rw=1.
	#endif
	DIO_u8WritePinVal(LCD_u8Reset,DIO_u8LOW);//rs=0.
	do
	{
		Local_u8ValBusyFlag=0;
		DIO_u8WritePinVal(LCD_u8Enable,DIO_u8HIGH);//Enable=1.
		Delay_ms_Max1s(1);
		#if (LCD_u8LcdMode == LCD_u8Bit4)
		DIO_u8ReadPinVal(LCD_u8D3,&Local_u8ValBusyFlag );
		#elif (LCD_u8LcdMode == LCD_u8Bit8)
		DIO_u8ReadPinVal(LCD_u8D7,&Local_u8ValBusyFlag );
		#endif
		Delay_ms_Max1s(1);
		DIO_u8WritePinVal(LCD_u8Enable,DIO_u8LOW);//e=0.
		Delay_ms_Max1s(1);

		DIO_u8WritePinVal(LCD_u8Enable,DIO_u8HIGH);//e=1
		Delay_ms_Max1s(1);
	}while(Local_u8ValBusyFlag == LCD_u8Busy);
	DIO_u8WritePinVal(LCD_u8ReadWrite,DIO_u8LOW);//rw=0.

	#if (LCD_u8LcdMode == LCD_u8Bit4)
	DIO_u8WritePinDir(LCD_u8D0,DIO_u8OUTPUT);
	DIO_u8WritePinDir(LCD_u8D1,DIO_u8OUTPUT);
	DIO_u8WritePinDir(LCD_u8D2,DIO_u8OUTPUT);
	DIO_u8WritePinDir(LCD_u8D3,DIO_u8OUTPUT);
	Delay_ms_Max1s(1);
	#elif (LCD_u8LcdMode == LCD_u8Bit8)
	DIO_u8WritePinDir(LCD_u8D0,DIO_u8OUTPUT);
	DIO_u8WritePinDir(LCD_u8D1,DIO_u8OUTPUT);
	DIO_u8WritePinDir(LCD_u8D2,DIO_u8OUTPUT);
	DIO_u8WritePinDir(LCD_u8D3,DIO_u8OUTPUT);
	DIO_u8WritePinDir(LCD_u8D4,DIO_u8OUTPUT);
	DIO_u8WritePinDir(LCD_u8D5,DIO_u8OUTPUT);
	DIO_u8WritePinDir(LCD_u8D6,DIO_u8OUTPUT);
	DIO_u8WritePinDir(LCD_u8D7,DIO_u8OUTPUT);
	#endif
}
/*****************************************************************/
void LCD_VoidInit(void)
{

	#if (LCD_u8LcdMode == LCD_u8Bit8)
	LCD_VoidCmd(0x38); // initialization of 16X2 LCD in 8bit mode
	Delay_ms_Max1s(20);

	LCD_VoidCmd(0x01); // clear LCD
	Delay_ms_Max1s(1);

	LCD_VoidCmd(0x0C); // cursor Off// Automatic Increment – No Display shift.
	Delay_ms_Max1s(1);

	LCD_VoidCmd(0x80); // --- go to first line and --0 is for 0th position
	Delay_ms_Max1s(1);
	#else
	LCD_VoidCmd(0x33);       //to initialize LCD in 2 lines, 5X7 dots and 4bit mode.
	Delay_ms_Max1s(20);
	LCD_VoidCmd(0x32);       // Display no cursor – no blink.
	Delay_ms_Max1s(10);
	LCD_VoidCmd(0x28);       // Automatic Increment – No Display shift.
	LCD_VoidCmd(0x0c);       // Address DDRAM with 0 offset 80h.
	LCD_VoidCmd(0x06);
	Delay_ms_Max1s(1);
	LCD_VoidCmd(0x01);
	Delay_ms_Max1s(1);
	#endif

	return;
}
/*****************************************************************/
void LCD_VoidString(u8 *LCD_u8Ptr)
{
	while(*LCD_u8Ptr)
	{
		LCD_VoidData(*LCD_u8Ptr++);
	}
	return;
}
/*********************************************************************************************/

void LCD_VoidRow(u8 LCD_u8no)//elsf elawl wla eltany
{
	if (LCD_u8no == 1)
	{
		LCD_VoidCmd(0x80); // sf awl
	}
	if (LCD_u8no ==2)
	{
		LCD_VoidCmd(0xC0); //sf tany
	}
}
/*********************************************************************************************/

void LCD_VoidRowString (u8 LCD_u8row,u8 *LCD_u8String) //(rkm el sf,"el2sm ely 3ais tktbo")
{
	LCD_VoidRow(LCD_u8row);
	///*
	 while (*LCD_u8String)
	{
		LCD_VoidData(*LCD_u8String++);
	}
	//*/
	//LCD_VoidString(LCD_u8String);
}
/*********************************************************************************************/

void LCD_VoidGotoxy(u8 LCD_u8x,u8 LCD_u8y)//(rkm el3mod,rkm elsf)
 {
    if(LCD_u8y == 1)
    {
        LCD_VoidCmd(0x80+LCD_u8x);
    }
     else
     {
        LCD_VoidCmd(0xc0+LCD_u8x);
     }
 }
/*********************************************************************************************/

void LCD_VoidSendStringxy(u8 *LCD_u8str,u8 LCD_u8x,u8 LCD_u8y)//("aktb ely 3aizo",rkm anhih 7th fy el3mod ,rkm el sf)
{
     LCD_VoidGotoxy(LCD_u8x,LCD_u8y);
     LCD_VoidString(LCD_u8str);
}
/*********************************************************************************************/

void LCD_VoidClearScreen(void)
{
	LCD_VoidCmd(0x01);
}
/*********************************************************************************************/

u16* LCD_u16ReturnString(u16 inputValue)
{
    static u16 Local_u16ProcessedString[5]; // Return a string of 3 digits.
    u8 Local_u8Counter=0; // Brute-force counter for first digit.

    if (inputValue < 99)
    {
    	Local_u16ProcessedString[Local_u8Counter++]=inputValue / 10 +'0'; //first number
    	Local_u16ProcessedString[Local_u8Counter++]=inputValue % 10 +'0';//Second number
    }
    else if (inputValue < 999)
    {
    	Local_u16ProcessedString[Local_u8Counter++]=(inputValue / 100) +'0'; //first number
    	Local_u16ProcessedString[Local_u8Counter++]=((inputValue / 10) % 10) +'0';//Second number
    	Local_u16ProcessedString[Local_u8Counter++]=inputValue % 10 +'0';//Third number
    }
    else if (inputValue < 1024)
    {
    	Local_u16ProcessedString[Local_u8Counter++]='1'; //first number
    	Local_u16ProcessedString[Local_u8Counter++]='0'; //Second number
    	Local_u16ProcessedString[Local_u8Counter++]=((inputValue / 10) % 10) +'0';//Third number
    	Local_u16ProcessedString[Local_u8Counter++]=inputValue % 10 +'0';//Forth number
    }
    else;//nothing

    Local_u16ProcessedString[Local_u8Counter]='\0';//last number
    return Local_u16ProcessedString; // Return the processed string.
}

