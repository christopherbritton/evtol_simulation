#pragma once
#include <vector>
#include <utility>

// Records fault codes for EVTOLs during simulation
class FaultManager {
public:
    void recordFault(int evtolId, int faultCode); // Log a fault code
    void report() const;                          // Display all recorded faults
    const std::vector<std::pair<int, int>>& getAllFaults() const { return faults; }  //This gives read-only access to the internal faults vector.


private:
    std::vector<std::pair<int, int>> faults;      // Pair of EVTOL ID and fault code
};
