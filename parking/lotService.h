#pragma once
#include <string>
#include "repository.h"
#include "vehicle.h"
#include "parkingSpot.h"
#include "bookings.h"

class LotService
{
private:
    Repository &repo;

    VehicleType getType(std::string vehicleId);
    ParkingSpot *getSpot(VehicleType type);

public:
    LotService(Repository &r);

    std::string book(const Vehicle &v, const User &user);
    void freeSpot(const std::string &spotId);
};
