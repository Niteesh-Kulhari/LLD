#ifndef PAYMENTS_H
#define PAYMENTS_H
#include "models.h"
#include <iostream>
#include <string>
using namespace std;
using namespace std::chrono;

class Payment
{
    string mode; // e.g. "UPI" or "Cash"

public:
    Payment(const string &mode) : mode(mode) {}

    void pay(double amount)
    {
        cout << "[" << mode << " Payment] of "
             << amount << " received" << endl;
    }
};

#endif