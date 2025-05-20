#pragma once
#include "VehicleType.hpp"
#include "VehicleProfile.hpp"

// Represents an EVTOL vehicle and its runtime state
class EVTOL {
public:
    // Full constructor
    EVTOL(int id, VehicleType type, const VehicleProfile& profile);

    void simulateStep();                   // Random state update
    bool hasFault() const;                 // Fault state
    bool needsCharging() const;           // Charging needed
    bool isCharging() const;              // Actively charging
    int getId() const;
    VehicleType getType() const;
    int getFaultCode() const;
    void startCharging(int currentMinute);

    // New accessors
    const VehicleProfile& getProfile() const;
    double getCruiseSpeed() const;
    int getPassengerCapacity() const;

private:
    int id;
    VehicleType type;
    VehicleProfile profile;
    bool fault;
    bool chargingNeeded;
    int faultCode;

    // Helper for randomized decisions
    bool coinFlip(int odds);
};

