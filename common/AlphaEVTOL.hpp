#pragma once
#include "Config.hpp"
#include "EVTOL.hpp"

class AlphaEVTOL : public EVTOL {
private:
    const double cruiseSpeed = Config::AlphaSpec.cruiseSpeed;                // [mph]    - Max cruise speed
    const double batteryCapacity = Config::AlphaSpec.batteryCapacity;        // [kWh]    - Max battery energy
    const double chargeTime = Config::AlphaSpec.chargeTime;                  // [hrs]    - Time to charge fully
    const double energyUsePerMile = Config::AlphaSpec.energyUsePerMile;      // [kWh/mile] - Energy consumption rate
    const int passengerCount = Config::AlphaSpec.passengerCount;             // [count]  - Max passengers
    const double faultProbability = Config::AlphaSpec.faultProbability;      // [prob/hr] - Fault probability per flight hour

    double batteryLevel = batteryCapacity;                                   // [kWh]    - Current battery energy
    double chargeRate = batteryCapacity / chargeTime;                        // [kWh/hr] - Charging rate
    bool charging = false;                                                   // [bool]   - Charging state
    bool faultActive = false;                                                // Forces fault condition

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
    void injectFault() override;
};