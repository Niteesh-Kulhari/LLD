#include "string"
using namespace std;

#include "vehicle.h"

Vehicle::Vehicle(std::string id, std::string licensePlate, VehicleType type)
    : id(id), licensePlate(licensePlate), type(type) {}

std::string Vehicle::getLicensePlate() const
{
    return licensePlate;
}

std::string Vehicle::getId() const
{
    return id;
}

VehicleType Vehicle::getVehicleType() const
{
    return type;
}
