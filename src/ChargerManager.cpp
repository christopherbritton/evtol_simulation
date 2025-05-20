
#include "ChargerManager.hpp"
#include "EVTOL.hpp"
#include <iostream>

ChargerManager::ChargerManager(int portCount) : availablePorts(portCount) {}

void ChargerManager::assignCharger(EVTOL& evtol, int currentMinute) {
    if (availablePorts > 0 && evtol.needsCharging()) {
        evtol.startCharging(currentMinute);
        chargingEVTOLs.push_back(evtol.getId());
        --availablePorts;
    }
}

void ChargerManager::update(int currentMinute) {
    // Placeholder: simulate some chargers finishing
    int totalPorts = availablePorts + chargingEVTOLs.size();
    availablePorts = totalPorts - chargingEVTOLs.size(); // No real logic
}

void ChargerManager::report() const {
    std::cout << "\n--- Charger Status ---\n";
    std::cout << "Available ports: " << availablePorts << "\n";
    std::cout << "Charging EVTOLs: ";
    for (int id : chargingEVTOLs) {
        std::cout << id << " ";
    }
    std::cout << "\n";
}
