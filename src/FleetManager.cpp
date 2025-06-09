#include "FleetManager.hpp"
#include "AlphaEVTOL.hpp"
#include "BravoEVTOL.hpp"
#include "CharlieEVTOL.hpp"
#include "DeltaEVTOL.hpp"
#include "EchoEVTOL.hpp"
#include "StatisticsReporter.hpp"
#include <iostream>
#include <random>
#include <unordered_map>
#include <memory>
#include <algorithm>
#include <iomanip>

// Function to randomly generate a fleet of EVTOLs
// Time complexity: O(n), where n is the fleet size
// Space complexity: O(n), each vehicle stored in a smart pointer in the fleet vector
void FleetManager::generateFleet(int size) {
    std::random_device rd;                     // source of entropy for seeding
    std::mt19937 gen(rd());                    // Mersenne Twister generator
    std::uniform_int_distribution<> dis(0, 4); // random distribution for EVTOL types

    for (int i = 0; i < size; ++i) {
        int type = dis(gen);
        switch (type) {
            case 0: fleet.push_back(std::make_unique<AlphaEVTOL>()); typeCounts["Alpha"]++; break;
            case 1: fleet.push_back(std::make_unique<BravoEVTOL>()); typeCounts["Bravo"]++; break;
            case 2: fleet.push_back(std::make_unique<CharlieEVTOL>()); typeCounts["Charlie"]++; break;
            case 3: fleet.push_back(std::make_unique<DeltaEVTOL>()); typeCounts["Delta"]++; break;
            case 4: fleet.push_back(std::make_unique<EchoEVTOL>()); typeCounts["Echo"]++; break;
        }
    }
}

// Simulates the fleet for a given total duration, broken into discrete steps
// Time complexity: O(t * n), where t = number of steps, n = fleet size
// Space complexity: O(1)
void FleetManager::simulate(double totalDurationHours, double stepHours) {
    int steps = static_cast<int>(totalDurationHours / stepHours);
    for (int i = 0; i < steps; ++i) {
        simulateStep(stepHours);
    }
}

// Simulates a single step of flight operations for all EVTOLs
// Time complexity: O(n), where n = fleet size
// Space complexity: O(n), temporary queue of charging vehicles
void FleetManager::simulateStep(double hours) {
    for (std::vector<std::unique_ptr<EVTOL>>::const_iterator vehiclePtr = fleet.begin(); vehiclePtr != fleet.end(); ++vehiclePtr) {
        EVTOL* vehicle = vehiclePtr->get();                         // raw pointer access for vehicle logic
        std::string type = vehicle->getType();
        //booking time that already occcured? Or booking time that has yet to come (time added at conclusion of step? Time leading up to the step or time leading up to the step?)
        if (vehicle->isCharging()) {
            double chargeTime = vehicle->getChargeTime();           // hours
            stats[type].totalChargeTime += chargeTime;
            continue;
        }

        double availableEnergy = vehicle->getBatteryLevel();        // kWh
        double cruiseSpeed = vehicle->getCruiseSpeed();             // mph
        double energyUsePerMile = vehicle->getEnergyUsePerMile();   // kWh per mile
        double maxFlightRange = availableEnergy / energyUsePerMile; // miles
        double maxFlightTime = maxFlightRange / cruiseSpeed;        // hours
        double flightTime = std::min(hours, maxFlightTime);         // hours

        double distanceFlown = cruiseSpeed * flightTime;            // miles
        vehicle->fly(flightTime);

        stats[type].flights++;
        stats[type].totalFlightTime += flightTime;                                       // hours
        stats[type].totalDistance += distanceFlown;                                      // miles
        stats[type].totalPassengerMiles += distanceFlown * vehicle->getPassengerCount(); // passenger-miles

        if (vehicle->checkForFault()) {
            stats[type].totalFaults++;
        }

        if (vehicle->needsCharge()) {
            chargeQueue.push(vehicle);
        }
    }

    for (int i = 0; i < Config::MaxChargers && !chargeQueue.empty(); ++i) {
        EVTOL* v = chargeQueue.front();
        chargeQueue.pop();

        std::string type = v->getType();
        stats[type].totalChargeTime += v->getChargeTime(); // hours (double booking?)
        stats[type].charges++;
        v->charge();
    }
}

// Prints fleet summary and optionally detailed statistics
// Time complexity: O(k), where k = number of EVTOL types
void FleetManager::printStatistics(bool detailed) const {
    StatisticsReporter reporter;
    reporter.printFleetSummary(typeCounts);            // outputs number of vehicles per type
    reporter.printStatisticsDetails(stats, detailed);  // outputs performance stats per type
}