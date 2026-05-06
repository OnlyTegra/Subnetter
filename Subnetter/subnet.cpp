#include "subnet.h"
#include "ipAddress.h"ù
#include <iostream>

subnet::subnet(ipAddress _ip)
{
	subnet::localIp = _ip;
}

std::string subnet::execute(int nReti)
{
	int cidr = subnet::localIp.cidr;
	//Nhost​=2^(32−CIDR)−2

	int Nhost = std::pow(2, 32 - cidr) - 2;
	int nSubnet = Nhost + 2;
	ipAddress newIp(subnet::localIp.printWithoutCIDR(), 23);
	return "";
}