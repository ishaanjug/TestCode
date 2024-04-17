#include "main.h"
#include "config.h"
#include "lemlib/api.hpp"
#include <iostream>

pros::Motor L1(10, pros::E_MOTOR_GEARSET_06, true);
pros::Motor L2(8, pros::E_MOTOR_GEARSET_06, true);
pros::Motor L3(6, pros::E_MOTOR_GEARSET_06, true);
pros::MotorGroup LeftDrive({L1, L2, L3});

pros::Motor R1(12, pros::E_MOTOR_GEARSET_06, true);
pros::Motor R2(13, pros::E_MOTOR_GEARSET_06, true);
pros::Motor R3(14, pros::E_MOTOR_GEARSET_06, true);
pros::MotorGroup RightDrive({R1, R2, R3});

lemlib::Drivetrain_t drivetrain {
    &LeftDrive, // left drivetrain motors
    &RightDrive, // right drivetrain motors
    10, // track width
    2.75, // wheel diameter
    450 // wheel rpm
};
 
// inertial sensor
pros::Imu inertial(2); // port 2
 
// odometry struct
lemlib::OdomSensors_t sensors {
    nullptr, // vertical tracking wheel 1
    nullptr, // vertical tracking wheel 2
    nullptr, // horizontal tracking wheel 1
    nullptr, // we don't have a second tracking wheel, so we set it to nullptr
    &inertial // inertial sensor
};

// forward/backward PID
lemlib::ChassisController_t lateralController {
    8, // kP
    30, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    5 // slew rate
};
 
// turning PID
lemlib::ChassisController_t angularController {
    4, // kP
    40, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    0 // slew rate
};

lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors); 