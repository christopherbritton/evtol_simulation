#pragma once

#include "EVTOL.hpp"

class AlphaEVTOL : public EVTOL {
private:
    const double cruiseSpeed = 120.0;         // [mph]    - Max cruise speed
    const double batteryCapacity = 320.0;     // [kWh]    - Max battery energy
    const double chargeTime = 0.6;            // [hrs]    - Time to charge fully
    const double energyUsePerMile = 1.6;      // [kWh/mile] - Energy consumption rate
    const int passengerCount = 4;             // [count]  - Max passengers
    const double faultProbability = 0.25;     // [prob/hr] - Fault probability per flight hour

    double batteryLevel = batteryCapacity;    // [kWh]    - Current battery energy
    double chargeRate = batteryCapacity / chargeTime; // [kWh/hr] - Charging rate
    bool charging = false;                    // [bool]   - Charging state

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
    void resetBattery() override;
    int getPassengerCapacity() const override;
    const char* getType() const override;
    bool checkForFault() const override;
    double getRemainingBattery() const override;
};