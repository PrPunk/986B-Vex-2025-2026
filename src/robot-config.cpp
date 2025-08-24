#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);

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