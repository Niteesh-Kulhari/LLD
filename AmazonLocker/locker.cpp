#include "locker.h"
#include "string"
using namespace std;

Locker::Locker(const lockerType type) : type(type), state(lockerState::Available), packageId(""),
                                        pinCode("")
{
    id = "LOC_" + to_string(++lockerCounter);
}

bool Locker::isAvailable() const
{
    if (this->state == lockerState::Available)
    {
        return true;
    }
    return false;
}

void Locker::assignPackage(const string &packageId, const string &pinCode)
{
    this->packageId = packageId;
    this->pinCode = pinCode;
    this->state = lockerState::Occupied;
}

bool Locker::verifyPin(const string &pinCode) const
{
    if (pinCode == this->pinCode)
    {
        return true;
    }

    return false;
}

bool Locker::release()
{
    this->state = lockerState::Available;
    
    return true;
}

string Locker::getId() const
{
    return this->id;
}
lockerType Locker::getType() const
{
    return this->type;
}
lockerState Locker::getState() const
{
    return this->state;
}
string Locker::getPackageId() const
{
    return this->packageId;
}