/*
 * LCD_Prog.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/*Comment:Choose control Pins of lcd */
/*Range : DIO_u8PIN(0~31)*/
#define LCD_u8Reset			DIO_u8PIN24
#define LCD_u8ReadWrite		DIO_u8PIN25
#define LCD_u8Enable		DIO_u8PIN26

/*Comment:Choose control Pins of lcd */
/*Range : LCD_u8Bit8 and LCD_u8Bit4*/
#define LCD_u8LcdMode			LCD_u8Bit8

/*Comment:Choose Data Pins of lcd */
/*Range : DIO_u8PIN(0~31)*/
/* in 4 bit mode must connect D7 in lcd and arrange of DIO_u8PIN from smaller to bigger(01234)*/
/*in any mode lcd_D7 must be last pin*/
#define LCD_u8D0			DIO_u8PIN16
#define LCD_u8D1			DIO_u8PIN17
#define LCD_u8D2			DIO_u8PIN18
#define LCD_u8D3			DIO_u8PIN19
#define LCD_u8D4			DIO_u8PIN20
#define LCD_u8D5			DIO_u8PIN21
#define LCD_u8D6			DIO_u8PIN22
#define LCD_u8D7			DIO_u8PIN23

/***********************4 bit***************************************/
//#define LCD_u8LcdMode			LCD_u8Bit4

//#define LCD_u8D0			DIO_u8Pin4
//#define LCD_u8D1			DIO_u8Pin5
//#define LCD_u8D2			DIO_u8Pin6
//#define LCD_u8D3			DIO_u8Pin7
//#define LCD_u8D4			DIO_u8Pin4
//#define LCD_u8D5			DIO_u8Pin5
//#define LCD_u8D6			DIO_u8Pin6
//#define LCD_u8D7			DIO_u8Pin7

/***************************8 bit******************************************/
//#define LCD_u8LcdMode			LCD_u8Bit8
//
//#define LCD_u8D0			DIO_u8Pin0
//#define LCD_u8D1			DIO_u8Pin1
//#define LCD_u8D2			DIO_u8Pin2
//#define LCD_u8D3			DIO_u8Pin3
//#define LCD_u8D4			DIO_u8Pin4
//#define LCD_u8D5			DIO_u8Pin5
//#define LCD_u8D6			DIO_u8Pin6
//#define LCD_u8D7			DIO_u8Pin7

#endif /* LCD_CONFIG_H_ */
