#include "FleetManager.hpp"
#include <random>
#include <iostream>
#include "Config.hpp" // if you moved Config to a separate file

std::string FleetManager::getTypeName(const EVTOL* vehicle) const {
    if (dynamic_cast<const AlphaEVTOL*>(vehicle))   return "Alpha";
    if (dynamic_cast<const BravoEVTOL*>(vehicle))   return "Bravo";
    if (dynamic_cast<const CharlieEVTOL*>(vehicle)) return "Charlie";
    if (dynamic_cast<const DeltaEVTOL*>(vehicle))   return "Delta";
    if (dynamic_cast<const EchoEVTOL*>(vehicle))    return "Echo";
    return "Unknown";
}


void FleetManager::generateFleet(int count) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 4); // 0-4 for 5 types

    for (int i = 0; i < count; ++i) {
            int type = dis(gen);
            switch (type) {
    case 0:
        fleet.push_back(std::make_unique<AlphaEVTOL>());
        typeCounts["Alpha"]++;
        break;
    case 1:
        fleet.push_back(std::make_unique<BravoEVTOL>());
        typeCounts["Bravo"]++;
        break;
    case 2:
        fleet.push_back(std::make_unique<CharlieEVTOL>());
        typeCounts["Charlie"]++;
        break;
    case 3:
        fleet.push_back(std::make_unique<DeltaEVTOL>());
        typeCounts["Delta"]++;
        break;
    case 4:
        fleet.push_back(std::make_unique<EchoEVTOL>());
        typeCounts["Echo"]++;
        break;
}

        }

        std::cout << "\n\U0001F6C1 Fleet Composition:\n";
        for (const auto& [type, count] : typeCounts) {
            std::cout << "- " << type << ": " << count << " vehicle(s)\n";
        }
        std::cout << std::endl;
    }

void FleetManager::simulateStep(double hours) {
    std::mt19937 gen(std::random_device{}());

    for (auto& vehicle : fleet) {
        std::string type = getTypeName(vehicle.get());
        double cruiseSpeed = vehicle->getCruiseSpeed();
        double distance = cruiseSpeed * hours;
        vehicle->fly(hours);

        auto& s = stats[type];
        s.totalFlightTime += hours;
        s.totalDistance += distance;
        s.totalPassengerMiles += distance * vehicle->getPassengerCount();
        s.flights++;

        std::bernoulli_distribution faultDist(vehicle->getFaultProbabilityPerHour() * hours);
        if (faultDist(gen)) s.totalFaults++;

        if (vehicle->needsCharge()) {
            chargeQueue.push(vehicle.get());
        }
    }

    for (int i = 0; i < Config::MaxChargers && !chargeQueue.empty(); ++i) {
        EVTOL* v = chargeQueue.front();
        chargeQueue.pop();

        std::string type = getTypeName(v);
        stats[type].totalChargeTime += v->getChargeTime();
        stats[type].charges++;
        v->charge();
    }
}

void FleetManager::printStatistics() const {
    std::cout << "\n📊 Simulation Summary:\n";
    std::cout << "Fleet Composition (Reconfirmed):\n";
    for (const auto& [type, count] : typeCounts) {
        std::cout << "- " << type << ": " << count << " vehicle(s)\n";
    }

    for (const auto& [type, s] : stats) {
        std::cout << "\n--- " << type << " ---\n";
        std::cout << "Average Flight Time: " << (s.flights ? s.totalFlightTime / s.flights : 0) << " hrs\n";
        std::cout << "Average Distance per Flight: " << (s.flights ? s.totalDistance / s.flights : 0) << " miles\n";
        std::cout << "Average Charging Time: " << (s.charges ? s.totalChargeTime / s.charges : 0) << " hrs\n";
        std::cout << "Total Faults: " << s.totalFaults << "\n";
        std::cout << "Total Passenger Miles: " << s.totalPassengerMiles << "\n";
    }
}
