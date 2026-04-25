#include "bookings.h"
#include "user.h"
#include "parkingSpot.h"
#include "vehicle.h"
#include <vector>
#include <unordered_map>
#include "string"
using namespace std;
#include "repository.h"

std::string Repository::generateBookingId()
{
    bookingCounter++;
    return "B" + std::to_string(bookingCounter);
}

// ---- User ----
void Repository::addUser(const User &user)
{
    userDb[user.getId()] = user;
}

User *Repository::returnUser(std::string id)
{
    if (userDb.find(id) != userDb.end())
        return &userDb[id];
    return nullptr;
}

void Repository::deleteUser(const User &user)
{
    userDb.erase(user.getId());
}

// ---- ParkingSpot ----
void Repository::addParkingSpot(const ParkingSpot &spot)
{
    spotDb[spot.getId()] = spot;
}

ParkingSpot *Repository::getSpot(const std::string &spotId)
{
    auto it = spotDb.find(spotId);
    if (it != spotDb.end())
        return &it->second;
    return nullptr;
}

void Repository::deleteParkingSpot(const std::string &spotId)
{
    spotDb.erase(spotId);
}

std::unordered_map<std::string, ParkingSpot> &Repository::getAllSpots()
{
    return spotDb;
}

// ---- Vehicle ----
void Repository::addVehicle(const Vehicle &vehicle)
{
    vehicleDb[vehicle.getId()] = vehicle;
}

Vehicle *Repository::getVehicle(const std::string &vehicleId)
{
    auto it = vehicleDb.find(vehicleId);
    if (it != vehicleDb.end())
        return &it->second;
    return nullptr;
}

void Repository::deleteVehicle(const std::string &vehicleId)
{
    vehicleDb.erase(vehicleId);
}

// ---- Booking ----
void Repository::addBooking(const Booking &booking)
{
    bookingDb[booking.getBookingId()] = booking;
}

Booking *Repository::getBooking(const std::string &bookingId)
{
    auto it = bookingDb.find(bookingId);
    if (it != bookingDb.end())
        return &it->second;
    return nullptr;
}

void Repository::deleteBooking(const std::string &bookingId)
{
    bookingDb.erase(bookingId);
}
