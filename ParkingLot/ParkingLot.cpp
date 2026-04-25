#include "ParkingLot.hpp"
#include <iostream>

using namespace std;

ParkingLot::ParkingLot(int numCompact, int numRegular, int numLarge)
    : capacity(numCompact + numRegular + numLarge), availableSpots(capacity)
{

    int spotNumber = 1;

    for (int i = 0; i < numCompact; i++)
    {
        spots.push_back(new ParkingSpot(spotNumber++, SpotType::COMPACT));
    }

    for (int i = 0; i < numRegular; i++)
    {
        spots.push_back(new ParkingSpot(spotNumber++, SpotType::REGULAR));
    }

    for (int i = 0; i < numLarge; i++)
    {
        spots.push_back(new ParkingSpot(spotNumber++, SpotType::LARGE));
    }
}

ParkingLot::~ParkingLot()
{
    for (auto spot : spots)
    {
        delete spot;
    }
}

int ParkingLot::getCapacity() const { return capacity; }
int ParkingLot::getAvailableSpots() const { return availableSpots; }

bool ParkingLot::ParkVehicle(Vehicle *vehicle)
{
    if (!vehicle)
        return false;

    if (occupied.find(vehicle->getLicensePlate()) != occupied.end())
    {
        return false;
    }

    ParkingSpot *spot = findAvailableSpot(vehicle);

    if (!spot)
        return false;

    if (spot->parkVehicle(vehicle))
    {
        occupied[vehicle->getLicensePlate()] = spot;
        availableSpots--;
        return true;
    }

    return false;
}

Vehicle *ParkingLot::removeVehicle(const string &licensePlate)
{
    if (licensePlate.length() == 0)
        return nullptr;

    auto it = occupied.find(licensePlate);
    if (it == occupied.end())
        return nullptr;

    ParkingSpot *spot = it->second;
    Vehicle *vehicle = spot->removeVehicle();

    if (vehicle)
    {
        occupied.erase(it);
        availableSpots++;
    }

    return vehicle;
}

ParkingSpot *ParkingLot::findVehicle(const string &licensePlate)
{
    if (licensePlate.empty())
        return nullptr;

    auto it = occupied.find(licensePlate);
    if (it == occupied.end())
        return nullptr;

    return it->second;
}

void ParkingLot::displayInfo() const
{
    cout << "\nParking Lot Status:" << endl;
    cout << "Total Capacity: " << capacity << endl;
    cout << "Available Spots: " << availableSpots << endl;
    cout << "Occupied Spots: " << (capacity - availableSpots) << endl;
}

void ParkingLot::displayOccupancy() const
{
    cout << "\nDetailed Occupancy:" << endl;

    for (auto spot : spots)
    {
        spot->displayInfo();
    }
}

ParkingSpot *ParkingLot::findAvailableSpot(const Vehicle *vehicle) const
{
    for (auto spot : spots)
    {
        if (spot->isAvailable() && spot->canFitVehicle(vehicle))
        {
            return spot;
        }
    }

    return nullptr;
}
