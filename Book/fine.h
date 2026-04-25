#ifndef FINE_H
#define FINE_H
#include "models.h"
#include "vector"
using namespace std;
using namespace std::chrono;

class FineStratergy
{
public:
    virtual double calculateFine(vector<Book> &books, system_clock::time_point from, system_clock::time_point to) = 0;
};

class FlatFine
{
public:
    double calculateFine(vector<Book> &books, system_clock::time_point from, system_clock::time_point to)
    {
        auto days = duration_cast<hours>(to - from).count() / 24;
        if (days < 0)
            return 0.0;
        return days * 100 * books.size();
    }
};

#endif