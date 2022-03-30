#include "Leg.h"


static Pose	neutralPose = {90, 90, 90};


Leg::Leg() {}


Leg::Leg(int pin1, int pin2, int pin3) : pin1(pin1), pin2(pin2), pin3(pin3) {};


void
Leg::neutral()
{
	set(neutralPose);
}


void
Leg::enable()
{
	enabled = true;
	leg1.attach(pin1);
	leg2.attach(pin2);
	leg3.attach(pin3);
	set(neutralPose);
}


void
Leg::disable()
{
	if (!enabled) {
		return;
	}

	leg1.detach();
	leg2.detach();
	leg3.detach();
	enabled = false;
}


void
Leg::set(Pose pose)
{
	if (enabled) {
		Serial << "Pose: " << pose.leg1 << "/" << pose.leg2 <<
			  "/" << pose.leg3 << endl;
		if (pose.leg1 != -1) leg1.write(pose.leg1);
		if (pose.leg2 != -1) leg2.write(pose.leg2);
		if (pose.leg3 != -1) leg3.write(pose.leg3);
	}
}


void
Leg::set1(int servo, int pos)
{
	if (!enabled) {
		return;
	}

	switch (servo) {
	case 1:
		leg1.write(pos);
		break;
	case 2:
		leg2.write(pos);
		break;
	case 3:
		leg3.write(pos);
		break;
	default:
		return;
	}
}



Pose
Leg::get()
{
	Pose	pose = {-1, -1, -1};

	if (enabled) {
		pose.leg1 = leg1.read();
		pose.leg2 = leg2.read();
		pose.leg3 = leg3.read();
	}

	return pose;
}

