// StatisticsReporter.cpp
#include "StatisticsReporter.hpp"
#include <iostream>
#include <iomanip>

// Prints the count of each EVTOL type in the fleet
// Time Complexity: O(k), where k = number of unique EVTOL types
// Space Complexity: O(1)
void StatisticsReporter::printFleetSummary(const std::map<std::string, int>& typeCounts) {
    std::cout << "\nFleet Composition Summary:\n";
    for (std::map<std::string, int>::const_iterator entry = typeCounts.begin(); entry != typeCounts.end(); ++entry) {
        std::cout << "- " << entry->first << ": " << entry->second << " vehicles\n";
    }
}

// Prints all relevant statistics for each EVTOL type
// Time Complexity: O(k), where k = number of EVTOL types in the map
// Space Complexity: O(1)
// If inMinutes is true, all time-based outputs are converted from hours to minutes
void StatisticsReporter::printStatisticsDetails(const std::map<std::string, Statistics>& stats, bool inMinutes) {
    std::cout << "\nSimulation Statistics Summary:\n";
    for (std::map<std::string, Statistics>::const_iterator entry = stats.begin(); entry != stats.end(); ++entry) {
        const std::string& type = entry->first;
        const Statistics& stat = entry->second;


        double avgFlightTime = (stat.flights > 0) ? (stat.totalFlightTime / stat.flights) : 0.0;
        double avgChargeTime = (stat.charges > 0) ? (stat.totalChargeTime / stat.charges) : 0.0;

        double totalFlightTime = stat.totalFlightTime;
        double totalChargeTime = stat.totalChargeTime;

        if (inMinutes) {
            avgFlightTime *= 60;
            avgChargeTime *= 60;
            totalFlightTime *= 60;
            totalChargeTime *= 60;
        }

        std::string timeUnit = inMinutes ? "minutes" : "hours";

        std::cout << "\nVehicle Type: " << type << "\n"
                  << "  Total Flights       : " << stat.flights << "\n"
                  << "  Total Charges       : " << stat.charges << "\n"
                  << "  Faults Encountered  : " << stat.totalFaults << "\n"
                  << "  Avg Flight Time     : " << std::fixed << std::setprecision(2) << avgFlightTime << " " << timeUnit << "\n"
                  << "  Avg Charge Time     : " << avgChargeTime << " " << timeUnit << "\n"
                  << "  Total Flight Time   : " << totalFlightTime << " " << timeUnit << "\n"
                  << "  Total Distance      : " << stat.totalDistance << " miles\n"
                  << "  Total Charge Time   : " << totalChargeTime << " " << timeUnit << "\n"
                  << "  Total Passenger Miles: " << stat.totalPassengerMiles << "\n";
    }
}
