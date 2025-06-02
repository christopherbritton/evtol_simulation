#pragma once

namespace Config {
    struct VehicleSpec {
        double cruiseSpeed;
        double batteryCapacity;
        double chargeTime;
        double energyUsePerMile;
        int    passengerCount;
        double faultProbability;
    };

    constexpr VehicleSpec AlphaSpec   = {120.0, 320.0, 0.6, 1.6, 4, 0.01};
    constexpr VehicleSpec BravoSpec   = {100.0, 300.0, 0.7, 1.3, 3, 0.012};
    constexpr VehicleSpec CharlieSpec = {110.0, 310.0, 0.65, 1.25, 4, 0.015};
    constexpr VehicleSpec DeltaSpec   = {115.0, 330.0, 0.55, 1.15, 5, 0.013};
    constexpr VehicleSpec EchoSpec    = {105.0, 290.0, 0.75, 1.35, 3, 0.014};

    // Legacy-style aliases to support existing test_evtol_methods.cpp references
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

    constexpr int FleetSize = 20;
    constexpr int MaxChargers = 3;
    constexpr double SimulationDurationHours = 3.0;
    constexpr double SimulationStepHours = 0.1;
}
