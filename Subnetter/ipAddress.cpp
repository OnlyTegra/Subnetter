#include "ipAddress.h"
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>

ipAddress::ipAddress(std::string _ip, int _cidr)
{
	ipAddress::cidr = _cidr;
	ipAddress::serializeIp(_ip);
}

ipAddress::ipAddress()
{
    ipAddress::cidr = 0;
    ipAddress::serializeIp("0.0.0.0");
}

void ipAddress::serializeIp(std::string ip)
{
    std::vector<std::string> result;
    ipAddress::split(result, ip, '.');

    if (result.size() != 4)
    {
        throw std::runtime_error("Formato IP non valido");
    }

    ipAddress::firstOctet = std::atoi(result[0].c_str());
    ipAddress::secondOctet = std::atoi(result[1].c_str());
    ipAddress::thirdOctet = std::atoi(result[2].c_str());
    ipAddress::fourthOctet = std::atoi(result[3].c_str());

    if (firstOctet < 0 || firstOctet > 255 ||
        secondOctet < 0 || secondOctet > 255 ||
        thirdOctet < 0 || thirdOctet > 255 ||
        fourthOctet < 0 || fourthOctet > 255)
    {
        throw std::runtime_error("Ottetto non valido (0-255)");
    }
}

std::string ipAddress::print()
{
    return std::to_string(ipAddress::firstOctet) + "." + std::to_string(ipAddress::secondOctet) + "." + std::to_string(ipAddress::thirdOctet) + "." + std::to_string(ipAddress::fourthOctet) + "/" + std::to_string(ipAddress::cidr);
}

std::string ipAddress::printWithoutCIDR()
{
    return std::to_string(ipAddress::firstOctet) + "." + std::to_string(ipAddress::secondOctet) + "." + std::to_string(ipAddress::thirdOctet) + "." + std::to_string(ipAddress::fourthOctet);
}

std::string ipAddress::getSubnetMask()
{
    std::string temp = "";
    for (int i = 0; i < 32; i++)
    {
        if (i > 0 && i % 8 == 0)
        {
            temp += ".";
        }

        if (i < ipAddress::cidr)
        {
            temp += "1";
        }
        else
        {
            temp += "0";
        }
    }
    
    std::vector<std::string> temp2;
    ipAddress::split(temp2, temp, '.');

    return std::to_string(std::stoi(temp2[0], nullptr, 2)) + "." + std::to_string(std::stoi(temp2[1], nullptr, 2)) + "." + std::to_string(std::stoi(temp2[2], nullptr, 2)) + "." + std::to_string(std::stoi(temp2[3], nullptr, 2));
}

void ipAddress::split(std::vector<std::string> &result, std::string stringToSplit, char split)
{
    std::string temp = "";

    for (int i = 0; i < stringToSplit.length(); i++) {
        if (stringToSplit[i] == split) {
            result.push_back(temp);
            temp = "";
        }
        else {
            temp += stringToSplit[i];
        }
    }
    result.push_back(temp);
}


