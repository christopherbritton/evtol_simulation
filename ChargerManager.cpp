#include "ChargerManager.hpp"
#include <iostream>
ChargerManager::ChargerManager(int portCount) : availablePorts(portCount) {}
void ChargerManager::assignCharger(EVTOL& evtol) {
    if (availablePorts > 0) {
        chargingEVTOLs.push_back(evtol.getId()); // amortized O(1)
        --availablePorts;
        std::cout << "Assigned charger to EVTOL " << evtol.getId() << "\n";
    } else {
        std::cout << "No chargers available for EVTOL " << evtol.getId() << "\n";
    }
}
void ChargerManager::update() {
    availablePorts += chargingEVTOLs.size(); // Time: O(k)
    chargingEVTOLs.clear();
}
void ChargerManager::report() const {
    std::cout << "Available charging ports: " << availablePorts << "\n";
}
