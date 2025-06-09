//FleetManager.hpp
#pragma once

#include "EVTOL.hpp"
#include "Config.hpp"
#include "Statistics.hpp"
#include <vector>
#include <map>
#include <memory>
#include <queue>
#include <string>

// FleetManager manages a fleet of EVTOL vehicles, simulates operations,
// and collects statistical performance metrics.
class FleetManager {
private:
    std::vector<std::unique_ptr<EVTOL>> fleet;                
    std::map<std::string, int> typeCounts;                    
    std::map<std::string, Statistics> stats;                  
    std::queue<EVTOL*> chargeQueue;                           

    // Retrieves the vehicle type name 
    std::string getTypeName(const EVTOL* vehicle) const {
        return vehicle->getType(); 
}


    // Runs simulation step for all vehicles in the fleet
    void simulateStep(double hours);

public:
    // Generates random fleet composition
    void generateFleet(int count);

    // Runs full simulation for totalHours in discrete steps of stepHours
    void simulate(double totalHours, double stepHours);

    // Prints summary statistics and optionally includes time in minutes
    void printStatistics(bool inMinutes = true) const;
};