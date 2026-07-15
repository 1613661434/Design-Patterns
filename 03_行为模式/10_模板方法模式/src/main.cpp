#include "Robot.hpp"

int main()
{
    AbstractRobot* robot = nullptr;
    robot = new Pacifist;
    robot->getProperty();
    delete robot;
    std::cout << "====================================" << std::endl;
    robot = new Seraphim;
    robot->getProperty();
    delete robot;
    return 0;
}
