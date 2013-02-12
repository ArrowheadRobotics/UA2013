#ifndef TRUMPET
#define TRUMPET

class PID {
	//VARIABLE DECLARATIONS
	float goal;
	float P;
	float I;
	float D;
	float v;  //velocity
	float h;  //height
	float range;  //max velocity
	float setold;  //previous set value;
	float sum;  //integral sum
	float calculateProportion();
	float calculateIntegral();
	float calculateDerivative();
public:
	PID(){};
	PID(float, float, float, float, float, float);  //goal, P, I, D, maxspeed, currend position
	float calculatePID();
	void setGoal(float);
	void setValues(float, float, float, float, float, float);  //goal, P, I, D, maxspeed, current position
	float getError();
};

#endif
