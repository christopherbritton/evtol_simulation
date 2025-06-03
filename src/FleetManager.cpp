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

void FleetManager::generateFleet(int size) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 4);

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

void FleetManager::simulate(double totalDurationHours, double stepHours) {
    int steps = static_cast<int>(totalDurationHours / stepHours);
    for (int i = 0; i < steps; ++i) {
        simulateStep(stepHours);
    }
}

void FleetManager::simulateStep(double hours) {
    for (const auto& vehiclePtr : fleet) {
        EVTOL* vehicle = vehiclePtr.get();
        std::string type = vehicle->getType();

        if (vehicle->isCharging()) {
            double chargeTime = vehicle->getChargeTime();
            stats[type].totalChargeTime += chargeTime;
            continue;
        }

        double availableEnergy = vehicle->getBatteryLevel();
        double cruiseSpeed = vehicle->getCruiseSpeed();
        double energyUsePerMile = vehicle->getEnergyUsePerMile();
        double maxFlightRange = availableEnergy / energyUsePerMile; // in miles
        double maxFlightTime = maxFlightRange / cruiseSpeed;         // in hours
        double flightTime = std::min(hours, maxFlightTime);

        double distanceFlown = cruiseSpeed * flightTime;
        vehicle->fly(flightTime);

        stats[type].flights++;
        stats[type].totalFlightTime += flightTime;
        stats[type].totalDistance += distanceFlown;
        stats[type].totalPassengerMiles += distanceFlown * vehicle->getPassengerCount();

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
        stats[type].totalChargeTime += v->getChargeTime();
        stats[type].charges++;
        v->charge();
    }
}

void FleetManager::printStatistics(bool detailed) const {
    StatisticsReporter reporter;
    reporter.printFleetSummary(typeCounts);  // <- This line reintroduces the fleet composition summary
    reporter.printStatisticsDetails(stats, detailed);
}



