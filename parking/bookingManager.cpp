
#include "string"
#include "bookingManager.h"
#include <vector>
#include "bookings.h"
#include "repository.cpp"
#include "lotService.cpp"
#include <unordered_map>
using namespace std;

#include "bookingManager.h"

BookingManager::BookingManager(Repository &repo, LotService &lot)
    : repo(repo), lot(lot) {}

std::string BookingManager::createBooking(const User &user, const Vehicle &vehicle)
{
    std::string bookingId = lot.book(vehicle, user);

    if (!bookingId.empty())
    {
        return "Your spot has been booked with id: " + bookingId;
    }

    return "Booking Failed";
}

std::string BookingManager::cancelBooking(const std::string &bookingId)
{
    Booking *booking = repo.getBooking(bookingId);
    if (!booking)
        return "Booking Not Found";

    std::string spotId = booking->getSpotId();
    lot.freeSpot(spotId);
    repo.deleteBooking(bookingId);

    return "Booking has been successfully cancelled";
}
