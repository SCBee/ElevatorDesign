#include <main.h>
#include <iostream>

int main(int, char**)
{
    // Call driving functions
    //motor.driver();
    //cable.driver();

    // Output
    //motor.output();
    //cable.output();

    motor.calcLoadTorque();
    motor.calcAccelerationTorque();
    motor.calcTotalTorque();

    std::cout << "Load Torque: " << motor.getLoadTorque() << "\nAcceleration Torque: "
                << motor.getAccelerationTorque() << "\nTotal Torque: " << motor.getTotalTorque() << "\n";



    return 0;
}
