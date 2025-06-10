#pragma once

#include "EVTOL.hpp"
#include "Config.hpp"

class DeltaEVTOL : public EVTOL {
public:
    DeltaEVTOL(int id);

    void fly(double hours) override;
    void charge() override;
    bool needsCharge() const override;

    double getCruiseSpeed() const override;
    double getBatteryCapacity() const override;
    double getChargeTime() const override;
    double getEnergyUsePerMile() const override;
    int getPassengerCount() const override;
    double getFaultProbabilityPerHour() const override;

    const char* getType() const override;
    void injectFault() override;
};