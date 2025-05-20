#include "VehicleType.hpp"
#include "VehicleProfile.hpp"
#include "ChargerManager.hpp"
#include "FaultManager.hpp"
#include "FleetManager.hpp"
#include "StatisticsTracker.hpp"
#include "EVTOL.hpp"

#include <iostream>
#include <vector>
#include <random>
#include <map>

int main() {
    // Time: O(v * t), Space: O(v) where v = number of EVTOLs, t = time steps

    // Initialize managers
    ChargerManager chargerManager(3);
    FaultManager faultManager;
    StatisticsTracker statsTracker;

    // Define vehicle types
    std::vector<VehicleType> types = {
        VehicleType::Alpha,
        VehicleType::Bravo,
        VehicleType::Charlie,
        VehicleType::Delta,
        VehicleType::Echo
    };

    // Define profiles per vehicle type
    std::map<VehicleType, VehicleProfile> vehicleProfiles = {
        {VehicleType::Alpha, {150, 100, 1, 0.5, 4, 0.01}},
        {VehicleType::Bravo, {120, 90, 1.2, 0.75, 5, 0.015}},
        {VehicleType::Charlie, {180, 110, 1.1, 0.6, 6, 0.012}},
        {VehicleType::Delta, {200, 95, 0.9, 0.8, 3, 0.02}},
        {VehicleType::Echo, {140, 105, 1.3, 0.7, 2, 0.01}}
    };

    // Create RNG
    std::random_device rd;
    std::default_random_engine rng(rd());

    // Create fleet of 20 EVTOLs
    FleetManager fleetManager(types, rng, vehicleProfiles);
    std::vector<EVTOL>& evtols = fleetManager.getFleet();

    // Print fleet composition
    std::map<VehicleType, int> typeCounts;
    for (size_t i = 0; i < evtols.size(); ++i) {
        typeCounts[evtols[i].getType()]++;
    }

    std::cout << "Fleet composition:\n";
    int fleetTotal = 0;
    for (std::map<VehicleType, int>::const_iterator it = typeCounts.begin(); it != typeCounts.end(); ++it) {
        std::string label;
        switch (it->first) {
            case VehicleType::Alpha: label = "Alpha"; break;
            case VehicleType::Bravo: label = "Bravo"; break;
            case VehicleType::Charlie: label = "Charlie"; break;
            case VehicleType::Delta: label = "Delta"; break;
            case VehicleType::Echo: label = "Echo"; break;
            default: label = "Unknown"; break;
        }
        std::cout << label << ": " << it->second << " vehicles\n";
        fleetTotal += it->second;
        }
        std::cout << "Fleet Count Total: " << fleetTotal << " vehicles\n";

    const int timeStepMinutes = 1;
    const int totalMinutes = 180;

    std::map<int, int> flightStartTime;
    std::map<int, int> chargeStartTime;

    for (int minute = 0; minute < totalMinutes; minute += timeStepMinutes) {
        for (size_t i = 0; i < evtols.size(); ++i) {
            evtols[i].simulateStep();

            if (!evtols[i].isCharging() && !evtols[i].hasFault()) {
                flightStartTime[i]++;
            }

            if (evtols[i].hasFault()) {
                faultManager.recordFault(evtols[i].getId(), evtols[i].getFaultCode());
                statsTracker.recordFault(evtols[i].getType());
            }

            if (evtols[i].needsCharging() && evtols[i].isCharging()) {
                chargerManager.assignCharger(evtols[i], minute);

                statsTracker.recordCharge(evtols[i].getType(), evtols[i].getProfile().timeToCharge);
                statsTracker.recordFlight(
                    evtols[i].getType(),
                    flightStartTime[i],
                    evtols[i].getCruiseSpeed(),
                    evtols[i].getPassengerCapacity()
                );

                flightStartTime[i] = 0;
            }
        }

        chargerManager.update(minute);
    }

    statsTracker.setSuppressOutput(false);
    statsTracker.report();
    return 0;
}