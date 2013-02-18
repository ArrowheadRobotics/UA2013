#include "driver.h"
#include "../Robotmap.h"
#include "../Robot.h"
#include "../Commands/drive3.h"
driver::driver() : Subsystem("driver") {
	en1 = RobotMap::driveren1;
	en2 = RobotMap::driveren2;
	spd2 = RobotMap::driverspd2;
	spd1 = RobotMap::driverspd1;
	driveTrain = RobotMap::driverdriveTrain;
	gyro1 = RobotMap::drivergyro1;
}
    
void driver::InitDefaultCommand() {
	SetDefaultCommand(new drive3);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
void driver::M_drive(Joystick* stick1, Joystick* stick2){
	driveTrain->TankDrive(stick1, stick2);
}
void driver::drive2(Joystick* stick1, Joystick* stick2){
	float s1, s2;
	s1=stick1->GetY();
	s2=stick2->GetY();
	if(s1<.2 && s1>-.2)
		s1=0;
	if(s2<.2 && s2>-.2)
		s2=0;
	spd1->Set(s1);
	spd2->Set(s2);
}
void driver::read(){
	printf("Encoder 1 Raw: %d ",Robot::driver->en1->GetRaw());
	printf("Encoder 1: %d ",Robot::driver->en1->Get());
	printf("Encoder 2 Raw: %d ",Robot::driver->en2->GetRaw());
	printf("Encoder 2: %d ",Robot::driver->en2->Get());
	printf("RPM: %f\n", .24/Robot::driver->en1->GetPeriod());
}
void driver::reset(){
	Robot::driver->en1->Reset();
	Robot::driver->en2->Reset();
}
