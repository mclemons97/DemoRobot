#include "WPILib.h"
#include "LCD2004.h"
/**
 * This is a demo program showing the use of the RobotDrive class.
 * The SampleRobot class is the base of a robot application that will automatically call your
 * Autonomous and OperatorControl methods at the right time as controlled by the switches on
 * the driver station or the field controls.
 *
 * WARNING: While it may look like a good choice to use for your code if you're inexperienced,
 * don't. Unless you know what you are doing, complex code will be much more difficult under
 * this system. Use IterativeRobot or Command-Based instead if you're new.
 */
class Robot: public SampleRobot
{

	Joystick stick; // only joystick
	I2C *LCDDisplay;


public:
	Robot() :

			stick(0)
			//LCDDisplay(I2C::Port::kOnboard, 0x27)

	{
		//Note SmartDashboard is not initialized here, wait until RobotInit to make SmartDashboard calls
		LCDDisplay = new I2C(I2C::Port::kOnboard, 0x3F);// 0x3f
		//initLCD();
	}
	void RobotInit()
	{
		initLCD();
	}
		void initLCD() {

			LCDwriteCMD(0x03);
			LCDwriteCMD(0x03);
			LCDwriteCMD(0x03);
			LCDwriteCMD(0x02);
			//4 bit mode??? -- yes. Always. It's the default way of doing this for LCD displays
			LCDwriteCMD( LCD_FUNCTIONSET | LCD_2LINE | LCD_5x8DOTS | LCD_4BITMODE );
			LCDwriteCMD( LCD_DISPLAYCONTROL | LCD_DISPLAYON );
			LCDwriteCMD( LCD_CLEARDISPLAY );
			LCDwriteCMD( LCD_ENTRYMODESET | LCD_ENTRYLEFT );
			zsleep(10);
		}
		void zsleep(int t) //time in ms
		{
		Wait(t);
		}
		void LCDwriteCMD (int data) {
			LCD_rawWrite(data & 0xF0);
			LCD_rawWrite((data <<4 ) & 0xF0);
		}
		void LCDwriteChar ( int data) {
			LCD_rawWrite( Rs |  (data & 0xF0));
			LCD_rawWrite( Rs | ((data <<4 ) & 0xF0));
		}
		void LCD_rawWrite( int data) {
			LCDDisplay->Write(0, data | LCD_BACKLIGHT );
			strobe(data);
		}
		void strobe(int data){
			//    	Syntax: lcdDisplay.write(reg,data);
			LCDDisplay->Write(0, data | En | LCD_BACKLIGHT );
			zsleep(1);
			LCDDisplay->Write(0, (data & ~En) | LCD_BACKLIGHT );
			zsleep(1);
		}
		void LCDwriteString(std::string s, int line) {
				switch (line) {
				case 1: LCDwriteCMD(0x80); break;
				case 2: LCDwriteCMD(0xC0); break;
				case 3: LCDwriteCMD(0x94); break;
				case 4: LCDwriteCMD(0xD4); break;
				default: return;	//invalid line number does nothing.
				}
		}
	void Autonomous()
	{
		while(IsAutonomous()&&IsEnabled())
		{


		}
	}
	void OperatorControl()
	{

	}
	void Test()
	{
		LCDwriteCMD(LCD_CLEARDISPLAY);
		LCDwriteString("test",1);
		Wait(1.0);
		LCDwriteString("test",2);
		Wait(1.0);
		LCDwriteString("test",3);
		Wait(1.0);
		LCDwriteString("test",4);
		Wait(1.0);//wait so no refresh
	}
};

START_ROBOT_CLASS(Robot)
