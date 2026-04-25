#include "ParkingSpot.hpp"
#include <iostream>

ParkingSpot::ParkingSpot(int spotNumber, SpotType type)
    : spotNumber(spotNumber), type(type), vehicle(nullptr), available(true) {}

int ParkingSpot::getSpotNumber() const { return spotNumber; }
SpotType ParkingSpot::getType() const { return type; }
Vehicle *ParkingSpot::getVehicle() const { return vehicle; }
bool ParkingSpot::isAvailable() const { return available; }

bool ParkingSpot::canFitVehicle(const Vehicle *vehicle) const
{
    if (!vehicle)
        return false;

    switch (vehicle->getType())
    {
    case VehicleType::MOTORCYCLE:
        return true;
    case VehicleType::CAR:
        return type != SpotType::COMPACT;
    case VehicleType::BUS:
    case VehicleType::TRUCK:
        return type == SpotType::LARGE;
    }

    return false;
}

bool ParkingSpot::parkVehicle(Vehicle *vehicle)
{
    if (!available || !canFitVehicle(vehicle))
        return false;

    this->vehicle = vehicle;
    available = false;
    return true;
}

Vehicle *ParkingSpot::removeVehicle()
{
    if (!vehicle)
        return nullptr;

    Vehicle *removedVehicle = vehicle;
    this->vehicle = nullptr;
    available = true;
    return removedVehicle;
}

void ParkingSpot::displayInfo() const
{
    cout << "Spot: " << spotNumber << "(";

    switch (type)
    {
    case SpotType::COMPACT:
        cout << "Compact";
        break;
    case SpotType::LARGE:
        cout << "Large";
        break;
    case SpotType::REGULAR:
        cout << "Regular";
        break;
    }

    cout << "): " << (available ? "Available" : "Occupied");
    if (vehicle)
    {
        cout << " by ";
        vehicle->displayInfo();
    }
    else
    {
        cout << endl;
    }
}