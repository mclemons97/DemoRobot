/*
 * LCD2004.h
 *
 *  Created on: Nov 3, 2016
 *      Author: admin
 */

#ifndef SRC_LCD2004_H_
#define SRC_LCD2004_H_



 int LCD_CLEARDISPLAY = 0x01;
	 int LCD_RETURNHOME = 0x02;
	 int LCD_ENTRYMODESET = 0x04;
	 int LCD_DISPLAYCONTROL = 0x08;
	 int LCD_CURSORSHIFT = 0x10;
	 int LCD_FUNCTIONSET = 0x20;
	 int LCD_SETCGRAMADDR = 0x40;
	 int LCD_SETDDRAMADDR = 0x80;

	// Flags for display on/off control
	 int LCD_DISPLAYON = 0x04;
	 int LCD_DISPLAYOFF = 0x00;
	 int LCD_CURSORON = 0x02;
	 int LCD_CURSOROFF = 0x00;
	 int LCD_BLINKON = 0x01;
	 int LCD_BLINKOFF = 0x00;

	// Flags for display entry mode
	//  int LCD_ENTRYRIGHT = 0x00;
	 int LCD_ENTRYLEFT = 0x02;
	 int LCD_ENTRYSHIFTINCREMENT = 0x01;
	 int LCD_ENTRYSHIFTDECREMENT = 0x00;

	// Flags for display/cursor shift
	 int LCD_DISPLAYMOVE = 0x08;
	 int LCD_CURSORMOVE = 0x00;
	 int LCD_MOVERIGHT = 0x04;
	 int LCD_MOVELEFT = 0x00;

	// flags for function set
	 int LCD_8BITMODE = 0x10;
	 int LCD_4BITMODE = 0x00;
	 int LCD_2LINE = 0x08;	//for 2 or 4 lines actually
	 int LCD_1LINE = 0x00;
	 int LCD_5x10DOTS = 0x04;	//seldom used!!
	 int LCD_5x8DOTS = 0x00;

	// flags for backlight control
	 int LCD_BACKLIGHT = 0x08;
	 int LCD_NOBACKLIGHT = 0x00;

	//bitmasks for register control
	 int En = 0b00000100; // Enable bit
	 int Rw = 0b00000010; // Read/Write bit
	 int Rs = 0b00000001; // Register select bit


#endif /* SRC_LCD2004_H_ */
