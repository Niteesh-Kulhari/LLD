#pragma once
#include <string>
#include "user.h"
#include "vehicle.h"
#include "repository.h"
#include "lotService.h"

class BookingManager
{
    Repository &repo;
    LotService &lot;

public:
    BookingManager(Repository &repo, LotService &lot);

    std::string createBooking(const User &user, const Vehicle &vehicle);
    std::string cancelBooking(const std::string &bookingId);
};
