
#include "ChargerManager.hpp"
#include "EVTOL.hpp"
#include <iostream>

// Test ChargerManager assignment and reporting
int main() {
    VehicleProfile profile = {100, 100, 1, 0.5, 4, 0};
    EVTOL e1(1, VehicleType::Alpha, profile);
    ChargerManager manager(2);

    manager.assignCharger(e1, 0);
    manager.update(1);
    manager.report();

    std::cout << "ChargerManager test passed\n";
    return 0;
}
