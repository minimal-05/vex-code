#include "auton.hpp"
#include <string>

extern std::string autonSide;

void runAuton() {
  if (autonSide == "left") autonomousLeft();
  else if (autonSide == "right") autonomousRight();
  else if (autonSide == "awp") autonomousAWP();
  else if (autonSide == "skill") autonomousSkills();
  else if (autonSide == "test") autonomousTest();
}
