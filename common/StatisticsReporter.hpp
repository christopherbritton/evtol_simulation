#pragma once

#include <map>
#include <string>
#include "Statistics.hpp"

// Responsible for reporting simulation results to the console
class StatisticsReporter {
public:
    // Prints a summary of fleet composition: number of vehicles per type
    static void printFleetSummary(const std::map<std::string, int>& typeCounts);

    // Prints detailed simulation statistics for each EVTOL type
    // Parameters:
    // - stats: mapping of vehicle type name to Statistics object
    // - inMinutes: whether to display time in minutes instead of hours
    static void printStatisticsDetails(const std::map<std::string, Statistics>& stats, bool inMinutes);
};
