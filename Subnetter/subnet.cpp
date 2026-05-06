#include "subnet.h"
#include "ipAddress.h"
#include <iostream>

subnet::subnet(ipAddress _ip)
{
	subnet::localIp = _ip;
}

std::string subnet::execute(int nReti)
{
	std::string result;
	int cidr_old = subnet::localIp.getCidr();
	int Nhost = std::pow(2, 32 - cidr_old) - 2;
	int s = 0;

	while (std::pow(2, s) < nReti)
	{
		s++;
	}

	int cidr_new = cidr_old + s;
	int h = 32 - cidr_new;
	int block = std::pow(2, h);
	uint32_t base = localIp.getIpValue();
	uint32_t NA = base - (base % block);

	for (int i = 0; i < nReti; i++)
	{
		uint32_t na = NA + i * block;
		uint32_t bc = na + block - 1;

		ipAddress ip_na;
		ipAddress ip_bc;

		ip_na.setFromValue(na);
		ip_bc.setFromValue(bc);

		ipAddress ip1;
		ipAddress ipN;

		ip1.setFromValue(na + 1);
		ipN.setFromValue(bc - 1);

		result += "SOTTORETE " + std::to_string(i) + ":\n"
					+ "\tNA: " + ip_na.printWithoutCIDR() + "\n"
					+ "\t[" + ip1.printWithoutCIDR() + " - " + ipN.printWithoutCIDR() + "]\n"
					+ "\tBC: " + ip_bc.printWithoutCIDR() + "\n";
	}

	return result;

}