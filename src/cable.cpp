#include <cable.h>
#include <utility.h>
#include <iostream>

// Calculate cross-sectional area of the cable with radius 'radius'
bool Cable::calcArea()
{
    if (area = (Util::PI * radius * radius))
        return true;
    else
        return false;
}

// Calculate stress from cable load and area
double Cable::calcStress()
{
    // sig = F/A

    stress = (load / area);

    return stress;
}

// Calculate strain from stress & elastic modulus
// Make sure to calculate the stress first before calculating strain
double Cable::calcStrain()
{
    // sig = Ee

    strain = stress / elasticModulus;

    return strain;
}

// Check to see if the cable meets the safety requirements
bool Cable::meetSafetyFactor()
{
    if ( (load * safetyFactor >= maxCableLoad) && (normalOperatingLoad >= maxCableLoad / safetyFactor) )
        return false;

    return true;
}

// Driver function
bool Cable::driver()
{
    // Returns false if a subsequent value was not calculated properly

    std::cout << "Please enter the required values (radius, load, elastic modulus): ";
    std::cin >> radius >> load >> elasticModulus;

    if (!Cable::calcArea())
    {
        std::cout << "Error. Area was not calculated.\n";
        return false;
    }

    if (!Cable::calcStress())
    {
        std::cout << "Error. Stress was not calculated.\n";
        return false;
    }

    if (!Cable::calcStrain())
    {
        std::cout << "Error. Strain was not calculated.\n";
        return false;
    }

    return true;
}

// Output function
bool Cable::output()
{
    // Print values to console

    return true;
}