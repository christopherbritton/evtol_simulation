#include "EVTOL.hpp"
#include <cstdlib>     // for std::rand
#include <ctime>       // for std::time

// Full constructor for EVTOL
EVTOL::EVTOL(int id, VehicleType type, const VehicleProfile& profile)
    : id(id), type(type), profile(profile), fault(false), chargingNeeded(false), faultCode(0) {
    // Optionally seed randomness here if not already seeded globally
}

// Simulates one step: randomly determines fault and charging need
void EVTOL::simulateStep() {
    fault = coinFlip(10);           // ~1 in 10 chance
    chargingNeeded = coinFlip(3);   // ~1 in 3 chance
    if (fault) {
        faultCode = 100 + (std::rand() % 50);  // Random fault code between 100–149
    }
}

// Getter for fault status
bool EVTOL::hasFault() const {
    return fault;
}

// Getter for whether charging is needed
bool EVTOL::needsCharging() const {
    return chargingNeeded;
}

// Getter for current charging state
bool EVTOL::isCharging() const {
    return chargingNeeded;
}

// Begin charging — resets flag (you may enhance for time tracking)
void EVTOL::startCharging(int /*currentMinute*/) {
    chargingNeeded = false;
}

// ID getter
int EVTOL::getId() const {
    return id;
}

// Type getter
VehicleType EVTOL::getType() const {
    return type;
}

// Fault code getter
int EVTOL::getFaultCode() const {
    return faultCode;
}

// Profile accessor
const VehicleProfile& EVTOL::getProfile() const {
    return profile;
}

// Cruise speed getter
double EVTOL::getCruiseSpeed() const {
    return profile.cruiseSpeed;
}

// Passenger capacity getter
int EVTOL::getPassengerCapacity() const {
    return static_cast<int>(profile.batteryCapacity / 25.0); // Example derived logic
}

// Private helper for coin flip logic
bool EVTOL::coinFlip(int odds) {
    return (std::rand() % odds) == 0;
}
