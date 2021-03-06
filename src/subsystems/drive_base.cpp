#include "drive_base.hpp"
#include "../commands/tank_drive.hpp"
#include "../port_mapping.hpp"

#include <WPILib.h>

Drive_Base::Drive_Base() :
Subsystem("Drive_Base"),
left_front_motor(new CANTalon(Ports::CANBusIDs::LEFT_FRONT_MOTOR)),
left_middle_motor (new CANTalon(Ports::CANBusIDs::LEFT_MIDDLE_MOTOR)),
left_rear_motor (new CANTalon(Ports::CANBusIDs::LEFT_REAR_MOTOR)),
right_front_motor (new CANTalon(Ports::CANBusIDs::RIGHT_FRONT_MOTOR)),
right_middle_motor (new CANTalon(Ports::CANBusIDs::RIGHT_MIDDLE_MOTOR)),
right_rear_motor (new CANTalon(Ports::CANBusIDs::RIGHT_REAR_MOTOR)) {
	set_motors_normalized(0, 0);
}

void Drive_Base::InitDefaultCommand() {
	SetDefaultCommand( new Tank_Drive() );
}

void Drive_Base::set_motors_normalized(float left_speed, float right_speed) {
	float left = constrain(left_speed);
	float right = constrain(right_speed);
	left_front_motor->Set(left);
	left_middle_motor->Set(left);
	left_rear_motor->Set(left);
	right_front_motor->Set(right);
	right_middle_motor->Set(right);
	right_rear_motor->Set(right);
}

float Drive_Base::constrain(float input) {
	if(input > 0.85) {
		input = 0.85;
	}
	else if(input < -0.85) {
		input = -0.85;
	}
	return input;
}
