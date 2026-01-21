#include "auton.hpp"
#include "../robot/robot_config.hpp"

void fromtheside() {
  // set starting position for middle
  chassis.setPose(-63, -17.5, 0);
  tonguePiston.set_value(true); // lifts tongue
  conveyorPiston.set_value(false);
  

  // move to ball
  bottomIntake.move(127);
  pros::delay(200);
  chassis.moveToPoint(-63, 0, 7000, {.maxSpeed = 40}, false);
  chassis.turnToPoint(-61, 20, 300, {.maxSpeed = 60}, false);
  chassis.moveToPoint(-61, 20, 4000, {.maxSpeed = 70}, false);
  
  // move to middle goal
  bottomIntake.move(0);
  chassis.turnToPoint(-18.495, 18.495, 500, {.maxSpeed = 60}, false);
  chassis.moveToPoint(-18.495, 18.495, 2500, {.maxSpeed = 70}, false);
  chassis.turnToPoint(-13, 13, 500, {.forwards = false, .maxSpeed = 60}, false);

} 

void fromthefront() {

  // set starting position for middle
  chassis.setPose(-56, 0, 270);
  tonguePiston.set_value(true); // lifts tongue
  conveyorPiston.set_value(false);

  // move to ball
  bottomIntake.move(127);
  chassis.moveToPoint(-65, 0, 500, {.maxSpeed = 70}, false);
  chassis.moveToPoint(-54, 0, 600, {.forwards = false, .maxSpeed = 90}, true);
  pros::delay(200);
  bottomIntake.move(-127);
  pros::delay(80);
  bottomIntake.move(127);
  chassis.moveToPoint(-65, 0, 800, {.maxSpeed = 100}, false);
  chassis.moveToPoint(-54, 0, 700, {.forwards = false, .maxSpeed = 90}, true);
  pros::delay(200);
  bottomIntake.move(-127);
  pros::delay(80);
  bottomIntake.move(127);
  chassis.moveToPoint(-65, 0, 800, {.maxSpeed = 100}, false);

  chassis.moveToPoint(-45, 0, 1000, {.forwards = false, .maxSpeed = 90}, false);
  bottomIntake.move(0);
  chassis.moveToPoint(-47, 0, 1300, {.maxSpeed = 30}, false);
  chassis.setPose(-45.5, 0, 270);

  chassis.moveToPoint(-22.5, 0, 1000, {.maxSpeed = 80}, false);
  chassis.turnToPoint(-19.5, 19, 500, {.maxSpeed = 80}, false);
  bottomIntake.move(127);
  chassis.moveToPoint(-19.5, 19, 1500, {.maxSpeed = 80}, true);
  pros::delay(600);
  bottomIntake.move(0);
}

