#pragma once
#include <bridge/include/bridge.h>
#include <print>
class Truck : public IVehicle
{
public:
    explicit Truck(const IEngine &engine) : IVehicle(engine) {};

protected:
    virtual void driveVehicle() const override
    {
        std::print("Starting Truck!\n");
    }
};
