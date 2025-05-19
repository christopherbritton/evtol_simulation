
#include "EVTOL.hpp"
#include <cassert>
#include <iostream>

// Basic functional test for EVTOL class update behavior
int main() {
    VehicleProfile profile = {100, 100, 1, 1, 1, 0};
    EVTOL e(1, VehicleType::Alpha, profile);
    for (int i = 0; i < 60; ++i) {
        e.simulateStep();
    }
    assert(e.getId() == 1);
    std::cout << "EVTOL test passed\n";
    return 0;
}
