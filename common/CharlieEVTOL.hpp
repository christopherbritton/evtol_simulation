#pragma once
#include "Config.hpp"
#include "EVTOL.hpp"

class CharlieEVTOL : public EVTOL {
private:
    const double cruiseSpeed = Config::CharlieSpec.cruiseSpeed;                // [mph]
    const double batteryCapacity = Config::CharlieSpec.batteryCapacity;        // [kWh]
    const double chargeTime = Config::CharlieSpec.chargeTime;                  // [hrs]
    const double energyUsePerMile = Config::CharlieSpec.energyUsePerMile;      // [kWh/mile]
    const int passengerCount = Config::CharlieSpec.passengerCount;             // [count]
    const double faultProbability = Config::CharlieSpec.faultProbability;      // [prob/hr]

    double batteryLevel = batteryCapacity;                                     // [kWh]
    double chargeRate = batteryCapacity / chargeTime;                          // [kWh/hr]
    bool charging = false;
    bool faultActive = false;                                                  // Forces fault condition

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