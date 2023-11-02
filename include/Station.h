#ifndef Station_h
#define Station_h

#include <string>
#include <vector>
#include "Packet.h"

#define BUFFER_CAPACITY 5

class Station {
    private:
        int id;                             // Unique identifier for the station
        std::string name;                   // Name or label of the station
        std::vector<Packet> bufferPackets;  // A collection of packets in the station's buffer
        int wavelength;                     // Wavelength information for the station

    public:
        // Constructors
        Station(int _id, std::string _name, std::vector<Packet> _bufferPackets, int _wavelength);
        Station(int _id, std::string _name, int _wavelength);

        // Getter methods
        int getID();
        std::string getName();
        std::vector<Packet> getBufferPackets();
        int getWavelength();
};

#endif
