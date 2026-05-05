#include <iostream>
#include "ipAddress.h"

int main()
{
    //ESEMPIO
    try
    {
        ipAddress ip("192.152.0.23", 13);
        std::cout << "IP: " << ip.print() << std::endl;

        std::cout << "SUBNET MASK: " << ip.getSubnetMask();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    

}

