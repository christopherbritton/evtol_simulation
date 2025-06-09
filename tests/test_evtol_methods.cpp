#include <iostream>
#include <stdexcept>
#include <random>
#include "Statistics.hpp"
#include "StatisticsReporter.hpp"
#include "FleetManager.hpp"
#include "AlphaEVTOL.hpp"
#include "BravoEVTOL.hpp"
#include "CharlieEVTOL.hpp"
#include "DeltaEVTOL.hpp"
#include "EchoEVTOL.hpp"
#include "Config.hpp"

int testsPassed = 0;
int testsFailed = 0;

void drainBattery(EVTOL& e) {
    while (!e.needsCharge()) {
        e.fly(0.1);
    }
}

void testAlphaEVTOL() {
    std::cout << "Running testAlphaEVTOL... ";
    try {
        AlphaEVTOL a;
        const auto& spec = Config::VehicleSpecs[static_cast<int>(Config::VehicleType::Alpha)];
        if (a.getCruiseSpeed() != spec.cruiseSpeed) throw std::runtime_error("Cruise speed mismatch");
        if (a.getBatteryCapacity() != spec.batteryCapacity) throw std::runtime_error("Battery capacity mismatch");
        if (a.getChargeTime() != spec.chargeTime) throw std::runtime_error("Charge time mismatch");
        if (a.getEnergyUsePerMile() != spec.energyUsePerMile) throw std::runtime_error("Energy use mismatch");
        if (a.getPassengerCount() != spec.passengerCount) throw std::runtime_error("Passenger count mismatch");
        if (a.getFaultProbabilityPerHour() != spec.faultProbability) throw std::runtime_error("Fault probability mismatch");

        drainBattery(a);
        a.charge();
        if (a.needsCharge()) throw std::runtime_error("Charge did not succeed");
        a.resetBattery();
        if (a.getRemainingBattery() != a.getBatteryCapacity()) throw std::runtime_error("Reset failed");

        std::cout << "✔ PASSED\n";
        ++testsPassed;
    } catch (const std::exception& e) {
        std::cerr << "✘ FAILED: " << e.what() << "\n";
        ++testsFailed;
    }
}

void testBravoEVTOL() {
    std::cout << "Running testBravoEVTOL... ";
    try {
        BravoEVTOL b;
        const auto& spec = Config::VehicleSpecs[static_cast<int>(Config::VehicleType::Bravo)];
        if (b.getCruiseSpeed() != spec.cruiseSpeed) throw std::runtime_error("Cruise speed mismatch");
        if (b.getBatteryCapacity() != spec.batteryCapacity) throw std::runtime_error("Battery capacity mismatch");
        if (b.getChargeTime() != spec.chargeTime) throw std::runtime_error("Charge time mismatch");
        if (b.getEnergyUsePerMile() != spec.energyUsePerMile) throw std::runtime_error("Energy use mismatch");
        if (b.getPassengerCount() != spec.passengerCount) throw std::runtime_error("Passenger count mismatch");
        if (b.getFaultProbabilityPerHour() != spec.faultProbability) throw std::runtime_error("Fault probability mismatch");

        drainBattery(b);
        b.charge();
        if (b.needsCharge()) throw std::runtime_error("Charge did not succeed");
        b.resetBattery();
        if (b.getRemainingBattery() != b.getBatteryCapacity()) throw std::runtime_error("Reset failed");

        std::cout << "✔ PASSED\n";
        ++testsPassed;
    } catch (const std::exception& e) {
        std::cerr << "✘ FAILED: " << e.what() << "\n";
        ++testsFailed;
    }
}

