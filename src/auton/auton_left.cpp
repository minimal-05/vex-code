#include "auton.hpp"
#include "../robot/robot_config.hpp"

// LEFT SIDE -- THIS WORKS & CAN SCORE 6 BALLS (MATCHLOAD IS DROPPED)
void autonomousLeft() {

  // set starting position on left side
  chassis.setPose(-48.36, 16.2, 77.89);
  tonguePiston.set_value(true); // lifts tongue
  conveyorPiston.set_value(false);

  // collect 3 middle balls (storage)
  bottomIntake.move(127);
  chassis.moveToPoint(-22.5, 22.5, 1800, {.maxSpeed = 50}, false);
 
  // turn to middle goal, move to it, & score
  chassis.turnToPoint(-7, 7, 500, { .forwards = false, .maxSpeed = 60, }, false);
  bottomIntake.move(0);
  chassis.moveToPoint(-7, 7, 1000, { .forwards = false, .maxSpeed = 70, }, false);
  conveyorPiston.set_value(true);
  bottomIntake.move(-127);
  pros::delay(50);
  bottomIntake.move(0);
  fullIntake.move(127);
  pros::delay(1800);
  fullIntake.move(0);

  conveyorPiston.set_value(false); // raise

  // move to goal & align, then run intake & score
  chassis.moveToPoint(-47, 47, 1800, {.maxSpeed = 80}, false);
  chassis.turnToPoint(-57, 47, 800, {.maxSpeed = 80}, false);

  // drop tongue, move to loader, intake
  bottomIntake.move(127);
  tonguePiston.set_value(false);
  pros::delay(400);
  chassis.moveToPoint(-58, 47, 1300, {.maxSpeed = 75}, false);

  // move to long goal & score
  chassis.moveToPoint(-24, 47, 3000, {.forwards = false, .maxSpeed = 80}, true);
  pros::delay(1500);
  bottomIntake.move(0);
  fullIntake.move(127);
  pros::delay(1500);
  fullIntake.move(0);

  // wing
  chassis.moveToPoint(-39, 47, 700, {.maxSpeed = 70}, false);
  chassis.turnToPoint(-32, 35.5, 400, {.forwards = false, .maxSpeed = 80}, false);
  chassis.moveToPoint(-32, 35.5, 1400, {.forwards = false, .maxSpeed = 70}, false);
  chassis.turnToPoint(-7, 35.5, 400, {.forwards = false, .maxSpeed = 80}, false);
  chassis.moveToPoint(-7, 35.5, 3000, {.forwards = false, .maxSpeed = 80}, false);
}