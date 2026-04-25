#pragma once
#include <string>
#include <unordered_map>
#include "user.h"
#include "package.h"
#include "locker.h"
using namespace std;

// ------------------ User Repo ------------------
class UserRepo
{
private:
    unordered_map<string, User> userDb;

public:
    bool addUser(const User &user);
    User *getUser(const string &id);
};

// ------------------ Locker Repo ------------------
class LockerRepo
{
private:
    unordered_map<string, Locker> lockerDb;

public:
    void addLocker(const Locker &locker);
    Locker *getLocker(const string &id);
    unordered_map<string, Locker> &getAllLockers();
};

// ------------------ Package Repo ------------------
class PackageRepo
{
private:
    unordered_map<string, Package> packageDb;

public:
    void addPackage(const Package &package);
    Package *getPackage(const string &id);
};
