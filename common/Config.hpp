#pragma once

namespace Config {
    // Structure representing vehicle performance and system characteristics
    struct VehicleSpec {
        double cruiseSpeed;         // [mph] Maximum cruise speed
        double batteryCapacity;     // [kWh] Total battery capacity
        double chargeTime;          // [hours] Time required to fully charge
        double energyUsePerMile;    // [kWh/mile] Energy consumption rate
        int    passengerCount;      // [count] Number of passengers
        double faultProbability;    // [probability/hour] Likelihood of fault per flight hour
    };

    // Specifications for each EVTOL type
    constexpr VehicleSpec AlphaSpec   = {120.0, 320.0, 0.6, 1.6, 4, 0.25};
    constexpr VehicleSpec BravoSpec   = {100.0, 100.0, 0.2, 1.5, 5, 0.1};
    constexpr VehicleSpec CharlieSpec = {160.0, 220.0, 0.8, 2.2, 3, 0.05};
    constexpr VehicleSpec DeltaSpec   = {90.0, 120.0, 0.62, 0.8, 2, 0.22};
    constexpr VehicleSpec EchoSpec    = {30.0, 150.0, 0.3, 5.8, 2, 0.61};

    // Aliases to support compatibility with unit test macros and legacy calls
    constexpr double AlphaCruiseSpeed       = AlphaSpec.cruiseSpeed;
    constexpr double AlphaBatteryCapacity   = AlphaSpec.batteryCapacity;
    constexpr double AlphaChargeTime        = AlphaSpec.chargeTime;
    constexpr double AlphaEnergyUsePerMile  = AlphaSpec.energyUsePerMile;
    constexpr int    AlphaPassengerCount    = AlphaSpec.passengerCount;
    constexpr double AlphaFaultProbability  = AlphaSpec.faultProbability;

    constexpr double BravoCruiseSpeed       = BravoSpec.cruiseSpeed;
    constexpr double BravoBatteryCapacity   = BravoSpec.batteryCapacity;
    constexpr double BravoChargeTime        = BravoSpec.chargeTime;
    constexpr double BravoEnergyUsePerMile  = BravoSpec.energyUsePerMile;
    constexpr int    BravoPassengerCount    = BravoSpec.passengerCount;
    constexpr double BravoFaultProbability  = BravoSpec.faultProbability;

    constexpr double CharlieCruiseSpeed       = CharlieSpec.cruiseSpeed;
    constexpr double CharlieBatteryCapacity   = CharlieSpec.batteryCapacity;
    constexpr double CharlieChargeTime        = CharlieSpec.chargeTime;
    constexpr double CharlieEnergyUsePerMile  = CharlieSpec.energyUsePerMile;
    constexpr int    CharliePassengerCount    = CharlieSpec.passengerCount;
    constexpr double CharlieFaultProbability  = CharlieSpec.faultProbability;

    constexpr double DeltaCruiseSpeed       = DeltaSpec.cruiseSpeed;
    constexpr double DeltaBatteryCapacity   = DeltaSpec.batteryCapacity;
    constexpr double DeltaChargeTime        = DeltaSpec.chargeTime;
    constexpr double DeltaEnergyUsePerMile  = DeltaSpec.energyUsePerMile;
    constexpr int    DeltaPassengerCount    = DeltaSpec.passengerCount;
    constexpr double DeltaFaultProbability  = DeltaSpec.faultProbability;

    constexpr double EchoCruiseSpeed       = EchoSpec.cruiseSpeed;
    constexpr double EchoBatteryCapacity   = EchoSpec.batteryCapacity;
    constexpr double EchoChargeTime        = EchoSpec.chargeTime;
    constexpr double EchoEnergyUsePerMile  = EchoSpec.energyUsePerMile;
    constexpr int    EchoPassengerCount    = EchoSpec.passengerCount;
    constexpr double EchoFaultProbability  = EchoSpec.faultProbability;

    // Simulation constants
    constexpr int FleetSize = 20;                         // [count] Total number of EVTOLs in fleet
    constexpr int MaxChargers = 3;                        // [count] Charging stations available
    constexpr double SimulationDurationHours = 3.0;       // [hours] Total time span of simulation
    constexpr double SimulationStepHours = 0.1;           // [hours] Simulation resolution step
} // namespace Config
