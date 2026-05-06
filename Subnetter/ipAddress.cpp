#include "ipAddress.h"
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>

/*

    IDEA:

    - usare un intero a 32 bit siccome l'ip è formato da 32 bit
    - divido in 4 blocchi 
    - si fa shift destra o sinistra per i/o
    - per somme o sottrazioni è efficiente in quanto se si fa 0.0.0.255 + 1 per il 4 otteto diventa 0.0.1.0 dopo lo shift




*/

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
    split(result, ip, '.');

    if (result.size() != 4)
    {
        throw std::runtime_error("Formato IP non valido");
    }
        

    uint32_t a = std::stoi(result[0]);
    uint32_t b = std::stoi(result[1]);
    uint32_t c = std::stoi(result[2]);
    uint32_t d = std::stoi(result[3]);

    if (a > 255 || b > 255 || c > 255 || d > 255)
    {
        throw std::runtime_error("Ottetto non valido (0-255)");
    }

    ipValue = (a << 24) | (b << 16) | (c << 8) | d;

    /*
    
    ||||ESEMPIO||||

    a = 01110000 00000000 00000000 00000000

    b = 00000000 11101110 00000000 00000000

    OR-(|)-------------------------------------

    c = 01110000 11101110 00000000 00000000
    
    
    */
}

std::string ipAddress::print()
{
    return printWithoutCIDR() + "/" + std::to_string(cidr);
}

std::string ipAddress::printWithoutCIDR()
{
    uint32_t a = (ipValue >> 24) & 255;
    uint32_t b = (ipValue >> 16) & 255;
    uint32_t c = (ipValue >> 8) & 255;
    uint32_t d = ipValue & 255;

    return std::to_string(a) + "." + std::to_string(b) + "." + std::to_string(c) + "." + std::to_string(d);

    /*
        ESEMPIO
        10000010 10101010 11110000 01100100
       
        00000000 00000000 00000000 11111111

        AND-(&)----------------------------

        00000000 00000000 00000000 01100100
    

        1)

        AAAAAAAA BBBBBBBBCCCCCCCCDDDDDDDD
        >> 24

        000000000000000000000000AAAAAAAA


        2)

        00000000 00000000 00000000 AAAAAAAA
        
        00000000 00000000 00000000 11111111

        AND-(&)----------------------------

        AAAAAAAA
    
    */
}

std::string ipAddress::getSubnetMask()
{
    uint32_t mask = (0xFFFFFFFF << (32 - cidr));

    /*
    ESEMPIO

    0xFFFFFFFF = 11111111 11111111 11111111 11111111
    32 - 24 = 8

    0xFFFFFFFF << 8

    11111111  | 11111111 11111111 11111111 00000000
    troncati perchè uint32 (max 32 bit)
    */

    uint32_t a = (mask >> 24) & 255;
    uint32_t b = (mask >> 16) & 255;
    uint32_t c = (mask >> 8) & 255;
    uint32_t d = mask & 255;

    /*
        stesso esempio di sopra ma per la subnet
    */

    return std::to_string(a) + "." + std::to_string(b) + "." + std::to_string(c) + "." + std::to_string(d);
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

//inutile
void ipAddress::add(uint32_t offset)
{
    ipValue += offset;
}

//inutile
void ipAddress::sub(uint32_t offset)
{
    ipValue -= offset;
}

void ipAddress::setFromValue(uint32_t value)
{
    ipValue = value;
}

uint32_t ipAddress::getIpValue()
{
    return ipValue;
}

int ipAddress::getCidr()
{
    return cidr;
}

/*

    mi sono aiutato un pò con l'ai per quanto riguarda lo shift e l'idea 
    di usare un tipo di dato a 32 bit per contenere l'ip, inizialmente pensavo
    di usare 4 variabili int per ogni otteto... (visibile comunque dai commit)

    nonostante l'ia mi abbia 'quasi' dato la soluzione ho cercato di
    capirla affondo, ed effettivamente ora so come si fanno le operazioni
    di shifting e l'uso degli operatori logici ed ovviamente anche
    come trattare il problema dell'ip in futuro. 

    ma apparte questo, il programma non lo userò per altro, volevo
    vedere fino a quanto riuscivo a ragionare con la mia testa,
    ed effettivamente tralasciando la parte del subnetting,
    la prima idea originale di usare 4 int funzionava e sono riuscito
    a creare un oggetto ip che stampava anche la subnetmask 
    (seppur fatto molto male), ma anche con l'ia ho imparato cose nuove
    e non solo copiato e incollato, il codice ora lo conosco e so
    il PERCHE si fanno certe operazioni.

    spero di non dimenticarmene, magari le conoscenze
    che ho imparato oggi le userò in futuro :).

    - Tegra (marco)

*/

