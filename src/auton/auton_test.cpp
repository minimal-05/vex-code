#include "auton.hpp"
#include "../robot/robot_config.hpp"

void autonomoustest() {
    chassis.setPose(-47, -47, 0);
    chassis.moveToPoint(-47, 47, 2000, {.maxSpeed = 90}, false);
}