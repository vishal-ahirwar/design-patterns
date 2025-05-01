// Auto Genrated C++ file by aura CLI
// None
#include <bridge/include/bike.h>
#include <bridge/include/bus.h>
#include <bridge/include/car.h>
#include <bridge/include/truck.h>
#include <bridge/include/gas_engine.h>
#include <bridge/include/electric_engine.h>
#include <bridge/include/hybrid_engine.h>
#include <design-patternsconfig.h>
#include <memory>

int main(int argc, char *argv[])
{
  auto electricEngine = ElectricEngine();
  auto gasEngine = GasEngine();
  auto hybridEngine = HybridEngine();
  std::unique_ptr<IVehicle> vehicles[] = {
      std::make_unique<Car>(electricEngine),
      std::make_unique<Bus>(hybridEngine),
      std::make_unique<Truck>(gasEngine),
      std::make_unique<Bike>(electricEngine),
      std::make_unique<Car>(hybridEngine)};
  for (std::unique_ptr<IVehicle> &vehicle : vehicles)
  {
    vehicle->drive();
  };

  return 0;
}
