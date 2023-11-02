#ifndef Packet_h
#define Packet_h

#include <string>

class Packet {
private:
    int id;               // Identifier for the packet
    std::string name;     // Name or description of the packet
    float arrivalTime;    // Time at which the packet arrived

public:
    // Constructor
    Packet(int, std::string, float);

    // Getter methods
    int getID();
    std::string getName();
    float getArrivalTime();
};

#endif
