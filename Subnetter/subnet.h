#pragma once
#include "ipAddress.h"
class subnet
{
public:
	subnet(ipAddress _ip);
	std::string execute(int nReti);
private:
	ipAddress localIp;
};

