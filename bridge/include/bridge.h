#pragma once

class IEngine
{
public:
    virtual void start() const = 0;
    virtual ~IEngine() = default;
};

class IVehicle
{
    const IEngine &_engine;

public:
    explicit IVehicle(const IEngine &engine) : _engine(engine) {};
    virtual void drive() const
    {
        _engine.start();
        driveVehicle();
    }
    virtual ~IVehicle() = default;

protected:
    virtual void driveVehicle() const = 0;
};
