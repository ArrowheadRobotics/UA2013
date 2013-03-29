#include "TrackTarget.h"
TrackTarget::TrackTarget() {
	Requires(Robot::elevation);
}
// Called just before this Command runs the first time
void TrackTarget::Initialize() {
	//height = 0;
}
// Called repeatedly when this Command is scheduled to run
void TrackTarget::Execute() {
#ifdef USE_NETWORK
	//	try
	//		{
	//			printf(" 123  =  %f\n",Robot::oi->server->GetNumber("targetPixelHeight"));
	//			height = Robot::oi->server->GetNumber("targetPixelHeight");
	//		}
	//	catch (...)
	//		{
	//			printf("FAILBLOG.ORG\n");
	//			}
	//	if(height>125) {
	//		Robot::elevation->Up(-.7*(height-120.0f)/120);
	//		printf(" %f\n",height);
	//	}else if (height<115){
	//		Robot::elevation->Down(-.7*(height-120.0f)/120);
	//		printf("Up %f\n",height);
	//	}
	//	else{
	//		Robot::elevation->Stop();
	//		printf("STOP %f\n",height);
	//	}
#endif
#ifndef USE_NETWORK
	Robot::elevation->elevationSetPoint = 3050;
	Robot::elevation->gotoSetPoint();
#endif
}
// Make this return true when this Command no longer needs to run execute()
bool TrackTarget::IsFinished() {
	return false;
}
// Called once after isFinished returns true
void TrackTarget::End() {
	Robot::elevation->Stop();
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TrackTarget::Interrupted() {
	Robot::elevation->Stop();
}
