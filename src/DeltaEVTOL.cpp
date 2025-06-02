#include "DeltaEVTOL.hpp"

// Simulates flight by reducing battery based on cruise speed and energy usage rate
void DeltaEVTOL::fly(double hours) {
    double distance = spec.cruiseSpeed * hours;                 // [miles] distance = speed * time
    battery -= distance * spec.energyUsePerMile;               // [kWh] battery drained based on distance
}

// Charges the EVTOL to its full battery capacity
void DeltaEVTOL::charge() {
    battery = spec.batteryCapacity;                            // [kWh]
}

// Determines if the battery needs charging
bool DeltaEVTOL::needsCharge() const {
    return battery <= 0;
}

// Accessor methods for vehicle characteristics

// [mph] Maximum cruise speed
double DeltaEVTOL::getCruiseSpeed() const { return spec.cruiseSpeed; }

// [kWh] Total battery storage capacity
double DeltaEVTOL::getBatteryCapacity() const { return spec.batteryCapacity; }

// [hours] Time needed to fully charge
double DeltaEVTOL::getChargeTime() const { return spec.chargeTime; }

// [kWh/mile] Energy usage per mile during operation
double DeltaEVTOL::getEnergyUsePerMile() const { return spec.energyUsePerMile; }

// [count] Passenger capacity
int DeltaEVTOL::getPassengerCount() const { return spec.passengerCount; }

// [probability/hour] Probability of fault occurrence per flight hour
double DeltaEVTOL::getFaultProbabilityPerHour() const { return spec.faultProbability; }

// [kWh] Remaining battery level
double DeltaEVTOL::getRemainingBattery() const { return battery; }

// Resets battery to its full capacity
void DeltaEVTOL::resetBattery() { battery = spec.batteryCapacity; }
