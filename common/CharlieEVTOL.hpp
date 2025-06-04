#pragma once

#include "EVTOL.hpp"

class CharlieEVTOL : public EVTOL {
private:
    const double cruiseSpeed = 160.0;            // [mph]
    const double batteryCapacity = 220.0;        // [kWh]
    const double chargeTime = 0.8;               // [hrs]
    const double energyUsePerMile = 2.2;         // [kWh/mile]
    const int passengerCount = 3;                // [count]
    const double faultProbability = 0.05;        // [prob/hr]

    double batteryLevel = batteryCapacity;       // [kWh]
    double chargeRate = batteryCapacity / chargeTime; // [kWh/hr]
    bool charging = false;

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