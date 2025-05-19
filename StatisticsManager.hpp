#pragma once
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include "EVTOL.hpp"

class StatisticsManager {
public:
    void collect(const std::vector<EVTOL>& fleet);
    void report() const;

private:
    std::map<std::string, Statistics> reportData;
};

inline void StatisticsManager::collect(const std::vector<EVTOL>& fleet) {
    for (std::vector<EVTOL>::const_iterator it = fleet.begin(); it != fleet.end(); ++it) {
        const std::string& company = it->getCompany();
        reportData[company].totalFlightTime += it->stats.totalFlightTime;
        reportData[company].totalDistance += it->stats.totalDistance;
        reportData[company].totalChargeTime += it->stats.totalChargeTime;
        reportData[company].faultCount += it->stats.faultCount;
        reportData[company].passengerMiles += it->stats.passengerMiles;
        reportData[company].flightCount += it->stats.flightCount;
        reportData[company].chargeCount += it->stats.chargeCount;
    }
}

inline void StatisticsManager::report() const {
    for (std::map<std::string, Statistics>::const_iterator rpt = reportData.begin(); rpt != reportData.end(); ++rpt) {
        const std::string& company = rpt->first;
        const Statistics& stat = rpt->second;
        std::cout << "\n--- " << company << " Company ---" << std::endl;
        std::cout << "Avg Flight Time: " << (stat.flightCount ? stat.totalFlightTime / stat.flightCount : 0) << " mins\n";
        std::cout << "Avg Distance: " << (stat.flightCount ? stat.totalDistance / stat.flightCount : 0) << " miles\n";
        std::cout << "Avg Charge Time: " << (stat.chargeCount ? stat.totalChargeTime / stat.chargeCount : 0) << " mins\n";
        std::cout << "Total Faults: " << stat.faultCount << "\n";
        std::cout << "Total Passenger Miles: " << stat.passengerMiles << std::endl;
    }
}