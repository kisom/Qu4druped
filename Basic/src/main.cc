#include <Arduino.h>
#include <Leg.h>


#define LEG1	0
#define	LEG2	1
#define LEG3	2
#define LEG4	3


Leg	legs[] = {
	Leg( 2,  3,  4),	// LEG1
	Leg( 5,  6,  7),	// LEG2
	Leg( 8,  9, 10),	// LEG3
	Leg(11, 12, 13),	// LEG4
};



void
setup()
{
	Serial.begin(9600);
	while (!Serial) ;

	Serial.println("started");
	legs[LEG1].enable();
	legs[LEG2].enable();
	legs[LEG3].enable();
	legs[LEG4].enable();

	delay(1000);
}


static bool
readInt(int &val)
{
	if (!Serial.available()) {
		return false;
	}

	val = Serial.parseInt();
	return true;
}


void
loop()
{
	static int	leg = -1;
	int		index = 0;
	int		pose[3];

	while ((leg == -1) && (!readInt(leg))) ;
	leg--;
	if ((leg < LEG1) || (leg > LEG4)) {
		return;
	}

	while (index < 3) {
		if (readInt(pose[index])) {
			index++;
		}
	}

	Serial << "leg: " << leg << " -> pose " << pose[0] <<
		  "/" << pose[1] << "/" << pose[2];
	legs[leg].set(Pose{pose[0], pose[1], pose[2]});
	leg = -1;
	index = 0;
}
