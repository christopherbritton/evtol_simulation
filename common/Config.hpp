#pragma once

#include <array>

//This pattern scales well as more EVTOL types are added, maintaining clean and centralized access to vehicle characteristics.

namespace Config {

// Structure representing vehicle performance and system characteristics
struct VehicleSpec {
    double cruiseSpeed;       // [mph] Maximum cruise speed
    double batteryCapacity;   // [kWh] Total battery capacity
    double chargeTime;        // [hours] Time required to fully charge
    double energyUsePerMile;  // [kWh/mile] Energy consumption rate
    int passengerCount;       // [count] Number of passengers
    double faultProbability;  // [prob/hr] Likelihood of fault per flight hour
};

// Enum representing vehicle types
enum class VehicleType {
    Alpha,
    Bravo,
    Charlie,
    Delta,
    Echo,
    Count
};

// Vehicle specifications for each EVTOL type per our problem statement
// inline constexpr: Guarantees compile-time evaluation and allows header file inclusion without multiple definition errors.
inline constexpr VehicleSpec AlphaSpec  = {120.0, 320.0, 0.6, 1.6, 4, 0.25};
inline constexpr VehicleSpec BravoSpec  = {100.0, 100.0, 0.2, 1.5, 5, 0.10};
inline constexpr VehicleSpec CharlieSpec = {160.0, 220.0, 0.8, 2.2, 3, 0.05};
inline constexpr VehicleSpec DeltaSpec  = {90.0, 120.0, 0.62, 0.8, 2, 0.22};
inline constexpr VehicleSpec EchoSpec   = {30.0, 150.0, 0.3, 5.8, 2, 0.61};

//A fixed-size array of VehicleSpec structures.
//This array allows consistent and efficient access to any vehicle type's configuration using an index derived from the VehicleType enum
inline constexpr std::array<VehicleSpec, static_cast<size_t>(VehicleType::Count)> VehicleSpecs = {{
    AlphaSpec,
    BravoSpec,
    CharlieSpec,
    DeltaSpec,
    EchoSpec
}};

// Simulation constants
constexpr int FleetSize = 20;                         // [count] Total number of EVTOLs
constexpr int MaxChargers = 3;                        // [count] Charging stations available
constexpr double SimulationDurationHours = 3.0;       // [hours] Total time span of simulation
constexpr double SimulationStepHours = 0.1;           // [hours] Simulation resolution step
} // namespace Config