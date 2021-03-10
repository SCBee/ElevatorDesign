#include <main.h>
#include <iostream>

int main(int, char**)
{
    // Call driving functions
    motor.driver();
    cable.driver();

    // Output
    motor.output();
    cable.output();

    return 0;
}
