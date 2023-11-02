#include "Packet.h"

// Initialize the packet
Packet::Packet(int _id, std::string _name, float _arrivalTime) {
    this->id = _id;
    this->name = _name;
    this->arrivalTime = _arrivalTime;
}

// Return the packet's identifier
int Packet::getID() {
    return this->id;
}

// Return the packet's name
std::string Packet::getName() {
    return this->name;
}

// Return the packet's arrival time
float Packet::getArrivalTime() {
    return this->arrivalTime;
}
