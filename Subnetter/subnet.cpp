#include "subnet.h"
#include "ipAddress.h"

subnet::subnet(ipAddress _ip)
{
	subnet::localIp = _ip;
}

std::string subnet::execute(int nHost)
{
	int cidr = subnet::localIp.cidr;
	return "";
}