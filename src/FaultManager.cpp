#include "FaultManager.hpp"
#include <iostream>

void FaultManager::recordFault(int evtolId, int faultCode) {
    faults.emplace_back(evtolId, faultCode);
}

void FaultManager::report() const {
    std::cout << "\n--- Fault Report ---\n";
    for (size_t i = 0; i < faults.size(); ++i) {
        std::cout << "EVTOL " << faults[i].first << " Fault Code: " << faults[i].second << "\n";
    }
}
