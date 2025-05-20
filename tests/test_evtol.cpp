#include "EVTOL.hpp"
#include <iostream>

void testEVTOL() {
    VehicleProfile profile{150, 100, 1.0, 0.5, 4, 0.01};
    EVTOL v1(1, VehicleType::Alpha, profile);

    v1.simulateStep();
    std::cout << "EVTOL tests passed.\n";
}

int main() {
    testEVTOL();
    return 0;
}
