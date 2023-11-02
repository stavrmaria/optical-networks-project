#include <iostream>
#include "Station.h"
#include "Packet.h"

#define NO_STATIONS 8
#define SERVER_TRANSMISSION_PROP 0.5

int main(int argc, char** argv) {
    Station *stations[NO_STATIONS];
    float arrivalProp = 2;
    
    while (arrivalProp < 0 || arrivalProp > 1) {
        std::cout << "Enter the arrival propability of the packets: ";
        std::cin >> arrivalProp;
    }
    std::cout << "Arrival propability: " << arrivalProp << std::endl;

    for (int i = 0, j = 1; i < NO_STATIONS; i++, j += (i % 2 == 0))
        stations[i] = new Station(i + 1, "station" + std::to_string(i + 1), j);
    std::cout << "Stations initialized successfully." << std::endl;

    for (int i = 0; i < NO_STATIONS; i++)
        delete stations[i];
    
    return 0;
}