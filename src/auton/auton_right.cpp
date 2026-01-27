#include "auton.hpp"
#include "../robot/robot_config.hpp"

void autonomousRight() {

  // set starting position on right side
  chassis.setPose(-48.36, -16.2, 103.692);
  tonguePiston.set_value(true); // lifts tongue
  // lastX = false;

  // collect 3 middle balls (storage)
  bottomIntake.move(127);
  chassis.moveToPoint(-22.5, -22.5, 2000, {.maxSpeed = 90}, false);
  pros::delay(400);
  tonguePiston.set_value(false);

  // move to goal & align, then run intake & score
  chassis.turnToPoint(-47, -47, 500, { .maxSpeed = 80}, false);
  chassis.moveToPoint(-47, -47, 1600, { .maxSpeed = 90}, false);
  chassis.turnToPoint(-60, -47, 800, {.maxSpeed = 80}, false);

  // move to loader, intake
  bottomIntake.move(127);
  pros::delay(400);
  chassis.moveToPoint(-60, -47, 1100, {.maxSpeed = 80}, false);

  // move to long goal & score
  chassis.moveToPoint(-24, -47, 4000, {.forwards = false, .maxSpeed = 80}, true);
  pros::delay(1500);
  bottomIntake.move(0);
  fullIntake.move(127);
  pros::delay(2500);
  fullIntake.move(0);

  // wing
  chassis.moveToPoint(-39, -47, 600, {.maxSpeed = 80}, false);
  chassis.turnToPoint(-32, -56.75, 300, {.forwards = false, .maxSpeed = 80}, false);
  chassis.moveToPoint(-32, -56.75, 800, {.forwards = false, .maxSpeed = 80}, false);
  chassis.turnToPoint(-7, -56.75, 300, {.forwards = false, .maxSpeed = 80}, false);
  chassis.moveToPoint(-7, -56.75, 3000, {.forwards = false, .maxSpeed = 70}, false);
  
}