#pragma once
#include <iostream>
#include <memory>
#include <print>
#include <random>
#include <design-patternsconfig.h>
class CloudStorage
{
public:
  virtual void uploadContents(const std::string &content) = 0;
  virtual int getFreeSpace() = 0;
  virtual std::string getServiceName() = 0;
  virtual ~CloudStorage() = default;
};

class CloudDrive : public CloudStorage
{
public:
  void uploadContents(const std::string &content) override;
  int getFreeSpace() override;
  std::string getServiceName() override;
};
class FastShare : public CloudStorage
{
public:
  void uploadContents(const std::string &content) override;
  int getFreeSpace() override;
  std::string getServiceName() override;
};

// 3rd party service that we want to integrate in our CloudStorage
class VirtualDrive
{
public:
  bool uploadData(const std::string &data, const int uniqueID);
  int usedSpace() const;
  const int totalSpace = 15;
};

class VirtualDeviceAdapter : public CloudStorage, private VirtualDrive
{
public:
  void uploadContents(const std::string &content) override;
  int getFreeSpace() override;
  std::string getServiceName() override;
};