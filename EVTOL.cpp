
#include "EVTOL.hpp"
#include <cstdlib>

// Constructor with profile
EVTOL::EVTOL(int id, VehicleType type, const VehicleProfile& profile)
    : id(id), type(type), profile(profile), fault(false), chargingNeeded(false), faultCode(0) {}

bool EVTOL::coinFlip(int odds) {
    return (std::rand() % odds) == 0;
}

void EVTOL::simulateStep() {
    fault = coinFlip(10);
    chargingNeeded = coinFlip(3);
    faultCode = fault ? (100 + std::rand() % 50) : 0;
}

bool EVTOL::hasFault() const { return fault; }
bool EVTOL::needsCharging() const { return chargingNeeded; }
int EVTOL::getId() const { return id; }
VehicleType EVTOL::getType() const { return type; }
int EVTOL::getFaultCode() const { return faultCode; }


// Simulate charging by toggling chargingNeeded state
void EVTOL::startCharging(int currentMinute) {
    chargingNeeded = false;
}
