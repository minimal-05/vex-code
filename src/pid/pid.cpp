#include "pid.hpp"

lemlib::ControllerSettings lateral_controller(11, // proportional gain (kP)
                                              0.003, // integral gain (kI)
                                              60, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in inches
                                              300, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              30 // maximum acceleration (slew)
);

// angular PID controller
lemlib::ControllerSettings angular_controller(4, // proportional gain (kP)
                                              0.001, // integral gain (kI)
                                              45, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in degrees
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in degrees
                                              500, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);