#include "driver.hpp"
#include "../robot/robot_config.hpp"

void runDriver() {
    static int direction = -1;
    static bool lastX = false;

    static bool tongueState = false;
    static bool conveyorState = false;
    static bool wingState = true;

    while (true) {
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

        // deadzone
        if (abs(rightX) < 10) rightX = 0;
        if (abs(leftY) < 10) leftY = 0;

        // base turn sensitivity
        //double baseTurn = 0.68;
        //rightX *= baseTurn;

        // apply inversion
        leftY *= direction;

        chassis.curvature(leftY, rightX);

        // intake controls
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
            bottomIntake.move(127);
        } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) {
            topIntake.move(127);
            bottomIntake.move(127);
        } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
            topIntake.move(-127);
            bottomIntake.move(-127);
        } else {
            topIntake.move(0);
            bottomIntake.move(0);
        }

        // pistons
        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
            conveyorState = !conveyorState;
            conveyorPiston.set_value(conveyorState);
        }

        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)) {
            tongueState = !tongueState;
            tonguePiston.set_value(tongueState);
        }

        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)) {
            wingState = !wingState;
            wingPiston.set_value(wingState);
        }

        // invert throttle button (X)
        bool xPressed = controller.get_digital(pros::E_CONTROLLER_DIGITAL_X);
        if (xPressed && !lastX) {
            direction = -direction;
        }
        lastX = xPressed;

        pros::delay(25);
    }
}
