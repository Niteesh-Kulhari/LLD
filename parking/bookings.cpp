
#include "string"
using namespace std;

#include "bookings.h"

Booking::Booking(std::string id, std::string userId, std::string vehicleId, std::string spotId, BookingStatus status)
    : id(id), userId(userId), vehicleId(vehicleId), spotId(spotId), status(status) {}

std::string Booking::getBookingId() const { return id; }
std::string Booking::getUserId() const { return userId; }
std::string Booking::getVehicleId() const { return vehicleId; }
std::string Booking::getSpotId() const { return spotId; }
BookingStatus Booking::getStatus() const { return status; }

void Booking::setStatus(BookingStatus newStatus)
{
    status = newStatus;
}