void testCharlieEVTOL() {
    std::cout << "Running testCharlieEVTOL... ";
    try {
        CharlieEVTOL c;
        const auto& spec = Config::VehicleSpecs[static_cast<int>(Config::VehicleType::Charlie)];
        if (c.getCruiseSpeed() != spec.cruiseSpeed) throw std::runtime_error("Cruise speed mismatch");
        if (c.getBatteryCapacity() != spec.batteryCapacity) throw std::runtime_error("Battery capacity mismatch");
        if (c.getChargeTime() != spec.chargeTime) throw std::runtime_error("Charge time mismatch");
        if (c.getEnergyUsePerMile() != spec.energyUsePerMile) throw std::runtime_error("Energy use mismatch");
        if (c.getPassengerCount() != spec.passengerCount) throw std::runtime_error("Passenger count mismatch");
        if (c.getFaultProbabilityPerHour() != spec.faultProbability) throw std::runtime_error("Fault probability mismatch");

        drainBattery(c);
        c.charge();
        if (c.needsCharge()) throw std::runtime_error("Charge did not succeed");
        c.resetBattery();
        if (c.getRemainingBattery() != c.getBatteryCapacity()) throw std::runtime_error("Reset failed");

        std::cout << "✔ PASSED\n";
        ++testsPassed;
    } catch (const std::exception& e) {
        std::cerr << "✘ FAILED: " << e.what() << "\n";
        ++testsFailed;
    }
}

void testDeltaEVTOL() {
    std::cout << "Running testDeltaEVTOL... ";
    try {
        DeltaEVTOL d;
        const auto& spec = Config::VehicleSpecs[static_cast<int>(Config::VehicleType::Delta)];
        if (d.getCruiseSpeed() != spec.cruiseSpeed) throw std::runtime_error("Cruise speed mismatch");
        if (d.getBatteryCapacity() != spec.batteryCapacity) throw std::runtime_error("Battery capacity mismatch");
        if (d.getChargeTime() != spec.chargeTime) throw std::runtime_error("Charge time mismatch");
        if (d.getEnergyUsePerMile() != spec.energyUsePerMile) throw std::runtime_error("Energy use mismatch");
        if (d.getPassengerCount() != spec.passengerCount) throw std::runtime_error("Passenger count mismatch");
        if (d.getFaultProbabilityPerHour() != spec.faultProbability) throw std::runtime_error("Fault probability mismatch");

        drainBattery(d);
        d.charge();
        if (d.needsCharge()) throw std::runtime_error("Charge did not succeed");
        d.resetBattery();
        if (d.getRemainingBattery() != d.getBatteryCapacity()) throw std::runtime_error("Reset failed");

        std::cout << "✔ PASSED\n";
        ++testsPassed;
    } catch (const std::exception& e) {
        std::cerr << "✘ FAILED: " << e.what() << "\n";
        ++testsFailed;
    }
}

void testEchoEVTOL() {
    std::cout << "Running testEchoEVTOL... ";
    try {
        EchoEVTOL e;
        const auto& spec = Config::VehicleSpecs[static_cast<int>(Config::VehicleType::Echo)];
        if (e.getCruiseSpeed() != spec.cruiseSpeed) throw std::runtime_error("Cruise speed mismatch");
        if (e.getBatteryCapacity() != spec.batteryCapacity) throw std::runtime_error("Battery capacity mismatch");
        if (e.getChargeTime() != spec.chargeTime) throw std::runtime_error("Charge time mismatch");
        if (e.getEnergyUsePerMile() != spec.energyUsePerMile) throw std::runtime_error("Energy use mismatch");
        if (e.getPassengerCount() != spec.passengerCount) throw std::runtime_error("Passenger count mismatch");
        if (e.getFaultProbabilityPerHour() != spec.faultProbability) throw std::runtime_error("Fault probability mismatch");

        drainBattery(e);
        e.charge();
        if (e.needsCharge()) throw std::runtime_error("Charge did not succeed");
        e.resetBattery();
        if (e.getRemainingBattery() != e.getBatteryCapacity()) throw std::runtime_error("Reset failed");

        std::cout << "✔ PASSED\n";
        ++testsPassed;
    } catch (const std::exception& e) {
        std::cerr << "✘ FAILED: " << e.what() << "\n";
        ++testsFailed;
    }
}

