#include "string"
#include <vector>
#include "bookings.h"
#include "repository.h"
#include <unordered_map>
using namespace std;

class LotService
{
private:
    Repository &repo;

    VehicleType getType(string vehicleId)
    {
        return repo.getVehicle(vehicleId)->getVehicleType();
    }

    ParkingSpot *getspot(VehicleType type)
    {
        auto &db = repo.getAllSpots();
        for (auto &elem : db)
        {
            ParkingSpot *spot = &elem.second;
            if (spot->isAvailable() && spot->canFit(type, spot->getType()))
            {
                return spot;
            }
        }
        return nullptr;
    }

public:
    LotService(Repository &r) : repo(r) {}

    string book(const Vehicle &v, const User &user)
    {
        VehicleType type = getType(v.getId());

        ParkingSpot *spot = getspot(type);
        if (!spot)
            throw runtime_error("No Parking spot available for your vehicle");

        string bookingId = repo.generateBookingId();
        Booking book(bookingId, user.getId(), v.getId(), spot->getId(), BookingStatus::Active);

        repo.addBooking(book);

        spot->updateStatus(spotStatus::Occupied);

        return bookingId;
    }

    void freeSpot(const string &spotId)
    {
        ParkingSpot *spot = repo.getSpot(spotId);
        if (!spot)
            throw runtime_error("No spot found");
        spot->updateStatus(spotStatus::Available);
    }
};