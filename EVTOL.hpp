
#pragma once
#include "VehicleType.hpp"
#include "VehicleProfile.hpp"

// Represents an EVTOL vehicle and its runtime state
class EVTOL {
public:
    EVTOL(int id, VehicleType type, const VehicleProfile& profile); // Full constructor

    void simulateStep();     // Random state update
    bool hasFault() const;   // Fault state
    bool needsCharging() const; // Charging status
    int getId() const;
    VehicleType getType() const;
    int getFaultCode() const;
    void startCharging(int currentMinute);

private:
    int id;
    VehicleType type;
    VehicleProfile profile;
    bool fault;
    bool chargingNeeded;
    int faultCode;

    bool coinFlip(int odds); // Helper for randomized decisions
};
