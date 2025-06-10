#pragma once

#include <random>
#include "Config.hpp"

class EVTOL {
protected:
    int id;                                       // Unique vehicle identifier
    Config::VehicleType type;                     // Enum type of the vehicle (Alpha, Bravo, etc.)
    Config::VehicleSpec spec;                     // Configuration spec containing performance parameters

    double batteryLevel = 0;                      // Current battery level in kWh
    bool charging = false;                        // Charging status flag
    bool faultActive = false;                     // Fault status flag

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
// Constructor initializing the EVTOL with ID, type, and performance spec
    EVTOL(int id, Config::VehicleType type, const Config::VehicleSpec& spec);

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

// Definition moved outside class to avoid inline initialization of spec object
inline EVTOL::EVTOL(int id, Config::VehicleType type, const Config::VehicleSpec& spec)
    : id(id), type(type), spec(spec), batteryLevel(spec.batteryCapacity) {}