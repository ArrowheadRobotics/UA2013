#include "PID.h"

PID::PID(float ngoal, float nP, float nI, float nD, float nrange, float nh) {
    goal = ngoal;
    P = nP;
    I = nI;	
    D = nD;
    v = 0;
    h = nh;
    range = nrange;
    setold = range/2;
    sum = 0;
}

float PID::calculateProportion() {
    return (goal-h);  //change velocity by error
}

float PID::calculateIntegral() {
	sum += (h - goal);  //increment sum
	return -sum;  //return integral
}

float PID::calculateDerivative() {
    return(goal - (h+setold));  //guesstimate
}

float PID::calculatePID() {
    setold += P*calculateProportion() + I*calculateIntegral() + D*calculateDerivative();  //PID SUM
    if(setold<0) {setold = 0;}  //min speed
    if(setold>range) {setold = range;}  //max speed
    v=setold-range/2;  //set velocity
    h+=v;  //increment height
    return h;
}

void PID::setGoal(float ngoal) {
	goal = ngoal;
}

void PID::setValues(float ngoal, float nP, float nI, float nD, float nrange, float nh) {
    goal = ngoal;
    P = nP;
    I = nI;	
    D = nD;
    v = 0;
    h = nh;
    range = nrange;
    setold = range/2;
    sum = 0;
}

float PID::getError(){
	return (goal-h);
}
