#ifndef _QUADRUPED_LEG_H
#define _QUADRUPED_LEG_H

#include <Arduino.h>
#include <Servo.h>
#include <Streaming.h>


// Pose is used to to instruct the robot how to set each of the
// three servos in a leg. By convention, -1 means "don't change
// this."
typedef struct {
	int	leg1;
	int	leg2;
	int	leg3;
} Pose;


// TODO(kyle): consider a stepped approach, rather than just snapping
// into position.
class Leg {
public:
	Leg();	// disabled leg
	Leg(int pin1, int pin2, int pin3);

	void	neutral();
	void	enable();
	void	disable();
	void	set(Pose pose);
	void	set1(int servo, int pos);
	Pose	get();

private:
	int	pin1;
	int	pin2;
	int	pin3;
	bool	enabled;
	Servo	leg1;
	Servo	leg2;
	Servo	leg3;
};


#endif
