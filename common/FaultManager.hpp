
#pragma once
#include <vector>
#include <utility>

// Records fault codes for EVTOLs during simulation
class FaultManager {
public:
    void recordFault(int evtolId, int faultCode); // Log a fault code
    void report() const;                          // Display all recorded faults

private:
    std::vector<std::pair<int, int>> faults;      // Pair of EVTOL ID and fault code
};
