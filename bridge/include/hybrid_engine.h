#pragma once
#include <bridge/include/bridge.h>
#include <print>
class HybridEngine : public IEngine
{
public:
    virtual void start() const override
    {
        std::print("[Hybrid Engine] : ");
    }
};
