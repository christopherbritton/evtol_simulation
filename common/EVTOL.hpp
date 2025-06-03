#pragma once

class EVTOL {
public:
    virtual ~EVTOL() = default;

    virtual void fly(double hours) = 0;
    virtual void charge() = 0;
    virtual bool needsCharge() const = 0;

    virtual double getCruiseSpeed() const = 0;
    virtual double getBatteryCapacity() const = 0;
    virtual double getChargeTime() const = 0;
    virtual double getEnergyUsePerMile() const = 0;
    virtual int getPassengerCount() const = 0;
    virtual double getFaultProbabilityPerHour() const = 0;

    virtual double getRemainingBattery() const = 0;
    virtual void resetBattery() = 0;

    // New functions needed for simulation
    virtual bool isCharging() const = 0;
    virtual double getChargeRate() const = 0;
    virtual double getBatteryLevel() const = 0;
    virtual void charge(double hours) = 0;

    // New functions to retrieve the vehicle type and capacity
    virtual const char* getType() const = 0;
    virtual int getPassengerCapacity() const = 0;

    // New function to check if vehicle experienced a fault
    virtual bool checkForFault() const = 0;

    // Add default constructor if needed for make_unique
    EVTOL() = default;
};
