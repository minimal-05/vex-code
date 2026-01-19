#include "auton.hpp"
#include "../robot/robot_config.hpp"

// SOLO AWP -- DOESN'T WORK (UNTESTED) & CAN SCORE 12 BALLS IF IT WORKS (MATCHLOAD IS DROPPED)
void autonomousAWP() {

  // set starting position for middle
  chassis.setPose(-47, -15, 180);
  tonguePiston.set_value(true); // lifts tongue
  conveyorPiston.set_value(false);

  // move to tube
  chassis.moveToPoint(-47, -47, 1200, {.maxSpeed = 90}, false);
  chassis.turnToPoint(-57, -47, 500, {.maxSpeed = 80}, false);
  tonguePiston.set_value(false);
  pros::delay(300);
  bottomIntake.move(127);
  chassis.moveToPoint(-57, -47, 1100, {.maxSpeed = 70}, false);

  // move to long goal and score
  chassis.moveToPoint(-24, -47, 2000, {.forwards = false, .maxSpeed = 75}, true);
  pros::delay(1200);
  bottomIntake.move(0);
  fullIntake.move(127);
  pros::delay(800);
  fullIntake.move(0);
  tonguePiston.set_value(true);

  // move back and get 6 balls
  chassis.moveToPoint(-36, -47, 500, { .maxSpeed = 90}, true);
  chassis.turnToPoint(-22.5, -22.5, 400, {.maxSpeed = 80}, false);
  bottomIntake.move(127);
  chassis.moveToPoint(-22.5, -22.5, 1100, {.maxSpeed = 100}, true);
  pros::delay(300);
  tonguePiston.set_value(false);
  chassis.turnToPoint(-22.5, 22.5, 300, {.maxSpeed = 80}, false);
  tonguePiston.set_value(true);
  chassis.moveToPoint(-22.5, 22.5, 1600, {.maxSpeed = 100}, true);
  pros::delay(850);
  tonguePiston.set_value(false);
  
  // score middle top
  chassis.turnToPoint(-7, 7, 400, {.forwards = false, .maxSpeed = 80}, false);
  chassis.moveToPoint(-7, 7, 700, {.forwards = false, .maxSpeed = 70}, false);
  conveyorPiston.set_value(true);
  bottomIntake.move(-127);
  pros::delay(50);
  bottomIntake.move(0);
  fullIntake.move(127);
  pros::delay(500);
  fullIntake.move(0);
  conveyorPiston.set_value(false);

  //move to other tube
  chassis.moveToPoint(-46, 47, 1400, {.maxSpeed = 90}, false);
  chassis.turnToPoint(-57, 47, 400, {.maxSpeed = 80}, false);
  bottomIntake.move(127);
  chassis.moveToPoint(-57, 47, 1100, {.maxSpeed = 80}, false);

  // move to long goal and score
  chassis.moveToPoint(-24, 47, 3500, {.forwards = false, .maxSpeed = 70}, true);
  pros::delay(1200);
  bottomIntake.move(0);
  fullIntake.move(127);
  pros::delay(2300);
  fullIntake.move(0);

}