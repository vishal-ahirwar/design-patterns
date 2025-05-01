#pragma once
#include <bridge/include/bridge.h>
#include <print>
class Car : public IVehicle
{
public:
    explicit Car(const IEngine &engine) : IVehicle(engine) {};

protected:
    virtual void driveVehicle() const override
    {
        std::print("Starting Car!\n");
    }
};
