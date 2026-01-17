#include "main.h"
#include "robot/robot_config.hpp"
#include "auton/auton.hpp"
#include "driver/driver.hpp"

std::string autonSide = "skill"; // right, right-middle, left, awp, skill, test

void initialize() {
    pros::lcd::initialize();
    chassis.calibrate();
}

void autonomous() {
    runAuton();
}

void opcontrol() {
    runDriver();
}
