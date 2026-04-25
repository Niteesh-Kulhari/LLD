#pragma once
#include <string>

enum class BookingStatus
{
    Active,
    Cancelled,
    Completed // 👈 I’d add this too, since usually bookings end in "completed"
};

class Booking
{
    std::string id;
    std::string userId;
    std::string vehicleId;
    std::string spotId;
    BookingStatus status;

public:
    Booking(std::string id, std::string userId, std::string vehicleId, std::string spotId, BookingStatus status);

    std::string getBookingId() const;
    std::string getUserId() const;
    std::string getVehicleId() const;
    std::string getSpotId() const;
    BookingStatus getStatus() const;

    void setStatus(BookingStatus newStatus); // 👈 allows update
};
