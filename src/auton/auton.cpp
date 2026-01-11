#include "auton.hpp"
#include <string>

extern std::string autonSide;

void runAuton() {
  if (autonSide == "left") autonomousLeft();
  else if (autonSide == "right") autonomousRight();
  else if (autonSide == "right-middle") autonomousRightMiddle();
  else if (autonSide == "full") autonomousAWP();
  else if (autonSide == "skills") autonomousSkills();
}
