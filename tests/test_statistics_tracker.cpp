#include "../StatisticsTracker.hpp"
#include "../EVTOL.hpp"
#include <vector>
#include <iostream>

void test_statisticsTracker() {
    std::vector<EVTOL> evtols;
    for (int i = 0; i < 5; ++i) evtols.emplace_back(i + 1);
    StatisticsTracker tracker;
    tracker.record(evtols);
    tracker.report();
    std::cout << "test_statisticsTracker passed\n";
}

int main() {
    test_statisticsTracker();
    return 0;
}
