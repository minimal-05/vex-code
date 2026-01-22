#include "auton.hpp"
#include "../robot/robot_config.hpp"

void fromtheside() {
  // set starting position for middle
  chassis.setPose(-63, -17.5, 0);
  tonguePiston.set_value(true); // lifts tongue
  

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
  wingPiston.set_value(true);

  // move to ball
  bottomIntake.move(127);
  chassis.moveToPoint(-65, 0, 700, {.maxSpeed = 70}, false);
  chassis.moveToPoint(-54, 0, 600, {.forwards = false, .maxSpeed = 90}, true);
  // pros::delay(200);
  // bottomIntake.move(-127);
  // pros::delay(80);
  // bottomIntake.move(127);
  chassis.moveToPoint(-65, 0, 1000, {.maxSpeed = 100}, false);
  chassis.moveToPoint(-54, 0, 700, {.forwards = false, .maxSpeed = 90}, true);
  // pros::delay(200);
  // bottomIntake.move(-127);
  // pros::delay(80);
  // bottomIntake.move(127);
  chassis.moveToPoint(-65, 1, 1000, {.maxSpeed = 100}, false);
  chassis.moveToPoint(-54, 0, 700, {.forwards = false, .maxSpeed = 90}, true);
  chassis.moveToPoint(-65, -1, 1000, {.maxSpeed = 100}, false);
  chassis.moveToPoint(-54, 0, 700, {.forwards = false, .maxSpeed = 90}, true);

  chassis.moveToPoint(-43, 0, 2000, {.forwards = false, .maxSpeed = 90}, false);
  bottomIntake.move(0);
  chassis.moveToPoint(-50, 0, 1500, {.maxSpeed = 60}, false);
  chassis.setPose(-45.5, 0, 270);

  chassis.moveToPoint(-22.5, 0, 1000, {.forwards = false, .maxSpeed = 80}, false);
  chassis.turnToPoint(-19.5, 19, 500, {.maxSpeed = 80}, false);
  bottomIntake.move(127);
  chassis.moveToPoint(-19.5, 19, 1500, {.maxSpeed = 80}, true);
  pros::delay(430);
  tonguePiston.set_value(false);

  chassis.turnToPoint(-6.5, 6.5, 500, { .forwards = false, .maxSpeed = 80, }, false);
  chassis.moveToPoint(-6.5, 6.5, 800, { .forwards = false, .maxSpeed = 70, }, false);
  conveyorPiston.set_value(true);
  bottomIntake.move(-127);
  pros::delay(80);
  bottomIntake.move(0);
  fullIntake.move(127);
  pros::delay(3000);
  fullIntake.move(0);
  conveyorPiston.set_value(false);
}

void middle() {

  // set starting position for middle
  chassis.setPose(-43.586, 7.176, 51.961);
  tonguePiston.set_value(true); // lifts tongue
  wingPiston.set_value(true);

  bottomIntake.move(127);
  chassis.moveToPoint(-24, 22.5, 800, {.maxSpeed = 80}, true);
  pros::delay(450);
  bottomIntake.move(0);
  chassis.turnToPoint(-6.5, 6.5, 600, {.forwards = false, .maxSpeed = 80}, false);
  chassis.moveToPoint(-6.5, 6.5, 1000, {.forwards = false, .maxSpeed = 60}, false);
  conveyorPiston.set_value(true);
  bottomIntake.move(0);
  fullIntake.move(127);
  pros::delay(500);
  fullIntake.move(0);
  conveyorPiston.set_value(false);


}

