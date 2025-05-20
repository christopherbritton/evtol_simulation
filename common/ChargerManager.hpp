#pragma once
#include "EVTOL.hpp"
#include <vector>

// Manages available chargers and their assignments
class ChargerManager {
public:
    ChargerManager(int portCount);
    void assignCharger(EVTOL& evtol, int currentMinute);
    void update(int currentMinute);
    void report() const;

private:
    int availablePorts;
    std::vector<int> chargingEVTOLs;
};
