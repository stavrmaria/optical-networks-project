#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
#include "Station.h"
#include "Packet.h"

#define NO_STATIONS 8
#define NO_SLOTS 100
#define SERVER_TRANSMISSION_PROP 0.5
#define PACKET_TRANSMISSION_TIME 0.00001 // 10 microseconds

void updateWavelengths(std::unordered_map<int, int>& wavelengths, int wavelength) {
    if (wavelengths.find(wavelength) != wavelengths.end()) {
        wavelengths[wavelength]++;
    } else {
        wavelengths[wavelength] = 1;
    }
}

int main(int argc, char** argv) {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
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

    for (int slot = 0; slot < NO_SLOTS; slot++) {
        std::unordered_map<int, int> usedWavelengths;

        for (int i = 0; i < NO_STATIONS; i++) {
            float currentArrivalProp = static_cast<float>(std::rand()) / RAND_MAX;
            float transmissionProp = static_cast<float>(std::rand()) / RAND_MAX;
            int wavelength = stations[i]->getWavelength();

            // Add packet to buffer based on the arrival propability
            if (currentArrivalProp <= arrivalProp) {
                Packet packet(slot + 1, "station" + std::to_string(slot + 1), slot * PACKET_TRANSMISSION_TIME);
                bool added = stations[i]->addPacket(packet);

                if (!added) {
                    std::cout << "Packet loss" << std::endl;
                }
            }

            // Check if the station has packets in its queue and decide whether to transmit
            if (!stations[i]->isEmpty() && transmissionProp <= SERVER_TRANSMISSION_PROP) {
                updateWavelengths(usedWavelengths, wavelength);
                if (usedWavelengths[wavelength] < 1) {
                    stations[i]->removeOldestPacket();
                } else {
                    std::cout << "Collision" << std::endl;
                }
            }
        }
    }

    for (int i = 0; i < NO_STATIONS; i++)
        delete stations[i];
    
    return 0;
}