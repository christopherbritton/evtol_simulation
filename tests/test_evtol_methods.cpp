#include <iostream>
#include <stdexcept>
#include "AlphaEVTOL.hpp"
#include "BravoEVTOL.hpp"
#include "CharlieEVTOL.hpp"
#include "DeltaEVTOL.hpp"
#include "EchoEVTOL.hpp"
#include "Config.hpp"

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
        if (a.getCruiseSpeed() != Config::AlphaCruiseSpeed) throw std::runtime_error("Cruise speed mismatch");
        if (a.getBatteryCapacity() != Config::AlphaBatteryCapacity) throw std::runtime_error("Battery capacity mismatch");
        if (a.getChargeTime() != Config::AlphaChargeTime) throw std::runtime_error("Charge time mismatch");
        if (a.getEnergyUsePerMile() != Config::AlphaEnergyUsePerMile) throw std::runtime_error("Energy use mismatch");
        if (a.getPassengerCount() != Config::AlphaPassengerCount) throw std::runtime_error("Passenger count mismatch");
        if (a.getFaultProbabilityPerHour() != Config::AlphaFaultProbability) throw std::runtime_error("Fault probability mismatch");

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
        if (b.getCruiseSpeed() != Config::BravoCruiseSpeed) throw std::runtime_error("Cruise speed mismatch");
        if (b.getBatteryCapacity() != Config::BravoBatteryCapacity) throw std::runtime_error("Battery capacity mismatch");
        if (b.getChargeTime() != Config::BravoChargeTime) throw std::runtime_error("Charge time mismatch");
        if (b.getEnergyUsePerMile() != Config::BravoEnergyUsePerMile) throw std::runtime_error("Energy use mismatch");
        if (b.getPassengerCount() != Config::BravoPassengerCount) throw std::runtime_error("Passenger count mismatch");
        if (b.getFaultProbabilityPerHour() != Config::BravoFaultProbability) throw std::runtime_error("Fault probability mismatch");

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
        if (c.getCruiseSpeed() != Config::CharlieCruiseSpeed) throw std::runtime_error("Cruise speed mismatch");
        if (c.getBatteryCapacity() != Config::CharlieBatteryCapacity) throw std::runtime_error("Battery capacity mismatch");
        if (c.getChargeTime() != Config::CharlieChargeTime) throw std::runtime_error("Charge time mismatch");
        if (c.getEnergyUsePerMile() != Config::CharlieEnergyUsePerMile) throw std::runtime_error("Energy use mismatch");
        if (c.getPassengerCount() != Config::CharliePassengerCount) throw std::runtime_error("Passenger count mismatch");
        if (c.getFaultProbabilityPerHour() != Config::CharlieFaultProbability) throw std::runtime_error("Fault probability mismatch");

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
        if (d.getCruiseSpeed() != Config::DeltaCruiseSpeed) throw std::runtime_error("Cruise speed mismatch");
        if (d.getBatteryCapacity() != Config::DeltaBatteryCapacity) throw std::runtime_error("Battery capacity mismatch");
        if (d.getChargeTime() != Config::DeltaChargeTime) throw std::runtime_error("Charge time mismatch");
        if (d.getEnergyUsePerMile() != Config::DeltaEnergyUsePerMile) throw std::runtime_error("Energy use mismatch");
        if (d.getPassengerCount() != Config::DeltaPassengerCount) throw std::runtime_error("Passenger count mismatch");
        if (d.getFaultProbabilityPerHour() != Config::DeltaFaultProbability) throw std::runtime_error("Fault probability mismatch");

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
        if (e.getCruiseSpeed() != Config::EchoCruiseSpeed) throw std::runtime_error("Cruise speed mismatch");
        if (e.getBatteryCapacity() != Config::EchoBatteryCapacity) throw std::runtime_error("Battery capacity mismatch");
        if (e.getChargeTime() != Config::EchoChargeTime) throw std::runtime_error("Charge time mismatch");
        if (e.getEnergyUsePerMile() != Config::EchoEnergyUsePerMile) throw std::runtime_error("Energy use mismatch");
        if (e.getPassengerCount() != Config::EchoPassengerCount) throw std::runtime_error("Passenger count mismatch");
        if (e.getFaultProbabilityPerHour() != Config::EchoFaultProbability) throw std::runtime_error("Fault probability mismatch");

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
