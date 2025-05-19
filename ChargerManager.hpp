#pragma once
#include <vector>
#include <queue>
#include "EVTOL.hpp"

class ChargerManager {
public:
    ChargerManager(int n);
    void assignChargers(std::vector<EVTOL*>& vehicles);

private:
    int available;
    std::queue<EVTOL*> queue;
};

inline ChargerManager::ChargerManager(int n) : available(n) {}

inline void ChargerManager::assignChargers(std::vector<EVTOL*>& vehicles) {
    for (std::vector<EVTOL*>::iterator it = vehicles.begin(); it != vehicles.end(); ++it) {
        if ((*it)->isWaiting()) queue.push(*it);
    }
    while (!queue.empty() && available > 0) {
        EVTOL* v = queue.front();
        queue.pop();
        v->startCharging();
        --available;
    }
    available = 3;
}