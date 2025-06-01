#include <iostream>
#include <stdexcept>
#include "AlphaEVTOL.hpp"
#include "BravoEVTOL.hpp"
#include "CharlieEVTOL.hpp"
#include "DeltaEVTOL.hpp"
#include "EchoEVTOL.hpp"

int testsPassed = 0;
int testsFailed = 0;

void drainBattery(EVTOL& v) {
    while (!v.needsCharge()) {
        v.fly(0.1);
    }
    if (!v.needsCharge()) throw std::runtime_error("Battery did not drain as expected");
}

void testAlphaEVTOL() {
    std::cout << "Running testAlphaEVTOL... ";
    try {
        AlphaEVTOL a;
        if (a.getCruiseSpeed() != 120.0) throw std::runtime_error("Cruise speed mismatch");
        if (a.getBatteryCapacity() != 320.0) throw std::runtime_error("Battery capacity mismatch");
        if (a.getChargeTime() != 0.6) throw std::runtime_error("Charge time mismatch");
        if (a.getEnergyUsePerMile() != 1.6) throw std::runtime_error("Energy use mismatch");
        if (a.getPassengerCount() != 4) throw std::runtime_error("Passenger count mismatch");
        if (a.getFaultProbabilityPerHour() != 0.25) throw std::runtime_error("Fault probability mismatch");

        drainBattery(a);
        a.charge();
        if (a.needsCharge()) throw std::runtime_error("Charge did not succeed");
        a.resetBattery();
        if (a.getRemainingBattery() != a.getBatteryCapacity()) throw std::runtime_error("Reset failed");

        std::cout << "✅ PASSED\n";
        ++testsPassed;
    } catch (const std::exception& e) {
        std::cerr << "❌ FAILED: " << e.what() << "\n";
        ++testsFailed;
    }
}

void testBravoEVTOL() {
    std::cout << "Running testBravoEVTOL... ";
    try {
        BravoEVTOL b;
        if (b.getCruiseSpeed() != 100.0) throw std::runtime_error("Cruise speed mismatch");
        if (b.getBatteryCapacity() != 100.0) throw std::runtime_error("Battery capacity mismatch");
        if (b.getChargeTime() != 0.2) throw std::runtime_error("Charge time mismatch");
        if (b.getEnergyUsePerMile() != 1.5) throw std::runtime_error("Energy use mismatch");
        if (b.getPassengerCount() != 5) throw std::runtime_error("Passenger count mismatch");
        if (b.getFaultProbabilityPerHour() != 0.10) throw std::runtime_error("Fault probability mismatch");

        drainBattery(b);
        b.charge();
        if (b.needsCharge()) throw std::runtime_error("Charge did not succeed");
        b.resetBattery();
        if (b.getRemainingBattery() != b.getBatteryCapacity()) throw std::runtime_error("Reset failed");

        std::cout << "✅ PASSED\n";
        ++testsPassed;
    } catch (const std::exception& e) {
        std::cerr << "❌ FAILED: " << e.what() << "\n";
        ++testsFailed;
    }
}

void testCharlieEVTOL() {
    std::cout << "Running testCharlieEVTOL... ";
    try {
        CharlieEVTOL c;
        if (c.getCruiseSpeed() != 160.0) throw std::runtime_error("Cruise speed mismatch");
        if (c.getBatteryCapacity() != 220.0) throw std::runtime_error("Battery capacity mismatch");
        if (c.getChargeTime() != 0.8) throw std::runtime_error("Charge time mismatch");
        if (c.getEnergyUsePerMile() != 2.2) throw std::runtime_error("Energy use mismatch");
        if (c.getPassengerCount() != 3) throw std::runtime_error("Passenger count mismatch");
        if (c.getFaultProbabilityPerHour() != 0.05) throw std::runtime_error("Fault probability mismatch");

        drainBattery(c);
        c.charge();
        if (c.needsCharge()) throw std::runtime_error("Charge did not succeed");
        c.resetBattery();
        if (c.getRemainingBattery() != c.getBatteryCapacity()) throw std::runtime_error("Reset failed");

        std::cout << "✅ PASSED\n";
        ++testsPassed;
    } catch (const std::exception& e) {
        std::cerr << "❌ FAILED: " << e.what() << "\n";
        ++testsFailed;
    }
}

void testDeltaEVTOL() {
    std::cout << "Running testDeltaEVTOL... ";
    try {
        DeltaEVTOL d;
        if (d.getCruiseSpeed() != 90.0) throw std::runtime_error("Cruise speed mismatch");
        if (d.getBatteryCapacity() != 120.0) throw std::runtime_error("Battery capacity mismatch");
        if (d.getChargeTime() != 0.62) throw std::runtime_error("Charge time mismatch");
        if (d.getEnergyUsePerMile() != 0.8) throw std::runtime_error("Energy use mismatch");
        if (d.getPassengerCount() != 2) throw std::runtime_error("Passenger count mismatch");
        if (d.getFaultProbabilityPerHour() != 0.22) throw std::runtime_error("Fault probability mismatch");

        drainBattery(d);
        d.charge();
        if (d.needsCharge()) throw std::runtime_error("Charge did not succeed");
        d.resetBattery();
        if (d.getRemainingBattery() != d.getBatteryCapacity()) throw std::runtime_error("Reset failed");

        std::cout << "✅ PASSED\n";
        ++testsPassed;
    } catch (const std::exception& e) {
        std::cerr << "❌ FAILED: " << e.what() << "\n";
        ++testsFailed;
    }
}

void testEchoEVTOL() {
    std::cout << "Running testEchoEVTOL... ";
    try {
        EchoEVTOL e;
        if (e.getCruiseSpeed() != 30.0) throw std::runtime_error("Cruise speed mismatch");
        if (e.getBatteryCapacity() != 150.0) throw std::runtime_error("Battery capacity mismatch");
        if (e.getChargeTime() != 0.3) throw std::runtime_error("Charge time mismatch");
        if (e.getEnergyUsePerMile() != 5.8) throw std::runtime_error("Energy use mismatch");
        if (e.getPassengerCount() != 2) throw std::runtime_error("Passenger count mismatch");
        if (e.getFaultProbabilityPerHour() != 0.61) throw std::runtime_error("Fault probability mismatch");

        drainBattery(e);
        e.charge();
        if (e.needsCharge()) throw std::runtime_error("Charge did not succeed");
        e.resetBattery();
        if (e.getRemainingBattery() != e.getBatteryCapacity()) throw std::runtime_error("Reset failed");

        std::cout << "✅ PASSED\n";
        ++testsPassed;
    } catch (const std::exception& e) {
        std::cerr << "❌ FAILED: " << e.what() << "\n";
        ++testsFailed;
    }
}

int main() {
    testAlphaEVTOL();
    testBravoEVTOL();
    testCharlieEVTOL();
    testDeltaEVTOL();
    testEchoEVTOL();

    std::cout << "\nTest Summary: " << testsPassed << " passed, " << testsFailed << " failed.\n";
    return testsFailed == 0 ? 0 : 1;
}
