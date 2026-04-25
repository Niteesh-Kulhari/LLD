#pragma once
#include "models.h"
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

class PricingStrategy
{
public:
    virtual double calculatePrice(const vector<Book> &books,
                                  system_clock::time_point from,
                                  system_clock::time_point to) = 0;
    virtual ~PricingStrategy() = default;
};

class FlatPricingStrategy : public PricingStrategy
{
public:
    double calculatePrice(const vector<Book> &books,
                          system_clock::time_point from,
                          system_clock::time_point to)
    {
        auto days = duration_cast<hours>(to - from).count() / 24;
        return 100.0 * days * books.size();
    }
};
