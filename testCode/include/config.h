#include <iostream>
#include "main.h"
#include "lemlib/api.hpp"
#include "api.h"

extern pros::Controller controller;

extern pros::Motor L1;
extern pros::Motor L2;
extern pros::Motor L3;
extern pros::Motor_Group LeftDrive;

extern pros::Motor R1;
extern pros::Motor R2;
extern pros::Motor R3;
extern pros::Motor_Group RightDrive;

extern pros::Imu inertial; 

extern lemlib::OdomSensors_t sensors; 

extern lemlib::ChassisController_t lateralController; 
extern lemlib::ChassisController_t angularController; 

extern lemlib::Chassis chassis;