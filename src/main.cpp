#include "main.h"
#include "robot/robot_config.hpp"
#include "auton/auton.hpp"
#include "driver/driver.hpp"

std::string autonSide = "right-middle";

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
