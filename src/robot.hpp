#pragma once

#include <WPILib.h>

class Robot : public IterativeRobot {
public:
	void RobotInit();
	void DisabledInit();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	void TestInit();
private:
//	Autonomous *autonomous;
};


