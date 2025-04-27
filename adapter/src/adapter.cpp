#include <adapter/include/adapter.h>

void CloudDrive::uploadContents(const std::string &content)
{
    std::print("Uploading {} bytes to {}.\n", content.length(), getServiceName());
}

int CloudDrive::getFreeSpace()
{
    return rand() % 10;
};

std::string CloudDrive::getServiceName()
{
    return "CloudDrive";
}

void FastShare::uploadContents(const std::string &content)
{
    std::print("Uploading {} bytes to {}.\n", content.length(), getServiceName());
}

int FastShare::getFreeSpace()
{
    return rand() % 10;
}

std::string FastShare::getServiceName()
{
    return "FastShare";
}

bool VirtualDrive::uploadData(const std::string &data, const int uniqueID)
{
    std::print("Uploading to VirtualDrive :{} , ID:{}.\n", data, uniqueID);
    return true;
}

int VirtualDrive::usedSpace() const
{
    return rand() % 10;
};

void VirtualDeviceAdapter::uploadContents(const std::string &content)
{
    uploadData(content, rand() % 1000 + 100);
};

int VirtualDeviceAdapter::getFreeSpace()
{
    return totalSpace - usedSpace();
}

std::string VirtualDeviceAdapter::getServiceName()
{
    return "VirtualDrive";
}