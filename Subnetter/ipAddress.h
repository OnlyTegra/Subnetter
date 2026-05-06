#pragma once
#include <string>
#include <vector>

class ipAddress
{
public:
	int firstOctet;
	int secondOctet;
	int thirdOctet;
	int fourthOctet;
	int cidr;
	ipAddress();
	ipAddress(std::string _ip, int _cidr);
	ipAddress(std::string);
	std::string getSubnetMask();
	std::string print();
	std::string printWithoutCIDR();

private:
	void serializeIp(std::string ip);
	void split(std::vector<std::string> &result, std::string stringToSplit, char split);
};

