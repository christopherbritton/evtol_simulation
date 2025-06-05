#pragma once

#include "EVTOL.hpp"

class EchoEVTOL : public EVTOL {
private:
    // Vehicle specifications with physical units
    const double cruiseSpeed = 30.0;          // [mph] - Maximum cruising speed
    const double batteryCapacity = 150.0;      // [kWh] - Maximum energy storage
    const double chargeTime = 0.3;             // [hrs] - Time to full charge
    const double energyUsePerMile = 5.8;       // [kWh/mile] - Energy consumption per mile
    const int passengerCount = 2;              // [count] - Seating capacity
    const double faultProbability = 0.61;      // [prob/hr] - Probability of failure per flight hour

    // Runtime operational state
    double batteryLevel = batteryCapacity;     // [kWh] - Current energy remaining
    double chargeRate = batteryCapacity / chargeTime; // [kWh/hr] - Charging rate
    bool charging = false;                     // [flag] - Whether currently charging
    bool faultActive = false;                 // Forces fault condition

public:
    // Core behaviors
    void fly(double hours) override;
    void charge() override;
    bool needsCharge() const override;

    // Accessors
    double getCruiseSpeed() const override;
    double getBatteryCapacity() const override;
    double getChargeTime() const override;
    double getEnergyUsePerMile() const override;
    int getPassengerCount() const override;
    double getFaultProbabilityPerHour() const override;

    // Interface extensions
    bool isCharging() const override;
    double getChargeRate() const override;
    double getBatteryLevel() const override;
    void charge(double hours) override;

    // Reset and utility
    void resetBattery() override;
    int getPassengerCapacity() const override;
    const char* getType() const override;
    bool checkForFault() const override;
    double getRemainingBattery() const override;
    void injectFault() override;
};
