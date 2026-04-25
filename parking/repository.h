#pragma once
#include <string>
#include <unordered_map>
#include "user.h"
#include "parkingSpot.h"
#include "Vehicle.h"
#include "bookings.h"

class Repository
{
private:
    std::unordered_map<std::string, User> userDb;
    std::unordered_map<std::string, ParkingSpot> spotDb;
    std::unordered_map<std::string, Vehicle> vehicleDb;
    std::unordered_map<std::string, Booking> bookingDb;

    int bookingCounter = 0;

public:
    // ---- Booking ID Generator ----
    std::string generateBookingId();

    // ---- User Db Actions ----
    void addUser(const User &user);
    User *returnUser(std::string id);
    void deleteUser(const User &user);

    // ---- Parking Spot Db Actions ----
    void addParkingSpot(const ParkingSpot &spot);
    ParkingSpot *getSpot(const std::string &spotId);
    void deleteParkingSpot(const std::string &spotId);
    std::unordered_map<std::string, ParkingSpot> &getAllSpots();

    // ---- Vehicle Db Actions ----
    void addVehicle(const Vehicle &vehicle);
    Vehicle *getVehicle(const std::string &vehicleId);
    void deleteVehicle(const std::string &vehicleId);

    // ---- Booking Db Actions ----
    void addBooking(const Booking &booking);
    Booking *getBooking(const std::string &bookingId);
    void deleteBooking(const std::string &bookingId);
};