void autonomousSkills() {  // need the odometry to not get stuck

  fromthefront();

  // scoring mid goal
  chassis.turnToPoint(-6, 6, 500, { .forwards = false, .maxSpeed = 80, }, false);
  chassis.moveToPoint(-6, 6, 1000, { .forwards = false, .maxSpeed = 70, }, false);
  conveyorPiston.set_value(true);
  bottomIntake.move(-127);
  pros::delay(50);
  bottomIntake.move(0);
  fullIntake.move(127);
  pros::delay(3000);
  fullIntake.move(0);

  conveyorPiston.set_value(false); // raise

  // move to goal & align, then run intake & score
  chassis.moveToPoint(-47, 47, 1800, {.maxSpeed = 90}, false);
  chassis.turnToPoint(-58, 47, 800, {.maxSpeed = 80}, false);

  // drop tongue, move to loader, intake
  tonguePiston.set_value(false);
  pros::delay(300);
  chassis.moveToPoint(-58, 47, 2500, {.maxSpeed = 80}, false);
  
  // move to other side
  chassis.moveToPoint(-37, 47, 2000, {.maxSpeed = 90}, false);
  chassis.turnToPoint(-28, 59, 500, {.maxSpeed = 80}, false);
  chassis.moveToPoint(-28, 59, 2000, {.maxSpeed = 90}, false);
  chassis.turnToPoint(28, 59, 500, {.maxSpeed = 80}, false);
  chassis.moveToPoint(28, 59, 4000, {.maxSpeed = 90}, false);
  chassis.turnToPoint(37, 47, 500, {.maxSpeed = 80}, false);
  chassis.moveToPoint(37, 47, 2000, {.maxSpeed = 90}, false);
  chassis.turnToPoint(30, 47, 500, {.maxSpeed = 80}, false);

  // drop tongue, move to loader, intake
  tonguePiston.set_value(true);
  bottomIntake.move(127);
  pros::delay(200);
  chassis.moveToPoint(58, 47, 2500, {.maxSpeed = 70}, false);
  
  // move to long goal & score
  chassis.moveToPoint(30, 47, 2000, {.forwards = false, .maxSpeed = 80}, false);
  bottomIntake.move(0);
  fullIntake.move(127);
  pros::delay(6000);
  fullIntake.move(0);
  tonguePiston.set_value(false);

  // move back, get 4 balls and score in bottom middle
  chassis.moveToPoint(37, 47, 800, {.maxSpeed = 70}, false);
  chassis.turnToPoint(22.5, 22.5, 500, {.maxSpeed = 60}, false);
  bottomIntake.move(127);
  chassis.moveToPoint(22.5, 22.5, 4000, {.maxSpeed = 50}, false);
  chassis.turnToPoint(14, 14, 500, {.maxSpeed = 60}, false);
  chassis.moveToPoint(14, 14, 1800, {.maxSpeed = 60}, false);
  bottomIntake.move(-127);
  pros::delay(2000);
  bottomIntake.move(0);

  // go out and get tube
  chassis.moveToPoint(19, 19, 1000, {.forwards = false, .maxSpeed = 70}, false);
  chassis.turnToPoint(42, -47, 500, {.maxSpeed = 60}, false);
  bottomIntake.move(127);
  chassis.moveToPoint(42, -47, 5000, {.maxSpeed = 80}, false);
  chassis.turnToPoint(58, -47, 500, {.maxSpeed = 60}, false);

  // drop tongue, move to loader, intake
  tonguePiston.set_value(true);
  pros::delay(200);
  chassis.moveToPoint(58, -47, 2500, {.maxSpeed = 60}, false);

  // move to long goal & score
  chassis.moveToPoint(30, -47, 2000, {.forwards = false, .maxSpeed = 80}, false);
  bottomIntake.move(0);
  fullIntake.move(127);
  pros::delay(6000);
  fullIntake.move(0);
  tonguePiston.set_value(false);
  
  // move to other side
  // chassis.moveToPoint(37, -47, 2000, {.maxSpeed = 70}, false);
  // chassis.turnToPoint(28, -59, 500, {.maxSpeed = 60}, false);
  // chassis.moveToPoint(28, -59, 2000, {.maxSpeed = 70}, false);
  // chassis.turnToPoint(-28, -59, 500, {.maxSpeed = 60}, false);
  // chassis.moveToPoint(-28, -59, 4000, {.maxSpeed = 80}, false);
  // chassis.turnToPoint(-37, -47, 500, {.maxSpeed = 60}, false);
  // chassis.moveToPoint(-37, -47, 2000, {.maxSpeed = 70}, false);
  // chassis.turnToPoint(-30, -47, 500, {.maxSpeed = 60}, false);

   // drop tongue, move to loader, intake
  tonguePiston.set_value(false);
  bottomIntake.move(127);
  pros::delay(200);
  chassis.moveToPoint(-58, -47, 2500, {.maxSpeed = 70}, false);
  
  // move to long goal & score
  chassis.moveToPoint(-30, -47, 2000, {.forwards = false, .maxSpeed = 80}, false);
  bottomIntake.move(0);
  fullIntake.move(127);
  pros::delay(6000);
  fullIntake.move(0);
  tonguePiston.set_value(false);

  // move back and park
  chassis.moveToPoint(-40, -47, 1800, {.forwards = false, .maxSpeed = 70}, false);
  chassis.turnToPoint(-40, 0, 500, {.maxSpeed = 60}, false);
  chassis.moveToPoint(-40, 0, 3000, {.maxSpeed = 80}, false);
  chassis.turnToPoint(-62, 0, 500, {.maxSpeed = 60}, false);
  chassis.moveToPoint(-62, 0, 4000, {.maxSpeed = 70}, false);

}