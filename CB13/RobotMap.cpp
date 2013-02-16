#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "Wire.h"
// NULL Inits *********************************
SpeedController* RobotMap::elevationSpd1 = NULL;
SpeedController* RobotMap::shooterSpd1 = NULL;
Encoder* RobotMap::elevationqenc = NULL;
DigitalInput* RobotMap::bottomLimit = NULL;
Counter* RobotMap::OpticalShoot = NULL;

Solenoid* RobotMap::gatesol1 = NULL;
Solenoid* RobotMap::gatesol2 = NULL;

Solenoid* RobotMap::frisbeeHandlersol1 = NULL;
Solenoid* RobotMap::frisbeeHandlersol2 = NULL;
Servo* RobotMap::frisbeeServo = NULL;
Relay* RobotMap::conveyorRelay = NULL;

Solenoid* RobotMap::climbersol1 = NULL;
Solenoid* RobotMap::climbersol2 = NULL;
SpeedController* RobotMap::climberspd1 = NULL;

Encoder* RobotMap::driveren1 = NULL;
Encoder* RobotMap::driveren2 = NULL;
SpeedController* RobotMap::driverspd2 = NULL;
SpeedController* RobotMap::driverspd1 = NULL;
RobotDrive* RobotMap::driverdriveTrain = NULL;
Gyro* RobotMap::drivergyro1 = NULL;


 Solenoid* RobotMap::chutelowextend = NULL;
 Solenoid* RobotMap::chutelowretract = NULL;
 Solenoid* RobotMap::chutehighextend = NULL;
 Solenoid* RobotMap::chutehighretract = NULL;

 Solenoid* RobotMap::firingpinIn = NULL;
 Solenoid* RobotMap::firingpinOut = NULL;
 
Compressor* RobotMap::compressor = NULL;
void RobotMap::init() {

	LiveWindow* lw = LiveWindow::GetInstance();
	

	//Climber ***************************
	climberspd1 = new Victor(moduleONE, portWINCH);//TODO Add Wiremap.h
	lw->AddActuator("climber", "spd1", (Victor*) climberspd1);

	//Elevation *************************
	elevationSpd1 = new Talon(moduleONE, portELEVATION);
	lw->AddActuator("Elevation", "Spd1", (Talon*) elevationSpd1);
	elevationqenc = new Encoder(moduleONE, ioELEVATIONENCODERA, moduleONE, ioELEVATIONENCODERB, false, Encoder::k4X);
	lw->AddSensor("Elevation", "qenc", elevationqenc);
	bottomLimit = new DigitalInput(moduleONE, ioELEVATIONSWNC);
	lw->AddSensor("BottomLimit", "bottomLimit", bottomLimit);
	OpticalShoot = new Counter(moduleONE, ioOPTICALSPEEDSENSOR);
	OpticalShoot->Start();
	OpticalShoot->Reset();
	lw->AddSensor("OpticalShoot", "OpticalShoot", OpticalShoot);
	elevationqenc->SetDistancePerPulse(1.0);
	elevationqenc->SetPIDSourceParameter(Encoder::kRate);
	elevationqenc->Start();
	shooterSpd1 = new Victor(moduleONE, portSHOOTER);
	firingpinIn = new Solenoid(moduleONE,portFIRINGPININ);
	firingpinOut = new Solenoid(moduleONE,portFIRINGPINOUT);
	
	//Frisbee Hanlder ******************
	 frisbeeHandlersol1 = new Solenoid(moduleTWO,portFORKUP);
	 frisbeeHandlersol1 = new Solenoid(moduleTWO,portFORKDOWN);
	frisbeeServo = new Servo(moduleONE,portDUMP);
	conveyorRelay = new Relay(moduleONE,portCONVEYOR);
	

	
	//Gate ****************************
	gatesol1 = new Solenoid(moduleTWO,portGATEEXTEND);
	gatesol2 = new Solenoid(moduleTWO,portGATERETRACT);
	
	//Compressor ****************************
	compressor = new Compressor(ioCOMPPRESSURESW,portCOMPRESSOR);

	
	
	//Chute ****************************
	chutelowextend = new Solenoid(moduleONE,portCHUTELOWEXTEND);
	chutelowretract = new Solenoid(moduleONE,portCHUTELOWRETRACT);
	chutehighextend = new Solenoid(moduleONE,portCHUTEHIGHEXTEND);
	chutehighretract = new Solenoid(moduleONE,portCHUTEHIGHRETRACT);
//	lw->AddActuator("chute","lowExtend", (Solenoid*) chutelowextend);
//	lw->AddActuator("chute","lowRetract", (Solenoid*) chutelowretract);
//	lw->AddActuator("chute","highExtend", (Solenoid*) chutehighextend);
//	lw->AddActuator("chute","highRetract", (Solenoid*) chutehighretract);
	
	//Drive ****************************
	driveren1 = new Encoder(moduleONE, ioDRIVEENCODERLEFTA, moduleONE,
			ioDRIVEENCODERLEFTB, true, Encoder::k4X);
	lw->AddSensor("driver", "en1", driveren1);
	driveren1->SetDistancePerPulse(1.0);
	driveren1->SetPIDSourceParameter(Encoder::kRate);
	driveren1->Start();
	driveren2 = new Encoder(moduleONE, ioDRIVEENCODERRIGHTA, moduleONE,
			ioDRIVEENCODERRIGHTB, false, Encoder::k4X);
	lw->AddSensor("driver", "en2", driveren2);
	driveren2->SetDistancePerPulse(1.0);
	driveren2->SetPIDSourceParameter(Encoder::kRate);
	driveren2->Start();
	driverspd2 = new Victor(moduleONE, portRIGHTDRIVE);
	lw->AddActuator("driver", "spd2", (Victor*) driverspd2);

	driverspd1 = new Victor(moduleONE, portLEFTDRIVE);
	lw->AddActuator("driver", "spd1", (Victor*) driverspd1);

	driverdriveTrain = new RobotDrive(driverspd1, driverspd2);

	driverdriveTrain->SetSafetyEnabled(false);
	driverdriveTrain->SetExpiration(0.1);
	driverdriveTrain->SetSensitivity(0.5);
	driverdriveTrain->SetMaxOutput(1.0);

	drivergyro1 = new Gyro(moduleONE, 1);//TODO create port for gyro
	drivergyro1->SetSensitivity(.75);
	lw->AddSensor("driver", "gyro1", drivergyro1);

	driveren1->SetDistancePerPulse(
			39 * 3.1415926535897932384626433832795028841971693993 / 14000);
	driveren2->SetDistancePerPulse(
			39 * 3.1415926535897932384626433832795028841971693993 / 14000);
	driveren1->Reset();
	driveren2->Reset();

}
