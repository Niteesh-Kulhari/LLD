#ifndef BOOKINGS_H
#define BOOKINGS_H
#include "models.h"
#include <string>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

struct Booking
{
    string id;
    User user;
    vector<Book> books;
    system_clock::time_point from;
    system_clock::time_point to;
    double amount{};
    PaymentType mode;
    bool isActive;

    Booking(User u, vector<Book> b,
            system_clock::time_point f,
            system_clock::time_point t,
            PaymentType mode)
        : id(to_string(rand())), user(u), books(move(b)),
          from(f), to(t), mode(mode), isActive(true) {}
};

#endif