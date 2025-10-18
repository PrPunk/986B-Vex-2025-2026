// robot.config.h
using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller CT1;
extern motor L1;
extern motor L2;
extern motor L3;
extern motor R1;
extern motor R2;
extern motor R3;
extern motor intakeL;
extern motor intakeR;
extern motor outake1;
extern digital_out outakePistons;
extern digital_out pnu2;

extern motor_group leftSide;
extern motor_group rightSide;
extern motor_group driveTrain;

// Initialize
void  vexcodeInit( void );