#include "robot_config.hpp"
#include "../pid/pid.hpp"

// controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// pistons
pros::adi::DigitalOut tonguePiston('B', false);
pros::adi::DigitalOut conveyorPiston('C', false);
pros::adi::DigitalOut wingPiston('A', true);

// motors
pros::MotorGroup left_mg({15, -14, -13}, pros::MotorGearset::blue);
pros::MotorGroup right_mg({3, -2, 1}, pros::MotorGearset::blue);
pros::Motor bottomIntake(-12);
pros::Motor topIntake(-11);
pros::MotorGroup fullIntake({-12, -11});

// sensors
pros::Imu imu(19);
pros::Rotation horizontal_rotation_sensor(16);
pros::Rotation vertical_rotation_sensor(17);

// drivetrain
lemlib::Drivetrain drivetrain(
    &left_mg,
    &right_mg,
    14.5,
    lemlib::Omniwheel::NEW_325,
    450,
    2
);

// tracking wheels
lemlib::TrackingWheel horizontal_tracking_wheel(
    &horizontal_rotation_sensor,
    lemlib::Omniwheel::NEW_2,
    0
);

lemlib::TrackingWheel vertical_tracking_wheel(
    &vertical_rotation_sensor,
    lemlib::Omniwheel::NEW_2,
    1
);

// odometry
lemlib::OdomSensors sensors(
    &vertical_tracking_wheel,
    nullptr,
    &horizontal_tracking_wheel,
    nullptr,
    &imu
);

// chassis
lemlib::Chassis chassis(
    drivetrain,
    lateral_controller,
    angular_controller,
    sensors
);
