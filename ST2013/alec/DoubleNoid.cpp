#include "DoubleNoid.h"

DoubleNoid::DoubleNoid(Solenoid *sa, Solenoid *sb, bool def) {
	setNoids(sa, sb, def);
}

void DoubleNoid::setNoids(Solenoid *sa, Solenoid *sb, bool def) {
	a = sa;
	b = sb;
	setValue(def);
}

Solenoid* DoubleNoid::getNoid(bool noid) {
	return (!noid)?a:b;
}

Solenoid* DoubleNoid::operator[](bool noid) {
	return getNoid(noid);
}

void DoubleNoid::setValue(bool noidvalue) {
	if(noidvalue) {
		b->Set(false);
		a->Set(true);
	} else {
		a->Set(false);
		b->Set(true);
	}
	
	value = noidvalue;
}

bool DoubleNoid::getValue() {
	return value;
}
