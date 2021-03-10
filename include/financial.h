#ifndef __FINANCIALS_H__
#define __FINANCIALS_H__

namespace Finance
{
    // Values
    double cableCost = 0.0f;
    double motorCost = 0.0f;
    double ExtraCost = 0.0f;
    double TotalCost = 0.0f;

    // Prices
    // Cables
    const double cablePrice = 0.0f;
    
    // Motors
    const double motorPrice = 0.0f;
    const double housingPrice = 0.0f;
    
    // Mechanical Extras
    const double counterweightPrice = 0.0f;
    const double cabinPrice = 0.0f;
    const double railingPrice = 0.0f;
    const double boltPrice = 0.0f;

    // Electrical Extras
    const double governerPrice = 0.0f;
    const double controllerPrice = 0.0f;
    const double selectorPrice = 0.0f;

    // Service
    const double contractPrice = 0.0f; // Labor cost

    // Functions
    double calcCableCost();
    double calcMotorCost();
    double calcExtraCost();
    double calcTotalCost();
}

#endif // __FINANCIALS_H__