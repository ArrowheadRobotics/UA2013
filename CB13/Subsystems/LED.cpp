#include "LED.h"
#include "../Robotmap.h"

LED::LED() : Subsystem("LED") {
	
}
    
void LED::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

void LED::red(){
	LED1->Set(Relay::kForward);
	LED2->Set(Relay::kOn);
}

void LED::blue(){
	LED1->Set(Relay::kReverse);
	LED2->Set(Relay::kOn);
}

void LED::green(){
	LED1->Set(Relay::kOn);
	LED2->Set(Relay::kOn);
}

void LED::pink(){
	LED1->Set(Relay::kOff );
	LED2->Set(Relay::kOn);
}

void LED::yellow(){
	LED1->Set(Relay::kForward);
	LED2->Set(Relay::kForward);
}

void LED::aqua(){
	LED1->Set(Relay::kReverse);
	LED2->Set(Relay::kForward);
}

void LED::white(){
	LED1->Set(Relay::kOff);
	LED2->Set(Relay::kForward);
}

void LED::off(){
	LED1->Set(Relay::kOff);
	LED2->Set(Relay::kOff);
}
