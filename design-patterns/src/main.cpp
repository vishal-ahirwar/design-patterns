// Auto Genrated C++ file by aura CLI
// None
#include <adapter/include/adapter.h>
#include <vector>
class ServiceManager
{
  std::vector<std::shared_ptr<CloudStorage>> _services{};

public:
  void uploadContents(const std::string &msg)
  {
    for (const auto &service : _services)
    {
      service->uploadContents(msg);
    }
  }
  void addService(const std::shared_ptr<CloudStorage> &service)
  {
    _services.push_back(service);
  };
  void removeService(const std::shared_ptr<CloudStorage> &service)
  {
    for (auto it = _services.begin(); it != _services.end(); ++it)
    {
      if (*it == service)
      {
        _services.erase(it);
        break;
      }
    }
  }
};

int main(int argc, char *argv[])
{
  ServiceManager manager;
  manager.addService(std::make_shared<CloudDrive>());
  {
    auto virtualDeviceAdapter = std::make_shared<VirtualDeviceAdapter>();
    auto fastShare = std::make_shared<FastShare>();
    manager.addService(virtualDeviceAdapter);
    manager.addService(fastShare);
    manager.removeService(fastShare);
  }
  manager.addService(std::make_shared<FastShare>());
  manager.uploadContents("Design-Patterns::Main()");
  return 0;
}
/*
this is the main project of this repo
*/