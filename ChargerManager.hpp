#pragma once
#include "EVTOL.hpp"
#include <vector>
// Manages available chargers and assignments
class ChargerManager {
public:
    ChargerManager(int portCount);            // Time: O(1), Space: O(1)
    void assignCharger(EVTOL& evtol);         // Time: O(1) amortized, Space: O(k)
    void update();                            // Time: O(k), Space: O(1)
    void report() const;                      // Time: O(1), Space: O(1)
private:
    int availablePorts;
    std::vector<int> chargingEVTOLs;
};
