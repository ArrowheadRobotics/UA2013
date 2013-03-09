#include "fire.h"
bool shot;
bool lowvoltshot;

Fire::Fire() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	t = new Timer();
	SetTimeout(2.0f);
}
// Called just before this Command runs the first time
void Fire::Initialize() {
	shot = false;
	t->Reset();
	t->Start();
	lowvoltshot = false;
}
// Called repeatedly when this Command is scheduled to run
void Fire::Execute() {
	printf("time: %f\n", t->Get());
	if (RobotMap::bottomLimit->Get() != 1) {//limit-> not loading, shooting
		if (!shot) {//hasn't fired
			if (60.0f / Robot::elevation->OpticalShoot->GetPeriod() > 4800
					|| t->Get() > 1.0f) {//at rpm
				printf("Fire\n");
				if (!(60.0f / Robot::elevation->OpticalShoot->GetPeriod() > 4800)) {
					lowvoltshot = true;
						Robot::elevation->fire();
						shot = true;//past tense shoot

				} else {
					Robot::elevation->fire();
					shot = true;//past tense shoot

				}
			} else {//not at rpm
				Robot::elevation->recoil();
			}

		} else {//has fired
			if (lowvoltshot) {
				if (t->Get() > 1.0f) {
					t->Reset();
					shot = false;
					lowvoltshot = false;
				}
			} else {
				shot = false;
				t->Reset();
			}
			//if(t->Get()<.4)Robot::elevation->recoil();
		}
	} else {//loading, button has controll. 
		Robot::elevation->fire();
	}
	printf("Exec\n");

	//	//	if (t->Get() > .5f && RobotMap::bottomLimit->Get() != 1)
	//	if (60.0f / Robot::elevation->OpticalShoot->GetPeriod() > 5400
	//			&& RobotMap::bottomLimit->Get() != 1)
	//		Robot::elevation->recoil();
}
// Make this return true when this Command no longer needs to run execute()
bool Fire::IsFinished() {
	printf("Finish\n");
	return IsTimedOut();
}
// Called once after isFinished returns true
void Fire::End() {
	printf("End\n");
	if (RobotMap::bottomLimit->Get() != 1)
		Robot::elevation->recoil();
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Fire::Interrupted() {
	printf("Int\n");
	Robot::elevation->recoil();
}
