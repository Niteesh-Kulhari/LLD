#ifndef PARKING_LOT_HPP
#define PARKING_LOT_HPP

#include <vector>
#include <map>
#include <string>
#include "ParkingSpot.hpp"

using namespace std;

class ParkingLot
{
private:
    vector<ParkingSpot *> spots;
    map<string, ParkingSpot *> occupied;
    int capacity;
    int availableSpots;

public:
    ParkingLot(int numCompact, int numRegular, int numLarge);
    ~ParkingLot();

    int getCapacity() const;
    int getAvailableSpots() const;

    bool ParkVehicle(Vehicle *vehicle);
    Vehicle *removeVehicle(const string &licensePlate);
    ParkingSpot *findVehicle(const string &licensePlate);

    void displayInfo() const;
    void displayOccupancy() const;

private:
    ParkingSpot *findAvailableSpot(const Vehicle *vehicle) const;
};

#endif