void autonomousSkills() {  // need the odometry to not get stuck

  // fromthefront();
  // fromtheside();
  middle();

  // move to goal & align
  chassis.moveToPoint(-47, 47, 1800, {.maxSpeed = 90}, false);
  chassis.turnToPoint(-58, 47, 800, {.maxSpeed = 80}, false);

  // drop tongue, move to loader, intake
  tonguePiston.set_value(false);
  pros::delay(400);
  chassis.moveToPoint(-58, 47, 4000, {.maxSpeed = 70}, false);

  
  // move to other side
  chassis.moveToPoint(-47, 47, 700, {.forwards = false, .maxSpeed = 90}, false);
  tonguePiston.set_value(true);
  chassis.turnToPoint(-37, 59, 700, {.maxSpeed = 80}, false);
  chassis.moveToPoint(-37, 59, 2000, {.maxSpeed = 90}, false);
  chassis.turnToPoint(32, 59, 500, {.maxSpeed = 80}, false);
  chassis.moveToPoint(32, 59, 4000, {.maxSpeed = 100}, false);
  chassis.turnToPoint(39, 47, 400, {.maxSpeed = 80}, false);
  chassis.moveToPoint(39, 47, 2000, {.maxSpeed = 90}, false);
  chassis.turnToPoint(24, 47, 500, {.forwards = false, .maxSpeed = 80}, false);

  // move to long goal & score
  chassis.moveToPoint(24, 47, 700, {.forwards = false, .maxSpeed = 80}, false);
  tonguePiston.set_value(true);
  bottomIntake.move(-127);
  pros::delay(100);
  bottomIntake.move(0);
  fullIntake.move(127);
  pros::delay(4000);
  fullIntake.move(0);

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

  // // go out and get tube
  // chassis.moveToPoint(19, 19, 1000, {.forwards = false, .maxSpeed = 70}, false);
  // chassis.turnToPoint(42, -47, 500, {.maxSpeed = 60}, false);
  // bottomIntake.move(127);
  // chassis.moveToPoint(42, -47, 5000, {.maxSpeed = 80}, false);
  // chassis.turnToPoint(58, -47, 500, {.maxSpeed = 60}, false);

  // // drop tongue, move to loader, intake
  // tonguePiston.set_value(true);
  // pros::delay(200);
  // chassis.moveToPoint(58, -47, 2500, {.maxSpeed = 60}, false);

  // // move to long goal & score
  // chassis.moveToPoint(30, -47, 2000, {.forwards = false, .maxSpeed = 80}, false);
  // bottomIntake.move(0);
  // fullIntake.move(127);
  // pros::delay(6000);
  // fullIntake.move(0);
  // tonguePiston.set_value(false);
  
  // // move to other side
  // // chassis.moveToPoint(37, -47, 2000, {.maxSpeed = 70}, false);
  // // chassis.turnToPoint(28, -59, 500, {.maxSpeed = 60}, false);
  // // chassis.moveToPoint(28, -59, 2000, {.maxSpeed = 70}, false);
  // // chassis.turnToPoint(-28, -59, 500, {.maxSpeed = 60}, false);
  // // chassis.moveToPoint(-28, -59, 4000, {.maxSpeed = 80}, false);
  // // chassis.turnToPoint(-37, -47, 500, {.maxSpeed = 60}, false);
  // // chassis.moveToPoint(-37, -47, 2000, {.maxSpeed = 70}, false);
  // // chassis.turnToPoint(-30, -47, 500, {.maxSpeed = 60}, false);

  //  // drop tongue, move to loader, intake
  // tonguePiston.set_value(false);
  // bottomIntake.move(127);
  // pros::delay(200);
  // chassis.moveToPoint(-58, -47, 2500, {.maxSpeed = 70}, false);
  
  // // move to long goal & score
  // chassis.moveToPoint(-30, -47, 2000, {.forwards = false, .maxSpeed = 80}, false);
  // bottomIntake.move(0);
  // fullIntake.move(127);
  // pros::delay(6000);
  // fullIntake.move(0);
  // tonguePiston.set_value(false);

  // // move back and park
  // chassis.moveToPoint(-40, -47, 1800, {.forwards = false, .maxSpeed = 70}, false);
  // chassis.turnToPoint(-40, 0, 500, {.maxSpeed = 60}, false);
  // chassis.moveToPoint(-40, 0, 3000, {.maxSpeed = 80}, false);
  // chassis.turnToPoint(-62, 0, 500, {.maxSpeed = 60}, false);
  // chassis.moveToPoint(-62, 0, 4000, {.maxSpeed = 70}, false);

}