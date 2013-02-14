#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
// NULL Inits *********************************
SpeedController* RobotMap::elevationSpd1 = NULL;
SpeedController* RobotMap::shooterSpd1 = NULL;
Encoder* RobotMap::elevationqenc = NULL;
DigitalInput* RobotMap::bottomLimit = NULL;
Counter* RobotMap::OpticalShoot =NULL;

Solenoid* RobotMap::gatesol1 = NULL;
Solenoid* RobotMap::gatesol2 = NULL;

Encoder* RobotMap::driveren1 = NULL;
Encoder* RobotMap::driveren2 = NULL;
SpeedController* RobotMap::driverspd2 = NULL;
SpeedController* RobotMap::driverspd1 = NULL;
RobotDrive* RobotMap::driverdriveTrain = NULL;
Gyro* RobotMap::drivergyro1 = NULL;

void RobotMap::init() {

	
	LiveWindow* lw = LiveWindow::GetInstance();
	
	//Elevation *************************
	elevationSpd1 = new Talon(1, 3);
	lw->AddActuator("Elevation", "Spd1", (Talon*) elevationSpd1);

	elevationqenc = new Encoder(1, 1, 1, 2, false, Encoder::k4X);
	lw->AddSensor("Elevation", "qenc", elevationqenc);
	bottomLimit = new DigitalInput(1, 7);
	lw->AddSensor("BottomLimit", "bottomLimit", bottomLimit);
	OpticalShoot = new Counter(1,10);
	OpticalShoot->Start();
	OpticalShoot->Reset();
	lw->AddSensor("OpticalShoot", "OpticalShoot", OpticalShoot);
	elevationqenc->SetDistancePerPulse(1.0);
	elevationqenc->SetPIDSourceParameter(Encoder::kRate);
	elevationqenc->Start();
	shooterSpd1 = new Victor(1,1);

	
	//Drive ****************************
	driveren1 = new Encoder(1, 4, 1, 8, true, Encoder::k4X);
	lw->AddSensor("driver", "en1", driveren1);
	driveren1->SetDistancePerPulse(1.0);
	driveren1->SetPIDSourceParameter(Encoder::kRate);
	driveren1->Start();
	driveren2 = new Encoder(1, 5, 1, 6, false, Encoder::k4X);
	lw->AddSensor("driver", "en2", driveren2);
	driveren2->SetDistancePerPulse(1.0);
	driveren2->SetPIDSourceParameter(Encoder::kRate);
	driveren2->Start();
	driverspd2 = new Victor(1, 2);
	lw->AddActuator("driver", "spd2", (Victor*) driverspd2);
	
	driverspd1 = new Victor(1, 9);//TODO Corey fix
	lw->AddActuator("driver", "spd1", (Victor*) driverspd1);

	driverdriveTrain = new RobotDrive(driverspd1, driverspd2);

	driverdriveTrain->SetSafetyEnabled(false);
	driverdriveTrain->SetExpiration(0.1);
	driverdriveTrain->SetSensitivity(0.5);
	driverdriveTrain->SetMaxOutput(1.0);

	drivergyro1 = new Gyro(1, 1);
	lw->AddSensor("driver", "gyro1", drivergyro1);
	drivergyro1->SetSensitivity(0.0064);

	driveren1->SetDistancePerPulse(
			39 * 3.1415926535897932384626433832795028841971693993 / 14000);
	driveren2->SetDistancePerPulse(
			39 * 3.1415926535897932384626433832795028841971693993 / 14000); //Alex likes pi!  Yes
	driveren1->Reset();
	driveren2->Reset();
	
}
