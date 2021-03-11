#ifndef __MOTOR_H__
#define __MOTOR_H__

// The `Motor` class defines the paramters and functions available
// for the static analysis of the motor and its housing.

// The functions are self-documenting but a more verbose description
// has been added to the function definitions in the `motor.cpp` file.

// All parameters are in SI units.
// Assumption(s):
//      1) Motor has a set output speed from design requirements
//      2) Motor is DC
//      3) Motor has predetermined:
//          a) voltage
//          b) current
//          c) resistance
//          d) radius
//          e) mass
//          f) speed
//      4) Normal operating torque of motor is: 
//      5) Max torque of motor is: 
// Safety Factor(s):
//      1) Motor should be able to drive at least 40% higher load/torque than normal operating load/torque
//      2) Counterweight is 1840 kg

#include <utility.h>

class Motor
{
    const double safetyFactor = 1.4f;

    // Electrical Values (Calculated during operation)
    double armaturePower = 0.0f; // watts
    double armaturePowerLoss = 0.0f; // watts
    double powerIn = 0.0f; // watts
    double powerOut = 0.0f; // watts

    // Mechanical Values (Calculated during operation)
    double totalTorque = 0.0f; // Nm, joules
    double loadTorque = 0.0f; // Nm, joules
    Util::Vec3D accelerationTorque {}; // Nm, joules
    double accelTorqueNormalized = 0.0f;
    double angularVelocity = 0.0f; // rad/s

    // Mechanical Parameters (REQUIRED)
    double maxTorqueRating = 0.0f; // Nm, joules (Change this to the assumption)
    double normalOperatingTorque = 0.0f; // Nm, joules (Change this to the assumption)
    double radius = 0.381f; // meters
    double idlerRadius = 0.0f; // meters
    double mass = 1840.0f; // kg ()
    double speed = 10.0f; // m/s

    // Electrical Parameters (REQUIRED)
    double voltage = 0.0f; // volts
    double current = 0.0f; // amperes
    double resistance = 0.0f; // ohms
    double armatureVoltage = 0.0f; // back-emf, volts

public:
#pragma region CONSTRUCTORS
    // Constructors
    Motor() {}

    Motor(double V, double I, double R, double e)
    {
        // Constructed with Electrical parameters
        voltage = V;
        current = I;
        resistance = R;
        armatureVoltage = e;
    }
#pragma endregion // CONSTRUCTORS

#pragma region GS
    // G&S
    double getVoltage(){ return voltage; }
    double getCurrent(){ return current; }
    double getResistance(){ return resistance; }
    double getArmatureVoltage(){ return armatureVoltage; }
    double getArmaturePower(){ return armaturePower; }
    double getArmaturePowerLoss(){ return armaturePowerLoss; }
    double getLoadTorque(){ return loadTorque; }
    double getPowerIn(){ return powerIn; }
    double getPowerOut(){ return powerOut; }
    double getAccelerationTorque(){ return accelTorqueNormalized; }
    double getTotalTorque(){ return totalTorque; }
    double getAngularVelocity(){ return angularVelocity; }

    bool setVoltage(double V)
    {
        if (voltage = V)
            return true;

        return false;
    }

    bool setCurrent(double I)
    {
        if (current = I)
            return true;
        
        return false;
    }

    bool setResistance(double R)
    {
        if (resistance = R)
            return true;
        
        return false;
    }

    bool setArmatureVoltage(double e)
    {
        if (armatureVoltage = e)
            return true;

        return false;
    }
#pragma endregion // GS

    // Functions
    bool calcArmaturePower();
    bool calcArmaturePowerLoss();
    bool calcBackEMF();
    bool calcPowerIn();
    bool calcPowerOut();
    bool calcLoadTorque();
    bool calcAccelerationTorque();
    bool calcAngularVelocity();
    bool calcTotalTorque();
    bool meetSafetyFactor();
    double calcEfficiency();

    // Driver & Output
    bool driver();
    bool output();
};

#endif // __MOTOR_H__