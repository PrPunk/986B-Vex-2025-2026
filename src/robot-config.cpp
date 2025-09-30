#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller CT1 = controller(primary);

motor L1 = motor(PORT3, ratio6_1, false);
motor L2 = motor(PORT2, ratio6_1, false);
motor L3 = motor(PORT1, ratio6_1, false);
motor R1 = motor(PORT4, ratio6_1, true);
motor R2 = motor(PORT7, ratio6_1, true);
motor R3 = motor(PORT8, ratio6_1, true);
motor intakeL = motor(PORT9, ratio6_1, false);
motor intakeR = motor(PORT10, ratio6_1, true);

digital_out outakePistons(Brain.ThreeWirePort.B);
digital_out pnu2(Brain.ThreeWirePort.C);
// VEXcode generated functions



// Initialize
void vexcodeInit( void ) {
  // Brain.Screen.print("Device initialization...");
  // Brain.Screen.setCursor(2, 1);
  // // calibrate the drivetrain gyro
  // wait(200, msec);
  // TurnGyroSmart.startCalibration(1);
  // Brain.Screen.print("Calibrating Gyro for Drivetrain");
  // // wait for the gyro calibration process to finish
  // while (TurnGyroSmart.isCalibrating()) {
  //   wait(25, msec);
  // }
  // // reset the screen now that the calibration is complete
  // Brain.Screen.clearScreen();
  // Brain.Screen.setCursor(1,1);
  // wait(50, msec);
  // Brain.Screen.clearScreen();
}