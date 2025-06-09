#pragma once

#include <random>
#include "Config.hpp"

class EVTOL {
protected:
    double batteryLevel = 0;
    bool charging = false;
    bool faultActive = false;

    // Mersenne Twister RNG
    static std::mt19937& getGenerator() {
        static thread_local std::mt19937 gen(std::random_device{}());
        return gen;
    }

    static std::uniform_real_distribution<>& getDistribution() {
        static thread_local std::uniform_real_distribution<> dis(0.0, 1.0);
        return dis;
    }

public:
    virtual ~EVTOL() = default;

    // Core behavior
    virtual void fly(double hours) = 0;
    virtual void charge() = 0;

    // Accessors
    virtual double getCruiseSpeed() const = 0;
    virtual double getBatteryCapacity() const = 0;
    virtual double getChargeTime() const = 0;
    virtual double getEnergyUsePerMile() const = 0;
    virtual int getPassengerCount() const = 0;
    virtual double getFaultProbabilityPerHour() const = 0;
    virtual const char* getType() const = 0;
    virtual void injectFault() = 0;

    // Utility
    virtual bool isCharging() const { return charging; }
    virtual double getChargeRate() const { return getBatteryCapacity() / getChargeTime(); }
    virtual double getBatteryLevel() const { return batteryLevel; }
    virtual bool needsCharge() const { return batteryLevel < getBatteryCapacity() * 0.25; }
    virtual void resetBattery() { batteryLevel = getBatteryCapacity(); }
    virtual double getRemainingBattery() const { return batteryLevel; }
    virtual bool checkForFault() const {
        return getDistribution()(getGenerator()) < getFaultProbabilityPerHour();
    }
};