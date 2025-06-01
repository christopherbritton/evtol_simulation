#pragma once

namespace Config {
    constexpr int FleetSize = 20;
    constexpr int MaxChargers = 3;
    constexpr double SimulationDurationHours = 3.0;
    constexpr double SimulationStepHours = 0.1;

    struct VehicleSpec {
        double cruiseSpeed;
        double batteryCapacity;
        double chargeTime;
        double energyUsePerMile;
        int passengerCount;
        double faultProbability;
    };

    constexpr VehicleSpec AlphaSpec   = {120.0, 320.0, 0.6, 1.6, 4, 0.25};
    constexpr VehicleSpec BravoSpec   = {100.0, 100.0, 0.2, 1.5, 5, 0.10};
    constexpr VehicleSpec CharlieSpec = {160.0, 220.0, 0.8, 2.2, 3, 0.05};
    constexpr VehicleSpec DeltaSpec   = { 90.0, 120.0, 0.62, 0.8, 2, 0.22};
    constexpr VehicleSpec EchoSpec    = { 30.0, 150.0, 0.3, 5.8, 2, 0.61};
}
