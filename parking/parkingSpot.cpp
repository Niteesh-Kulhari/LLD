#include "string"
#include "vehicle.h"
using namespace std;

#include "parkingSpot.h"
#include <stdexcept> // for runtime_error

ParkingSpot::ParkingSpot(std::string id, SpotType type, SpotStatus status)
    : id(id), type(type), status(status) {}

SpotType ParkingSpot::getType() const
{
    return type;
}

SpotStatus ParkingSpot::getStatus() const
{
    return status;
}

bool ParkingSpot::isAvailable() const
{
    return status == SpotStatus::Available;
}

std::string ParkingSpot::getId() const
{
    return id;
}

void ParkingSpot::updateStatus(SpotStatus newStatus)
{
    if (newStatus == SpotStatus::Occupied && status == SpotStatus::Occupied)
    {
        throw std::runtime_error("The Parking spot is already booked");
    }
    status = newStatus; // ✅ actually update it
}

bool ParkingSpot::canFit(VehicleType vType, SpotType sType)
{
    if (vType == VehicleType::Motorcycle)
        return true; // fits anywhere
    if (vType == VehicleType::Car && (sType == SpotType::Medium || sType == SpotType::Large))
        return true;
    if (vType == VehicleType::Truck && sType == SpotType::Large)
        return true;
    return false;
}
