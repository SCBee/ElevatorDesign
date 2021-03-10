#include <motor.h>
#include <utility.h>
#include <cmath>
#include <iostream>

// Calculate electrical power output of the armature
bool Motor::calcArmaturePower() 
{
    // Power = V*I - R*I^2

    if (armaturePower = voltage * current - resistance * std::pow(current, 2))
        return true;
    
    return false;
}

// Calculate electrical power loss of the armature (brushings)
bool Motor::calcArmaturePowerLoss()
{
    if (armaturePowerLoss = resistance * std::pow(current, 2))
        return true;

    return false;
}

// Calculate voltage of the armature
bool Motor::calcBackEMF() 
{
    if (armatureVoltage = voltage - current * resistance)
        return true;
    
    return false;
}

// Calculate the power input
bool Motor::calcPowerIn() 
{
    if (powerIn = voltage * current)
        return true;

    return false;
}

// Calculate the power output
bool Motor::calcPowerOut() 
{
    // Power Out = Torque * rad/s
    if (powerOut = loadTorque * angularVelocity)
        return true;

    return false;
}

// Calculate load torque
bool Motor::calcLoadTorque()
{
    // Load Torque = mass * gravity * radius
    if (loadTorque = mass * Util::GRAVITY * radius)
        return true;
    
    return false;
}

// Calculate acceleration torque
bool Motor::calcAccelerationTorque() 
{
    // Need to find equation for this

    return false;
}

// Calculate angular velocity of the spool that the motor is driving
bool Motor::calcAngularVelocity()
{
    if (angularVelocity = speed / (radius))
        return true;
    
    return false;
}

// Calculte total torque that the motor needs to output
bool Motor::calcTotalTorque()
{
    if (totalTorque = angularVelocity + accelerationTorque)
        return true;

    return false;
}

// Check to see if the motor meets the safety requirement
bool Motor::meetSafetyFactor()
{
    if ((maxTorqueRating > totalTorque * safetyFactor) && (maxTorqueRating > normalOperatingTorque * safetyFactor)) 
        return true;

    return false;
}

// Calculate efficiency of motor from output torque to electrical power in
double Motor::calcEfficiency()
{
    return (powerOut - powerIn) / powerIn;
}

// Driver function
bool Motor::driver()
{
    // Returns false if a subsequent value was not calculated properly

    std::cout << "Please enter the required mechanical values (radius, mass, speed): ";
    std::cin >> radius >> mass >> speed;

    std::cout << "Please enter the required electrical values (voltage, current, resistance): ";
    std::cin >> voltage >> current >> resistance;

    // Call all the calculation functions
    // ...
    // ...
    //

    return true;
}

// Output function
bool Motor::output()
{
    // Print values to console;

    return true;
}