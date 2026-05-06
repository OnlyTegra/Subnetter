#include <iostream>
#include "ipAddress.h"
#include "subnet.h";

#define N_RETI 4
#define CIDR 24

int main()
{
    //ESEMPIO
    try
    {
        ipAddress ip("192.168.0.67", CIDR);
        subnet sub(ip);

        std::cout << "NUMERO DI RETI DA RICAVARE: " << std::to_string(N_RETI) << std::endl;
        std::cout << "IP DI PARTENZA: " << ip.print() << std::endl;
        std::cout << "SUBNET MASK: " << ip.getSubnetMask() << std::endl;
        std::cout << "--------------------------------" << std::endl;
        std::cout << sub.execute(N_RETI) << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    

}

