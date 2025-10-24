/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Josiah Schatz and Sherwin Sagadam                         */
/*    Created:      Sat 23 Aug 2025                                           */
/*    Description:  Team 986B bot for 2025-2026                               */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "brain-display.cpp"
using namespace vex;
BrainDisplay brainDisplay; 

// A global instance of competition
competition Competition;

int autonMode = 1;
bool intakeOn = false;
float degPerInch = 47.012;
float inchPerDeg = 0.1069014;

void spinIntake() {
  intakeL.spin(fwd, 100, pct);
  intakeR.spin(fwd, 100, pct);
  outake2.spin(fwd, 100, pct);
}

void stopIntake() {
  intakeL.stop(brake);
  intakeR.stop(brake);
  outake2.stop(brake);
}

void spinIntakeOutake(int msecs) {
  intakeL.spin(fwd, 100, pct);
  intakeR.spin(fwd, 100, pct);
  outake1.spin(fwd, 100, pct);
  outake2.spin(fwd, 100, pct);
  wait (msecs, vex::timeUnits::msec);
  intakeL.stop(brake);
  intakeR.stop(brake);
  outake1.stop(brake);
  outake2.stop(brake);
}

void spinIntakePush(int msecs) {
  intakeL.spin(fwd, 100, pct);
  intakeR.spin(fwd, 100, pct);
  outake2.spin(fwd, 100, pct);
  driveTrain.spin(fwd, 5, pct);
  wait (msecs, vex::timeUnits::msec);
  intakeL.stop(brake);
  intakeR.stop(brake);
  outake2.stop(brake);
  driveTrain.stop(brake);
}

void moveStraight(float distance, int speed) {
  int degreesToTurn = degPerInch * distance;
  driveTrain.resetPosition();
  wait(100, vex::timeUnits::msec);
  driveTrain.spinToPosition(degreesToTurn, deg, speed, vex::velocityUnits::pct);
}

