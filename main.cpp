
#include "EVTOL.hpp"
#include "ChargerManager.hpp"
#include "FaultManager.hpp"
#include "StatisticsTracker.hpp"
#include "FleetManager.hpp"
#include "VehicleType.hpp"
#include "VehicleProfiles.hpp"
#include <iostream>
#include <vector>
#include <random>

int main() {
    // Initialize charger and trackers
    ChargerManager chargerManager(3);
    FaultManager faultManager;
    StatisticsTracker statsTracker;

    // Vehicle types
    std::vector<VehicleType> types = {
        VehicleType::Alpha,
        VehicleType::Bravo,
        VehicleType::Charlie,
        VehicleType::Delta,
        VehicleType::Echo
    };

    // RNG setup
    std::random_device rd;
    std::default_random_engine rng(rd());

    // Fleet creation
    FleetManager fleetManager(types, rng, vehicleProfiles);
    std::vector<EVTOL>& evtols = fleetManager.getFleet();

    // Simulation configuration
    const int timeStepMinutes = 1;
    const int totalMinutes = 180;

    for (int minute = 0; minute < totalMinutes; minute += timeStepMinutes) {
        for (size_t i = 0; i < evtols.size(); ++i) {
            evtols[i].update(minute);
            if (evtols[i].hasFault()) {
                faultManager.recordFault(evtols[i].getId(), evtols[i].getFaultCode());
            }
            if (evtols[i].needsCharging() && !evtols[i].isCharging()) {
                chargerManager.assignCharger(evtols[i], minute);
            }
        }
        chargerManager.update(minute);
        statsTracker.record(evtols);
    }

    statsTracker.report();
    faultManager.report();
    chargerManager.report();

    return 0;
}
