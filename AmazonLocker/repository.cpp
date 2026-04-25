#include "repository.h"
using namespace std;
// ------------------ User Repo ------------------
bool UserRepo::addUser(const User &user)
{
    if (userDb.count(user.getId()))
        return false; // prevent overwrite
    userDb[user.getId()] = user;
    return true;
}

User *UserRepo::getUser(const string &id)
{
    auto it = userDb.find(id);
    if (it != userDb.end())
        return &it->second;
    return nullptr;
}

// ------------------ Locker Repo ------------------
void LockerRepo::addLocker(const Locker &locker)
{
    lockerDb[locker.getId()] = locker;
}

Locker *LockerRepo::getLocker(const string &id)
{
    auto it = lockerDb.find(id);
    return (it != lockerDb.end()) ? &it->second : nullptr;
}
unordered_map<string, Locker> &LockerRepo::getAllLockers()
{
    return lockerDb;
}

// ------------------ Package Repo ------------------
void PackageRepo::addPackage(const Package &package)
{
    packageDb[package.getId()] = package;
}

Package *PackageRepo::getPackage(const string &id)
{
    auto it = packageDb.find(id);
    return (it != packageDb.end()) ? &it->second : nullptr;
}
