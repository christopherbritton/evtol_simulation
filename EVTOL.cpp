#include "EVTOL.hpp"
#include <cstdlib>
EVTOL::EVTOL(int id) : id(id), fault(false), chargingNeeded(false), faultCode(0) {}
bool EVTOL::coinFlip(int odds) { return (rand() % odds) == 0; }
void EVTOL::simulateStep() {
    fault = coinFlip(10);               // 10% chance
    chargingNeeded = coinFlip(3);       // ~33% chance
    faultCode = fault ? (100 + rand() % 50) : 0;
}
bool EVTOL::hasFault() const { return fault; }
bool EVTOL::needsCharging() const { return chargingNeeded; }
int EVTOL::getId() const { return id; }
int EVTOL::getFaultCode() const { return faultCode; }
