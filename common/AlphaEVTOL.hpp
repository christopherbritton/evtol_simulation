// AlphaEVTOL.hpp - Derived class representing the Alpha EVTOL variant
#pragma once

#include "EVTOL.hpp"  // Inherits base EVTOL behavior
#include "Config.hpp" // Includes vehicle specification for Alpha variant

// AlphaEVTOL defines a specific configuration of the EVTOL type
class AlphaEVTOL : public EVTOL {
public:
    // Constructor initializes AlphaEVTOL with its unique ID and AlphaSpec
    AlphaEVTOL(int id);
    
    // Core simulation behaviors
    void fly(double hours) override;           // Simulates flight consumption and updates state
    void charge() override;                    // Fully charges battery
    bool needsCharge() const override;         // Determines if charging is needed

    // Accessors for characteristics defined in the config spec
    double getCruiseSpeed() const override;          // Returns cruising speed in mph
    double getBatteryCapacity() const override;      // Returns battery capacity in kWh
    double getChargeTime() const override;           // Returns charge time in hours
    double getEnergyUsePerMile() const override;     // Returns energy use per mile in kWh
    int getPassengerCount() const override;          // Returns passenger count
    double getFaultProbabilityPerHour() const override; // Returns hourly fault probability

    // Type and fault management
    const char* getType() const override;            // Returns vehicle type string ("Alpha")
    void injectFault() override;                     // Forces fault condition
};