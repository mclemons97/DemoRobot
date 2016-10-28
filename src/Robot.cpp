#include "WPILib.h"

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
	RobotDrive myRobot; // robot drive system
	Joystick stick; // only joystick

public:
	Robot() :
			myRobot(9, 8, 7, 6), //fl, fr, rl, rr
			stick(0)		// as they are declared above.
	{
		//Note SmartDashboard is not initialized here, wait until RobotInit to make SmartDashboard calls
		myRobot.SetExpiration(0.1);//
	}

	void RobotInit()
	{
	}
	void Autonomous()
	{

	}

	/**
	 * Runs the motors with arcade steering.
	 */
	void OperatorControl()
	{
		myRobot.SetSafetyEnabled(true);
		while (IsOperatorControl() && IsEnabled())
		{
			if(abs(stick.GetRawAxis(4))>0.15)//left trigger
			{
				myRobot.Drive(1.0,-1.0);//turn left
			}
			if(abs(stick.GetRawAxis(5))>0.15)//right trigger
			{
				myRobot.Drive(1.0,1.0);//turn right
			}
			else
			{
				myRobot.MecanumDrive_Cartesian(stick.GetRawAxis(4), -1*stick.GetRawAxis(5),0); // drive with arcade style (use right stick)
			}
			Wait(0.005);				// wait for a motor update time

			}
	}

	/**
	 * Runs during test mode
	 */
	void Test()
	{
	}
};

START_ROBOT_CLASS(Robot)
