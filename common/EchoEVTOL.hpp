#pragma once
#include "Config.hpp"
#include "EVTOL.hpp"

class EchoEVTOL : public EVTOL {
private:
    // Vehicle specifications with physical units
    const double cruiseSpeed = Config::EchoSpec.cruiseSpeed;                 // [mph] - Maximum cruising speed
    const double batteryCapacity = Config::EchoSpec.batteryCapacity;         // [kWh] - Maximum energy storage
    const double chargeTime = Config::EchoSpec.chargeTime;                   // [hrs] - Time to full charge
    const double energyUsePerMile = Config::EchoSpec.energyUsePerMile;       // [kWh/mile] - Energy consumption per mile
    const int passengerCount = Config::EchoSpec.passengerCount;              // [count] - Seating capacity
    const double faultProbability = Config::EchoSpec.faultProbability;       // [prob/hr] - Probability of failure per flight hour

    // Runtime operational state
    double batteryLevel = batteryCapacity;                                   // [kWh] - Current energy remaining
    double chargeRate = batteryCapacity / chargeTime;                        // [kWh/hr] - Charging rate
    bool charging = false;                                                   // [flag] - Whether currently charging
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

    // Reset and utility
    void resetBattery() override;
    int getPassengerCapacity() const override;
    const char* getType() const override;
    bool checkForFault() const override;
    double getRemainingBattery() const override;
    void injectFault() override;
};
