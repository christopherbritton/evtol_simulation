// FleetManager.hpp
#pragma once

#include "EVTOL.hpp"
#include "Config.hpp"
#include "Statistics.hpp"
#include <vector>
#include <map>
#include <memory>
#include <queue>
#include <string>

class FleetManager {
private:
    std::vector<std::unique_ptr<EVTOL>> fleet;
    std::map<std::string, int> typeCounts;
    std::map<std::string, Statistics> stats;
    std::queue<EVTOL*> chargeQueue;

    std::string getTypeName(const EVTOL* vehicle) const;
    void simulateStep(double hours);

public:
    void generateFleet(int count);
    void simulate(double totalHours, double stepHours);
    void simulateStep(double totalHours, double stepHours);
    void printStatistics(bool inMinutes = true) const; // Added flag to print time in minutes
};