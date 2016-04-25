/*
 * LCD_Interface.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */

#ifndef LCD_INTERFACE_C_
#define LCD_INTERFACE_C_
/*
 * CG ROM : this the memory which holds the permanent fonts you call to be displayed .
 * this holds the pattern for every single character of  predefined lcd font.
 * and you call the content of this memory by the placeing  corresponding ascii value on the lcd port .
 * like for retrieval of   'A' you have to send the ascii value of 'A' which is 0x41 to the lcd.
 *********************************************************************************************************************
 * DD RAM : DDRAM is the memory which holds only those characters which are currently on the screen .
 * means if there is a message is currently being displayed on the screen then it has to be  on the DDRAM
 * for example if you want to display "hello" on the screen then you have load pattern of h from the CG ROM TO DD RAM
 * then do the same for 'e' ,'l' ,'l' and 'o'.
 *
 *********************************************************************************************************************
 * Register Selector
	RS		R/W
	0		0		Sends a command to LCD
	0		1		Read busy flag (DB7) and address counter (DB0 to DB6)
	1		0		Sends information to LCD
	1		1		Reads information from LCD
 *
 * */
extern void LCD_extern_voidCmd (u8 LCD_u8Command);/*send command to LCd */
extern void LCD_extern_voidData(u8 LCD_u8Data);/*send Data to LCd */
extern void LCD_VoidInit( void);/*to init lcd*/
extern void LCD_VoidString(u8 *LCD_u8Ptr);/*Display String on lcd*/
extern u16* LCD_u16ReturnString(u16 inputValue);/*it will convert from decimal to string*/
extern void LCD_extern_voidSendStringxy(u8 *LCD_u8str,u8 LCD_u8x,u8 LCD_u8y);//("aktb ely 3aizo",rkm anhih 7th fy el3mod ,rkm el sf)
extern void LCD_extern_voidGotoxy(u8 LCD_u8x,u8 LCD_u8y);//(rkm el3mod,rkm elsf)
extern void LCD_extern_voidRowString (u8 LCD_u8row,u8 *LCD_u8String);//(rkm el sf,"el2sm ely 3ais tktbo")
extern void LCD_extern_voidRow(u8 LCD_u8no);//elsf elawl wla eltany
extern void LCD_VoidClearScreen( void);//clear Lcd

extern void LCD_EnableLcd(void);
extern void LCD_WaitLcd(void);

#endif /* LCD_INTERFACE_C_ */
