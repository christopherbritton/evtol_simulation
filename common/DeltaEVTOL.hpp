#pragma once

#include "EVTOL.hpp"

class DeltaEVTOL : public EVTOL {
private:
    // Vehicle specification parameters (all constants)
    const double cruiseSpeed = 90.0;          // [mph]
    const double batteryCapacity = 120.0;     // [kWh]
    const double chargeTime = 0.62;           // [hrs]
    const double energyUsePerMile = 0.8;      // [kWh/mile]
    const int passengerCount = 2;             // [count]
    const double faultProbability = 0.22;     // [prob/hr]

    // Internal state variables
    double batteryLevel = batteryCapacity;            // [kWh]
    double chargeRate = batteryCapacity / chargeTime; // [kWh/hr]
    bool charging = false;                            // Charging state flag
    bool faultActive = false;                 // Forces fault condition

public:
    // Core behaviors
    void fly(double hours) override;         // Simulate flight
    void charge() override;                  // Initiate charging
    bool needsCharge() const override;       // Determine if charging is needed

    // Accessors
    double getCruiseSpeed() const override;              // [mph]
    double getBatteryCapacity() const override;          // [kWh]
    double getChargeTime() const override;               // [hrs]
    double getEnergyUsePerMile() const override;         // [kWh/mile]
    int getPassengerCount() const override;              // [count]
    double getFaultProbabilityPerHour() const override;  // [prob/hr]

    // Interface extensions
    bool isCharging() const override;                    // Charging state
    double getChargeRate() const override;               // [kWh/hr]
    double getBatteryLevel() const override;             // [kWh]
    void charge(double hours) override;                  // Charge for a duration

    // Maintenance & reporting
    void resetBattery() override;                        // Reset battery to full
    int getPassengerCapacity() const override;           // Alias for getPassengerCount
    const char* getType() const override;                // Return vehicle type string
    bool checkForFault() const override;                 // Simulate fault occurrence
    double getRemainingBattery() const override;         // [kWh] remaining capacity
    void injectFault() override;
};
