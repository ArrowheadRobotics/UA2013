#include "square.h"
square::square() {
	Requires(Robot::driver);
}
// Called just before this Command runs the first time
void square::Initialize() {
	Robot::driver->gyro1->Reset();
	Robot::driver->en1->Reset();
	Robot::driver->en2->Reset();
	while(Robot::driver->en1->GetDistance()<2 || Robot::driver->en2->GetDistance()<2){
		if(Robot::driver->en1->GetDistance()<2){
			Robot::driver->spd1->Set(-.2);
		}
		else{
			//Robot::driver->spd1->Set(0);
		}
		if(Robot::driver->en2->GetDistance()<2){
			Robot::driver->spd2->Set(.2);
		}
		else{
			//Robot::driver->spd2->Set(0);
		}
		printf("%f  %f\n", Robot::driver->en1->GetDistance(), Robot::driver->en2->GetDistance());
	}
	Robot::driver->spd1->Set(0);
	Robot::driver->spd2->Set(0);
	Wait(.2);
	while(Robot::driver->gyro1->GetAngle()<90){
		Robot::driver->spd1->Set(-.2);
		Robot::driver->spd2->Set(-.2);
		printf("%f\n", Robot::driver->gyro1->GetAngle());
	}
	Robot::driver->spd1->Set(0);
	Robot::driver->spd2->Set(0);
	Robot::driver->gyro1->Reset();
	Robot::driver->en1->Reset();
	Robot::driver->en2->Reset();
	Wait(.1);
	while(Robot::driver->en1->GetDistance()<2 || Robot::driver->en2->GetDistance()<2){
		if(Robot::driver->en1->GetDistance()<2){
			Robot::driver->spd1->Set(-.2);
		}
		else{
			//Robot::driver->spd1->Set(0);
		}
		if(Robot::driver->en2->GetDistance()<2){
			Robot::driver->spd2->Set(.2);
		}
		else{
			//Robot::driver->spd2->Set(0);
		}
		printf("%f  %f\n", Robot::driver->en1->GetDistance(), Robot::driver->en2->GetDistance());
	}
	Robot::driver->spd1->Set(0);
	Robot::driver->spd2->Set(0);
	Wait(.2);
	while(Robot::driver->gyro1->GetAngle()<90){
		Robot::driver->spd1->Set(-.2);
		Robot::driver->spd2->Set(-.2);
		printf("%f\n", Robot::driver->gyro1->GetAngle());
	}
	Robot::driver->spd1->Set(0);
	Robot::driver->spd2->Set(0);
	Robot::driver->gyro1->Reset();
	Robot::driver->en1->Reset();
	Robot::driver->en2->Reset();
	Wait(.1);
	while(Robot::driver->en1->GetDistance()<2 || Robot::driver->en2->GetDistance()<2){
		if(Robot::driver->en1->GetDistance()<2){
			Robot::driver->spd1->Set(-.2);
		}
		else{
			//Robot::driver->spd1->Set(0);
		}
		if(Robot::driver->en2->GetDistance()<2){
			Robot::driver->spd2->Set(.2);
		}
		else{
			//Robot::driver->spd2->Set(0);
		}
		printf("%f  %f\n", Robot::driver->en1->GetDistance(), Robot::driver->en2->GetDistance());
	}
	Robot::driver->spd1->Set(0);
	Robot::driver->spd2->Set(0);
	Wait(.2);
	while(Robot::driver->gyro1->GetAngle()<90){
		Robot::driver->spd1->Set(-.2);
		Robot::driver->spd2->Set(-.2);
		printf("%f\n", Robot::driver->gyro1->GetAngle());
	}
	Robot::driver->spd1->Set(0);
	Robot::driver->spd2->Set(0);
	Robot::driver->gyro1->Reset();
	Robot::driver->en1->Reset();
	Robot::driver->en2->Reset();
	Wait(.1);
	while(Robot::driver->en1->GetDistance()<2 || Robot::driver->en2->GetDistance()<2){
		if(Robot::driver->en1->GetDistance()<2){
			Robot::driver->spd1->Set(-.2);
		}
		else{
			//Robot::driver->spd1->Set(0);
		}
		if(Robot::driver->en2->GetDistance()<2){
			Robot::driver->spd2->Set(.2);
		}
		else{
			//Robot::driver->spd2->Set(0);
		}
		printf("%f  %f\n", Robot::driver->en1->GetDistance(), Robot::driver->en2->GetDistance());
	}
	Robot::driver->spd1->Set(0);
	Robot::driver->spd2->Set(0);
	Wait(.2);
	while(Robot::driver->gyro1->GetAngle()<90){
		Robot::driver->spd1->Set(-.2);
		Robot::driver->spd2->Set(-.2);
		printf("%f\n", Robot::driver->gyro1->GetAngle());
	}
	Robot::driver->spd1->Set(0);
	Robot::driver->spd2->Set(0);
}
// Called repeatedly when this Command is scheduled to run
void square::Execute() {
	
}
// Make this return true when this Command no longer needs to run execute()
bool square::IsFinished() {
	return true;
}
// Called once after isFinished returns true
void square::End() {
	
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void square::Interrupted() {
}
