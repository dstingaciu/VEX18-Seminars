#pragma config(Sensor, dgtl11, driveE,         sensorQuadEncoder)
#pragma config(Motor,  port1,           Ldrive,        tmotorVex393HighSpeed_HBridge, openLoop, reversed)
#pragma config(Motor,  port10,          Rdrive,        tmotorVex393HighSpeed_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define wheelDiameter 3.25;
#define ticksPerRotation 360;
int circ = PI*wheelDiameter;
int inchesToTicks(int dist){
	return (dist/circ)*ticksPerRotation;
}

// @params (degrees_turned)
void turn(int);
// @params (direction, distance in inches)
void moveStraight(int, int);

void moveStraight(int dist, int speed){
	SensorValue[driveE] = 0;
	int currentValue = 0;
	int targetTicks = inchesToTicks(dist);
	inchesToTicks(dist);	
	while(abs(currentValue)<targetTicks){
		motor[Ldrive] = speed;
		motor[Rdrive] = speed;
	}
}

void turn(int deg){
	SensorValue[driveE] = 0;
	int currentValue = 0;
	int targetTicks = 240;
	while(abs(currentValue)<targetTicks){
		motor[Ldrive] = -40*deg;
		motor[Rdrive] = 40*deg;
		currentValue = SensorValue[driveE];
	}
	motor[Ldrive] = 0;
	motor[Rdrive] = 0;
}

task main()
{
	while(1){
		moveStraight(24,60);
		turn(1);
	}


}
