#pragma once
#include <string>
#include "user.h"
#include "package.h"
#include "locker.h"
#include "repository.h"
using namespace std;

class LockerManager
{
    UserRepo &userRepo;
    PackageRepo &packageRepo;
    LockerRepo &lockerRepo;

public:
    LockerManager(UserRepo &ur, PackageRepo &pr, LockerRepo &lr);

    string assignPackage(const string &packageId, const string &userId, const string &pinCode);

    bool pickupPackage(const string &lockerId, const string &pinCode);
};
