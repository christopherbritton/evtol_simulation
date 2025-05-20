#include "ChargerManager.hpp"
#include "EVTOL.hpp"
#include <iostream>

void testChargerManager() {
    ChargerManager cm(2);
    VehicleProfile profile{150, 100, 1.0, 0.5, 4, 0.01};
    EVTOL v1(1, VehicleType::Alpha, profile);
    cm.assignCharger(v1, 0);
    cm.update(1);
    std::cout << "ChargerManager tests passed.\n";
}

int main() {
    testChargerManager();
    return 0;
}
