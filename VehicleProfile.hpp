
#pragma once

// Defines configuration parameters for each EVTOL type
struct VehicleProfile {
    double batteryCapacity;     // in kWh
    double cruiseSpeed;         // in mph
    double energyPerMile;       // in kWh/mile
    double timeToCharge;        // in hours
    int chargerType;            // charger ID/type
    double faultProbability;    // faults per hour
};
