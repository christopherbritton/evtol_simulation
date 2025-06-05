#pragma once

#include "EVTOL.hpp"

class BravoEVTOL : public EVTOL {
private:
    const double cruiseSpeed = 100.0;           // [mph]
    const double batteryCapacity = 100.0;       // [kWh]
    const double chargeTime = 0.2;              // [hrs]
    const double energyUsePerMile = 1.5;        // [kWh/mile]
    const int passengerCount = 5;               // [count]
    const double faultProbability = 0.10;       // [prob/hr]

    double batteryLevel = batteryCapacity;      // [kWh] - initial full charge
    double chargeRate = batteryCapacity / chargeTime; // [kWh/hr] - constant rate
    bool charging = false;                      // [bool] - charging state flag
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

    bool isCharging() const override;
    double getChargeRate() const override;
    double getBatteryLevel() const override;
    void charge(double hours) override;
    void resetBattery() override;
    int getPassengerCapacity() const override;
    const char* getType() const override;
    bool checkForFault() const override;
    double getRemainingBattery() const override;
    void injectFault() override;
    
};