#ifndef __CABLE_H__
#define __CABLE_H__

// The `Cable` class defines the paramters and functions available
// for the static analysis of the elevator cable.

// The functions are self-documenting but a more verbose description
// has been added to the function definitions in the `cable.cpp` file.

// All parameters are in SI units.
// Assumption(s):
//      1) Cable is not changing radius significantly during operation
//      2) Cable has pre-determined material properties (e.g., elastic mod)
//      3) Normal operating load is: 
//      4) Max cable load rating is: 
// Safety Factor(s):
//      1) Cable should be able to withstand at least 40% more of normal operating load
//      2) Counterweight is 1840 kg

class Cable
{
    const double safetyFactor = 1.4f;

    // Calculated during operation
    double stress = 0.0f; // Pa
    double strain = 0.0f; // dimensionless
    double area = 0.0f; // m^2

    // Required Parameters
    double radius = 0.0f; // m
    double load = 0.0f; // N
    double elasticModulus = 0.0f; // Pa
    const double normalOperatingLoad = 3000.0f; // kg (change this based on assumption)
    const double maxCableLoad = 5000.0f; // kg (change this based on assumption)
    const double counterweightRatio = 0.40f; // Percent of normal operating load that the counterweight weighs, %
    const double counterweight = normalOperatingLoad * counterweightRatio; // kg

public:

#pragma region CONSTRUCTORS
    Cable() // Empty
    {
        radius = 0.0f;
        load = 0.0f;
        elasticModulus = 0.0f;
    }
    Cable(double r, double F, double E)
    {
        radius = r;
        load = F;
        elasticModulus = E;
    }
#pragma endregion // CONSTRUCTORS

#pragma region GS
    double getRad(){ return radius; }
    double getLoad(){ return load; }
    double getElasticModulus(){ return elasticModulus; }
    double getArea(){ return area; }

    bool setRad(double r)
    {
        if (radius = r)
            return true;
        else
            return false;
    }

    bool setLoad(double F)
    {
        if (load = F)
            return true;
        else
            return false;
    }

    bool setElasticModulus(double E)
    {
        if (elasticModulus = E)
            return true;
        else
            return false;
    }
#pragma endregion // GS

    // Functions
    bool calcArea();
    double calcStress();
    double calcStrain();
    bool meetSafetyFactor();

    // Driver & Output
    bool driver();
    bool output();
};

#endif // __CABLE_H__