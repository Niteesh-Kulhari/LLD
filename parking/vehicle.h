#pragma once
#include <string>

enum class VehicleType
{
    Car,
    Motorcycle,
    Truck
};

class Vehicle
{
private:
    std::string id;
    std::string licensePlate;
    VehicleType type;

public:
    Vehicle(std::string id, std::string licensePlate, VehicleType type);

    std::string getLicensePlate() const;
    std::string getId() const;
    VehicleType getVehicleType() const;
};
