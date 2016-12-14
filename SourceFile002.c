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
task main()
{
	while(true)
	{
		getJoystickSettings(joystick);

		if(joystick. joy1_TopHat == 0)
		{
			motor[motorLF] = 50;
			motor[motorLM] = 50;
			motor[motorLB] = 50;

			motor[motorRF] = 50;
			motor[motorRM] = 50;
			motor[motorRB] = 50;
		} else
		if(joystick. joy1_TopHat == 4)
		{
			motor[motorLF] = -50;
			motor[motorLM] = -50;
			motor[motorLB] = -50;

			motor[motorRF] = -50;
			motor[motorRM] = -50;
			motor[motorRB] = -50;
		}	else
		if(joystick. joy1_TopHat == 6)
		{
			motor[motorLF] = -50;
			motor[motorLM] = -50;
			motor[motorLB] = -50;

			motor[motorRF] = 50;
			motor[motorRM] = 50;
			motor[motorRB] = 50;
		} else
		if(joystick. joy1_TopHat == 2)
		{
			motor[motorLF] = 50;
			motor[motorLM] = 50;
			motor[motorLB] = 50;

			motor[motorRF] = -50;
			motor[motorRM] = -50;
			motor[motorRB] = -50;
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
