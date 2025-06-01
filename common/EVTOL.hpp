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
};
