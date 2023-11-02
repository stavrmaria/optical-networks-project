#include "Station.h"

// Initialize the station
Station::Station(int _id, std::string _name, std::vector<Packet> _bufferPackets, int _wavelength) {
    this->id = _id;
    this->name = _name;
    this->bufferPackets = _bufferPackets;
    this->wavelength = _wavelength;
}

Station::Station(int _id, std::string _name, int _wavelength) {
    this->id = _id;
    this->name = _name;
    this->bufferPackets = {};
    this->wavelength = _wavelength;
}

// Return the station's ID
int Station::getID() {
    return this->id;
}

// Return the station's name
std::string Station::getName() {
    return this->name;
}

// Return the station's buffer packets
std::vector<Packet> Station::getBufferPackets() {
    return this->bufferPackets;
}

// Return the station's wavelength
int Station::getWavelength() {
    return this->wavelength;
}
