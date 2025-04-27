// Auto Genrated C++ file by aura CLI
// None
#include <adapter/include/adapter.h>
int main(int argc, char *argv[])
{
  srand(time(nullptr));
  std::unique_ptr<CloudStorage> services[]{std::make_unique<CloudDrive>(), std::make_unique<FastShare>(), std::make_unique<VirtualDeviceAdapter>()};
  for (const std::unique_ptr<CloudStorage> &service : services)
  {
    service->uploadContents("hello-world");
    std::print("[{}]free space : {}GB\n", service->getServiceName(), service->getFreeSpace());
  }
  return 0;
}
