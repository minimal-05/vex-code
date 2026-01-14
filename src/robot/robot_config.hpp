#pragma once
#include "main.h"
#include "lemlib/api.hpp"

// controller
extern pros::Controller controller;

// pistons
extern pros::adi::DigitalOut tonguePiston;
extern pros::adi::DigitalOut conveyorPiston;
extern pros::adi::DigitalOut wingPiston;

// motors
extern pros::MotorGroup left_mg;
extern pros::MotorGroup right_mg;
extern pros::Motor bottomIntake;
extern pros::Motor topIntake;
extern pros::MotorGroup fullIntake;

// sensors
extern pros::Imu imu;
extern pros::Rotation vertical_rotation_sensor;

// lemlib
extern lemlib::Drivetrain drivetrain;
extern lemlib::TrackingWheel vertical_tracking_wheel;
extern lemlib::OdomSensors sensors;
extern lemlib::Chassis chassis;
