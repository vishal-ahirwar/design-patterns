// Auto Genrated C++ file by aura CLI
// None
#include <adapter/include/adapter.h>
int main(int argc, char *argv[])
{
  std::unique_ptr<CloudStorage> services[]{std::make_unique<CloudDrive>(), std::make_unique<VirtualDeviceAdapter>(), std::make_unique<FastShare>()};
  for (std::unique_ptr<CloudStorage> &service : services)
  {
    service->uploadContents("design patterns");
  }
  return 0;
}
/*
this is the main project of this repo
*/