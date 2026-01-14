#include "auton.hpp"
#include "../robot/robot_config.hpp"

void autonomousRight() {

  // set starting position on right side
  chassis.setPose(-48.36, -16.2, 103.692);
  tonguePiston.set_value(true); // lifts tongue
  conveyorPiston.set_value(false);

  // collect 3 middle balls (storage)
  bottomIntake.move(127);
  chassis.moveToPoint(-22.5, -22.5, 2000, {.maxSpeed = 50}, false);
  bottomIntake.move(0);

  // move to goal & align, then run intake & score
  chassis.turnToPoint(-44, -47, 300, {.forwards = false, .maxSpeed = 80}, false);
  chassis.moveToPoint(-44, -47, 1600, {.forwards = false, .maxSpeed = 90}, false);
  chassis.turnToPoint(-57, -47, 700, {.maxSpeed = 80}, false);

  // drop tongue, move to loader, intake
  bottomIntake.move(127);
  tonguePiston.set_value(false);
  pros::delay(400);
  chassis.moveToPoint(-57, -47, 2000, {.maxSpeed = 75}, false);

  // move to long goal & score
  chassis.moveToPoint(-24, -47, 4000, {.forwards = false, .maxSpeed = 75}, true);
  pros::delay(1500);
  bottomIntake.move(0);
  fullIntake.move(127);
  pros::delay(2500);
  fullIntake.move(0);

  // wing
  chassis.moveToPoint(-39, -47, 1000, {.maxSpeed = 70}, false);
  chassis.turnToPoint(-32, -59, 600, {.forwards = false, .maxSpeed = 80}, false);
  chassis.moveToPoint(-32, -59, 1500, {.forwards = false, .maxSpeed = 70}, false);
  chassis.turnToPoint(-7, -59, 600, {.forwards = false, .maxSpeed = 80}, false);
  chassis.moveToPoint(-7, -59, 3000, {.forwards = false, .maxSpeed = 80}, false);
  
}