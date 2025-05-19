#include "FaultManager.hpp"
#include <iostream>
void FaultManager::recordFault(int evtolId, int faultCode) {
    faults.emplace_back(evtolId, faultCode); // amortized O(1)
}
void FaultManager::report() const {
    for (size_t i = 0; i < faults.size(); ++i) {
        std::cout << "EVTOL " << faults[i].first << " had fault code " << faults[i].second << "\n";
    }
}