void turnRobot(int degrees, int speed) {
  float inchesToTurn = inchPerDeg * degrees;
  int degreesToTurn = degPerInch * inchesToTurn;
  degreesToTurn = abs(degreesToTurn);
  leftSide.resetPosition();
  rightSide.resetPosition();
  wait(100, vex::timeUnits::msec);
  if (degrees > 0) {
    // Turn counterclockwise
    while (leftSide.position(deg) <= degreesToTurn && rightSide.position(deg) >= -degreesToTurn) {
      leftSide.spin(fwd, speed, pct);
      rightSide.spin(fwd, -speed, pct);
    }
    leftSide.stop(brake);
    rightSide.stop(brake);
    // leftSide.spinToPosition(degreesToTurn, deg, speed, vex::velocityUnits::pct);
    // rightSide.spinToPosition(-degreesToTurn, deg, speed, vex::velocityUnits::pct);
  } else if (degrees < 0) {
    // Turn clockwise
    while (leftSide.position(deg) >= -degreesToTurn && rightSide.position(deg) <= degreesToTurn) {
      leftSide.spin(fwd, -speed, pct);
      rightSide.spin(fwd, speed, pct);
    }
    leftSide.stop(brake);
    rightSide.stop(brake);
    // leftSide.spinToPosition(degreesToTurn, deg, speed, vex::velocityUnits::pct);
    // rightSide.spinToPosition(-degreesToTurn, deg, speed, vex::velocityUnits::pct);
  };
}

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  // All activities that occur before the scompetition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // Insert autonomous user code here
  if (autonMode == 1) {
    // Left Side Auton
    spinIntake();
    moveStraight(28, 40);
    stopIntake();
    turnRobot(110, 40);
    moveStraight(-13.5, 40);
    spinIntakeOutake(3000);
    moveStraight(46.5, 60);
    turnRobot(50, 20);
    moveStraight(13, 15);
    spinIntakePush(2500);
    outakePistons.set(1);
    moveStraight(-29, 15);
    spinIntakeOutake(10000);

  } else if (autonMode == 2) {
    // Right Side Auton
    moveStraight(32, 30);
    turnRobot(-90, 30);
    moveStraight(13, 15);
    spinIntakePush(2500);
    outakePistons.set(1);
    moveStraight(-29, 15);
    spinIntakeOutake(10000);
  } else if (autonMode == 3) {
    // Skills Auton
    intakeL.spin(fwd, 100, pct);
    intakeR.spin(fwd, 100, pct);
    outake2.spin(fwd, 100, pct);
    moveStraight(28, 30);//30
  }
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {

    // Tank drive controls
    L1.spin(fwd, (CT1.Axis2.value()/1.270), pct);
    L2.spin(fwd, (CT1.Axis2.value()/1.270), pct);
    L3.spin(fwd, (CT1.Axis2.value()/1.270), pct);
    R1.spin(fwd, (CT1.Axis3.value()/1.270), pct);
    R2.spin(fwd, (CT1.Axis3.value()/1.270), pct);
    R3.spin(fwd, (CT1.Axis3.value()/1.270), pct);
    
    // Intake and outake controls
    if (CT1.ButtonR2.pressing()) {
      // Starts sucking in for the intake
      // Starts spitting out for outake
      intakeL.spin(fwd, 100, pct);
      intakeR.spin(fwd, 100, pct);
      outake1.spin(fwd, 100, pct);
      outake2.spin(fwd, 100, pct);
      intakeOn = true;
    } else if (CT1.ButtonR1.pressing()) {
      // Stops sucking in and starts spitting out for intake
      // Stops spitting out and start sucking in for outake
      intakeL.spin(fwd, -100, pct);
      intakeR.spin(fwd, -100, pct);
      outake1.spin(fwd, -100, pct);
      outake2.spin(fwd, -100, pct);
      intakeOn = false;
    } else if (!intakeOn) {
      intakeL.stop(coast);
      intakeR.stop(coast);
      outake1.stop(coast);
      outake2.stop(coast);
    }

    if (CT1.ButtonDown.pressing()) {
      outakePistons.set(0);
    } else if (CT1.ButtonUp.pressing()) {
      outakePistons.set(1);
    }

    // Eliminates the judges if they give a bad score for our robot.
    if (CT1.ButtonLeft.pressing()) {
      pnu2.set(1);
    } else {
      pnu2.set(0);
    }
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

void setAuton(int autonNumber) {
  // Set autonomous mode.
  autonMode = autonNumber;
  CT1.rumble("-.-.-");
}

void goToPage(int pageId) {
  brainDisplay.switchPage(pageId);
}


void drawOnScreen() {
  //Place code here

  Button returnButton1;
  returnButton1.x = 350;
  returnButton1.y = 200;
  returnButton1.width = 140;
  returnButton1.height = 60;
  returnButton1.callback = goToPage;
  returnButton1.param = 0;
  char newText[20] = "Return";
  strcpy(returnButton1.text, newText);
  returnButton1.color = 0xff0000;
  brainDisplay.createButton(2,0, returnButton1);
  brainDisplay.addImage(2);

  Button skillsAutonButton;
  skillsAutonButton.x = 40;
  skillsAutonButton.y = 60;
  skillsAutonButton.width = 140;
  skillsAutonButton.height = 60;
  skillsAutonButton.callback = setAuton;     //  setAuton(3);
  skillsAutonButton.param = 3;
  char newText2[20] = "Skills Auton";
  strcpy(skillsAutonButton.text, newText2);
  skillsAutonButton.color = 0x04cc33;
  brainDisplay.createButton(1,0, skillsAutonButton);

  Button returnButton2;
  returnButton2.x = 40;
  returnButton2.y = 160;
  returnButton2.width = 140;
  returnButton2.height = 60;
  returnButton2.callback = goToPage;
  returnButton2.param = 0;
  char newText3[20] = "Return";
  strcpy(returnButton2.text, newText3);
  returnButton2.color = 0xff0000;
  brainDisplay.createButton(1,1, returnButton2);

  Button leftSideButton;
  leftSideButton.x = 300;
  leftSideButton.y = 60;
  leftSideButton.width = 140;
  leftSideButton.height = 60;
  leftSideButton.callback = setAuton;
  leftSideButton.param = 1;
  char newText4[20] = "Left Side";
  strcpy(leftSideButton.text, newText4);
  leftSideButton.color = 0x02749e;
  brainDisplay.createButton(1,2, leftSideButton);

  Button rightSideButton;
  rightSideButton.x = 300;
  rightSideButton.y = 160;
  rightSideButton.width = 140;
  rightSideButton.height = 60;
  rightSideButton.callback = setAuton;
  rightSideButton.param = 2;
  char newText5[20] = "Right Side";
  strcpy(rightSideButton.text, newText5);
  rightSideButton.color = 0x02749e;
  brainDisplay.createButton(1,3, rightSideButton);

  Button autonButton;
  autonButton.x = 180;
  autonButton.y = 160;
  autonButton.width = 140;
  autonButton.height = 60;
  autonButton.callback = goToPage;
  autonButton.param = 1;
  char newText6[20] = "Auton";
  strcpy(autonButton.text, newText6);
  autonButton.color = 0x02749e;
  brainDisplay.createButton(0,0, autonButton);
  brainDisplay.switchPage(0);

  Button imageButton;
  imageButton.x = 180;
  imageButton.y = 60;
  imageButton.width = 140;
  imageButton.height = 60;
  imageButton.callback = goToPage;
  imageButton.param = 2;
  char newText7[20] = "Image";
  strcpy(imageButton.text, newText7);
  imageButton.color = 0xff0000;
  brainDisplay.createButton(0,1, imageButton);

}

//
// Main will set up the competition functions and callbacks.
//

void screenCallback() {
  brainDisplay.screenPressed();
}

int main() {
  // Set up callbacks for autonomous and driver control periods.
  Brain.Screen.pressed(screenCallback);
  drawOnScreen();

  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
