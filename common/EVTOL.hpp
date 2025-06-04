#pragma once

// Abstract base class representing an electric Vertical Take-Off and Landing (eVTOL) vehicle
// This interface defines common behavior for all eVTOL variants.
class EVTOL {
public:
    // Core operation methods

    // Simulate flight for given number of hours
    virtual void fly(double hours) = 0;

    // Charge vehicle to full capacity
    virtual void charge() = 0;

    // Determine if vehicle needs charging
    virtual bool needsCharge() const = 0;

    // Accessors

    // Get cruising speed in mph
    virtual double getCruiseSpeed() const = 0;

    // Get battery capacity in kWh
    virtual double getBatteryCapacity() const = 0;

    // Get full charging time in hours
    virtual double getChargeTime() const = 0;

    // Get energy usage per mile in kWh/mile
    virtual double getEnergyUsePerMile() const = 0;

    // Get number of passengers
    virtual int getPassengerCount() const = 0;

    // Get hourly probability of failure (unit: [0,1] / hr)
    virtual double getFaultProbabilityPerHour() const = 0;

    // Interface extensions

    // Determine if vehicle is currently charging
    virtual bool isCharging() const = 0;

    // Get charge rate in kWh/hr
    virtual double getChargeRate() const = 0;

    // Get current battery level in kWh
    virtual double getBatteryLevel() const = 0;

    // Simulate charging by specified number of hours
    virtual void charge(double hours) = 0;

    // Reset battery to full capacity
    virtual void resetBattery() = 0;

    // Get max passenger capacity
    virtual int getPassengerCapacity() const = 0;

    // Return type string identifier (e.g. "Alpha")
    virtual const char* getType() const = 0;

    // Probabilistically simulate a fault
    virtual bool checkForFault() const = 0;

    // Get remaining battery energy in kWh
    virtual double getRemainingBattery() const = 0;
};