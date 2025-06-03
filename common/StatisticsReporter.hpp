#pragma once
#include <map>
#include <string>
#include "Statistics.hpp"

class StatisticsReporter {
public:
    static void printFleetSummary(const std::map<std::string, int>& typeCounts);
    static void printStatisticsDetails(const std::map<std::string, Statistics>& stats, bool inMinutes);

};
