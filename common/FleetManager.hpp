#pragma once
#include <memory>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include "EVTOL.hpp"
#include "AlphaEVTOL.hpp"
#include "BravoEVTOL.hpp"
#include "CharlieEVTOL.hpp"
#include "DeltaEVTOL.hpp"
#include "EchoEVTOL.hpp"


class FleetManager {
private:
    struct Statistics {
        double totalFlightTime = 0.0;
        double totalDistance = 0.0;
        double totalChargeTime = 0.0;
        int totalFaults = 0;
        double totalPassengerMiles = 0.0;
        int flights = 0;
        int charges = 0;
    };

    std::map<std::string, int> typeCounts;
    std::map<std::string, Statistics> stats;
    std::vector<std::unique_ptr<EVTOL>> fleet;
    std::queue<EVTOL*> chargeQueue;

    std::string getTypeName(const EVTOL* vehicle) const;

public:
    void generateFleet(int count);
    void simulateStep(double hours);
    void printStatistics() const;
};
