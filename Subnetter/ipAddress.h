#pragma once
#include <string>
#include <vector>
#include <cstdint>

class ipAddress
{
public:
    ipAddress();
    ipAddress(std::string ip, int cidr);
    ipAddress(std::string ip);

    std::string getSubnetMask();
    std::string print();
    std::string printWithoutCIDR();
    uint32_t getIpValue();
    void setFromValue(uint32_t value);
    int getCidr();

private:
    uint32_t ipValue;
    int cidr;
    void add(uint32_t offset);
    void sub(uint32_t offset);
    void serializeIp(std::string ip);
    void split(std::vector<std::string>& result, std::string stringToSplit, char split);
    std::string deserializeIp(uint32_t ip);

    uint32_t createMask();
};