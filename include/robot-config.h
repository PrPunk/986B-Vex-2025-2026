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
extern digital_out outakePistons;

// Initialize
void  vexcodeInit( void );