// --------------------------------------------------
// UNIT TEST: Statistics::reset and Statistics::update
// --------------------------------------------------
void testStatisticsUpdateAndReset() {
    std::cout << "Running testStatisticsUpdateAndReset... ";
    try {
        Statistics s;
        AlphaEVTOL testVehicle;
        std::mt19937 rng(42);

        // Simulate flight update
        double flightHours = 3.0;
        Statistics::update(s, &testVehicle, flightHours, rng);

        // Check that at least one stat was updated
        if (s.totalFlightTime <= 0.0) throw std::runtime_error("Flight time not updated");
        if (s.totalDistance <= 0.0) throw std::runtime_error("Distance not updated");
        if (s.flights != 1) throw std::runtime_error("Flights not incremented");

        // Reset and verify all fields are zeroed
        s.reset();
        if (s.totalFlightTime != 0.0 || s.totalDistance != 0.0 || s.totalFaults != 0 || s.flights != 0)
            throw std::runtime_error("Reset did not clear statistics");

        testsPassed++;
        std::cout << "✔ PASSED\n";
    } catch (const std::exception& e) {
        testsFailed++;
        std::cout << "✘ FAILED: " << e.what() << "\n";
    }
}

// --------------------------------------------------
// UNIT TEST: FleetManager::generateFleet and simulate
// --------------------------------------------------
void testFleetManagerGenerateAndSimulate() {
    std::cout << "Running testFleetManagerGenerateAndSimulate... \n";
    try {
        FleetManager fm;
        fm.generateFleet(20);

        fm.simulate(3.0, 0.1);

        std::cout << "\n--- Fleet Statistics Output ---\n";
        fm.printStatistics(true);
        std::cout << "--- End Fleet Statistics ---\n\n";

        std::cout << "\n--- Fleet Statistics Output (inMinutes = false) ---\n";
        fm.printStatistics(false);
        std::cout << "--- End Fleet Statistics ---\n\n";

        testsPassed++;
        std::cout << "✔ PASSED\n";
    } catch (const std::exception& e) {
        std::cout << "❌ FAILED: " << e.what() << "\n";
        testsFailed++;
    }
}

// --------------------------------------------------
// UNIT TEST: Force fault condition (DAL-B coverage)
// --------------------------------------------------
void testForcedFaultInjection() {
    std::cout << "Running testForcedFaultInjection... ";
    try {
        AlphaEVTOL a;
        a.injectFault();
        if (!a.checkForFault()) throw std::runtime_error("Fault not detected after injection");

        testsPassed++;
        std::cout << "✔ PASSED\n";
    } catch (const std::exception& e) {
        testsFailed++;
        std::cout << "FAILED: " << e.what() << "\n";
    }
}

// --------------------------------------------------
// UNIT TEST: SimulateStep execution path (charging=false)
// --------------------------------------------------
void testSimulateStepWithNoCharging() {
    std::cout << "Running testSimulateStepWithNoCharging... ";
    try {
        FleetManager fm;
        fm.generateFleet(1);

        // Step the simulation once with a small time increment
        fm.simulate(0.1, 0.1);

        testsPassed++;
        std::cout << "✔ PASSED\n";
    } catch (const std::exception& e) {
        testsFailed++;
        std::cout << "FAILED: " << e.what() << "\n";
    }
}

// --------------------------------------------------
// UNIT TEST: needsCharge() returns false when battery is full
// --------------------------------------------------
void testNeedsChargeFalseCondition() {
    std::cout << "Running testNeedsChargeFalseCondition... ";
    try {
        AlphaEVTOL a;
        if (a.needsCharge()) throw std::runtime_error("needsCharge() should be false for full battery");
        testsPassed++;
        std::cout << "✔ PASSED\n";
    } catch (const std::exception& e) {
        testsFailed++;
        std::cout << "FAILED: " << e.what() << "\n";
    }
}

// Entry point for test runner with summary report
int main() {
    testAlphaEVTOL();
    testBravoEVTOL();
    testCharlieEVTOL();
    testDeltaEVTOL();
    testEchoEVTOL();
    testNeedsChargeFalseCondition();
    testSimulateStepWithNoCharging();
    testStatisticsUpdateAndReset();
    testFleetManagerGenerateAndSimulate();

    std::cout << "\nTest Summary: " << testsPassed << " passed, " << testsFailed << " failed.\n";
    return testsFailed == 0 ? 0 : 1;
}