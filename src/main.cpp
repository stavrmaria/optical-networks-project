#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
#include "Station.h"
#include "Packet.h"

// Constants
#define NO_STATIONS 8
#define NO_SLOTS 500000
#define SERVER_TRANSMISSION_PROP 0.5
#define PACKET_TRANSMISSION_TIME 0.00001 // 10 microseconds

// Function to update the wavelength count
void updateWavelengths(std::unordered_map<int, int>& wavelengths, int wavelength) {
    if (wavelengths.find(wavelength) != wavelengths.end()) {
        wavelengths[wavelength]++;
    } else {
        wavelengths[wavelength] = 1;
    }
}

int main(int argc, char** argv) {
    Station *stations[NO_STATIONS];
    float arrivalProp = 2;
    unsigned int totalPacketsSent = 0;
    unsigned int totalPacketsLost = 0;
    unsigned int totalPacketsCreated = 0;
    float totalDelay = 0;

    // Seed the random number generator
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    
    // Prompt the user for the arrival probability
    while (arrivalProp < 0 || arrivalProp > 1) {
        std::cout << "Enter the arrival propability of the packets: ";
        std::cin >> arrivalProp;
    }
    std::cout << "Arrival propability: " << arrivalProp << std::endl;

    // Initialize stations
    for (int i = 0, j = 1; i < NO_STATIONS; i++, j += (i % 2 == 0))
        stations[i] = new Station(i + 1, "station" + std::to_string(i + 1), j);
    std::cout << "Stations initialized successfully." << std::endl;
    
    std::cout << "==> Starting the transmissions..." << std::endl;
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
                totalPacketsCreated++;

                if (!added)
                    totalPacketsLost++;
            }

            // Check if the station has packets in its queue and decide whether to transmit
            if (!stations[i]->isEmpty() && transmissionProp <= SERVER_TRANSMISSION_PROP) {
                updateWavelengths(usedWavelengths, wavelength);
                if (usedWavelengths[wavelength] == 1) {
                    Packet oldestPacket = stations[i]->removeOldestPacket();
                    float packetDelay = slot * PACKET_TRANSMISSION_TIME - oldestPacket.getArrivalTime();
                    totalDelay += packetDelay;
                    totalPacketsSent++;
                }
            }
        }
    }

    // Clean up and display results
    for (int i = 0; i < NO_STATIONS; i++)
        delete stations[i];

    std::cout << "==> Results" << std::endl;
    std::cout << "Throughput: " << ((float)totalPacketsSent / NO_SLOTS) << std::endl;
    
    if (totalPacketsSent != 0) {
        std::cout << "Average Delay: " << (totalDelay / totalPacketsSent) << std::endl;
        std::cout << "Packet Loss Rate: " << ((float)totalPacketsLost / totalPacketsSent) << std::endl;
    } 
    
    return 0;
}