#include "auton.hpp"
#include "../robot/robot_config.hpp"

// SOLO AWP -- DOESN'T WORK (UNTESTED) & CAN SCORE 12 BALLS IF IT WORKS (MATCHLOAD IS DROPPED)
void autonomousAWP() {

  // set starting position for middle
  chassis.setPose(-47, -15, 180);
  tonguePiston.set_value(true); // lifts tongue
  conveyorPiston.set_value(false);

  // move to tube
  chassis.moveToPoint(-47, -47, 1400, {.maxSpeed = 110}, false);
  chassis.turnToPoint(-57, -47, 700, {.maxSpeed = 80}, false);
  tonguePiston.set_value(false);
  pros::delay(400);
  bottomIntake.move(127);
  chassis.moveToPoint(-57, -47, 1600, {.maxSpeed = 70}, false);

  // move to long goal and score
  chassis.moveToPoint(-24, -47, 2700, {.forwards = false, .maxSpeed = 75}, true);
  pros::delay(1200);
  bottomIntake.move(0);
  fullIntake.move(127);
  pros::delay(1500);
  fullIntake.move(0);
  tonguePiston.set_value(true);

  // move back and get 6 balls
  chassis.moveToPoint(-36, -47, 1000, {.forwards = false, .maxSpeed = 110}, true);
  chassis.turnToPoint(-22.5, -22.5, 800, {.maxSpeed = 80}, false);
  bottomIntake.move(127);
  chassis.moveToPoint(-22.5, -22.5, 2000, {.maxSpeed = 60}, false);
  chassis.turnToPoint(-22.5, 22.5, 800, {.maxSpeed = 80}, false);
  pros::delay(800);
  tonguePiston.set_value(false);
  pros::delay(700);
  chassis.moveToPoint(-22.5, 22.5, 1500, {.maxSpeed = 110}, false);
  
  // score middle top
  chassis.turnToPoint(-11, -11, 800, {.forwards = false, .maxSpeed = 80}, false);
  conveyorPiston.set_value(true);
  chassis.moveToPoint(-11, -11, 1000, {.forwards = false, .maxSpeed = 70}, false);
  fullIntake.move(127);
  pros::delay(800);
  fullIntake.move(0);
  conveyorPiston.set_value(false);

  //move to other tube
  chassis.moveToPoint(-46, 47, 1500, {.maxSpeed = 110}, false);
  chassis.turnToPoint(-58, 47, 800, {.maxSpeed = 80}, false);
  tonguePiston.set_value(true);
  pros::delay(800);
  bottomIntake.move(127);
  chassis.moveToPoint(-58, 47, 2500, {.maxSpeed = 70}, false);

  // move to long goal and score
  chassis.moveToPoint(-24, 47, 3500, {.forwards = false, .maxSpeed = 75}, true);
  pros::delay(1200);
  bottomIntake.move(0);
  fullIntake.move(127);
  pros::delay(2300);
  fullIntake.move(0);

  // wing
  chassis.moveToPoint(-39, 47, 1000, {.maxSpeed = 70}, false);
  chassis.turnToPoint(-32, 35, 600, {.forwards = false, .maxSpeed = 80}, false);
  chassis.moveToPoint(-32, 35, 1500, {.forwards = false, .maxSpeed = 80}, false);
  chassis.turnToPoint(-7, 35, 600, {.forwards = false, .maxSpeed = 80}, false);
  chassis.moveToPoint(-7, 35, 3000, {.forwards = false, .maxSpeed = 80}, false);
}