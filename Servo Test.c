#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Hubs,  S2, HTServo,  none,     none,     none)
#pragma config(Hubs,  S3, HTMotor,  HTMotor,  none,     none)
#pragma config(Motor,  mtr_S1_C1_1,     motorRF,       tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     NoMotor,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motorRM,       tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_2,     motorRB,       tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S3_C1_1,     motorLF,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C1_2,     motorTurnCam,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C2_1,     motorLM,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C2_2,     motorLB,       tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S2_C1_1,    servoTiltCam,         tServoStandard)
#pragma config(Servo,  srvo_S2_C1_2,    servoRF,              tServoStandard)
#pragma config(Servo,  srvo_S2_C1_3,    servoLF,              tServoStandard)
#pragma config(Servo,  srvo_S2_C1_4,    servoRB,              tServoStandard)
#pragma config(Servo,  srvo_S2_C1_5,    servoLB,              tServoStandard)
#pragma config(Servo,  srvo_S2_C1_6,    NoServo,              tServoStandard)
#include "JoystickDriver.c"
void turnconfig()
{
	servo[servoLF] = 36;
	servo[servoLB] = 208;
	servo[servoRF] = 216;
	servo[servoRB] = 48;
}
void LeftTurn()
{
	turnconfig();

	wait10Msec(10);

	motor[motorLF] = -100;
	motor[motorLM] = -100;
	motor[motorLB] = -100;

	motor[motorRF] = 100;
	motor[motorRM] = 100;
	motor[motorRB] = 100;
}
void RightTurn()
{
	turnconfig();

	wait10Msec(10);

	motor[motorLF] = 100;
	motor[motorLM] = 100;
	motor[motorLB] = 100;

	motor[motorRF] = -100;
	motor[motorRM] = -100;
	motor[motorRB] = -100;
}
void StraightConfig()
{
	servo[servoLF] = 128;
	servo[servoLB] = 128;
	servo[servoRF] = 128;
	servo[servoRB] = 128;
}
void GoForward()
{
	StraightConfig();

	motor[motorLF] = 100;
	motor[motorLM] = 100;
	motor[motorLB] = 100;

	motor[motorRF] = 100;
	motor[motorRM] = 100;
	motor[motorRB] = 100;
}
void GoBackward()
{
	StraightConfig();
	motor[motorLF] = -100;
	motor[motorLM] = -100;
	motor[motorLB] = -100;

	motor[motorRF] = -100;
	motor[motorRM] = -100;
	motor[motorRB] = -100;
}
task main()
{
	while(true)
	{
		getJoystickSettings(joystick);

		if(joystick.joy1_TopHat = 2)
		{
			RightTurn();
		}
		if(joystick.joy1_TopHat = 6)
		{
			LeftTurn();
		}
				if(joystick.joy1_TopHat = 4)
		{
			GoBackward();
		}
		if(joystick.joy1_TopHat = 0)
		{
			GoForward();
		}
		if(joystick.joy1_TopHat = -1)
		{
			motor[motorLF] = 0;
			motor[motorLM] = 0;
			motor[motorLB] = 0;

			motor[motorRF] = 0;
			motor[motorRM] = 0;
			motor[motorRB] = 0;
		}
		else
		{
			motor[motorLF] = 0;
			motor[motorLM] = 0;
			motor[motorLB] = 0;

			motor[motorRF] = 0;
			motor[motorRM] = 0;
			motor[motorRB] = 0;
		}
	}
}
