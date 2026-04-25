#pragma once
#include <string>
#include "vehicle.h" // ✅ include header, not .cpp

enum class SpotType
{
    Small,
    Medium,
    Large
};

enum class SpotStatus
{
    Occupied,
    Available
};

class ParkingSpot
{
private:
    std::string id;
    SpotType type;
    SpotStatus status;

public:
    ParkingSpot(std::string id, SpotType type, SpotStatus status);

    SpotType getType() const;
    SpotStatus getStatus() const;
    bool isAvailable() const;
    std::string getId() const;

    void updateStatus(SpotStatus status);
    bool canFit(VehicleType vType, SpotType sType);
};
