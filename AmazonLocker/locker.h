#pragma once
#include "string"
using namespace std;

enum class lockerType
{
    Small,
    Medium,
    Large
};

enum class lockerState
{
    Available,
    Occupied
};

class Locker
{
    string id;
    lockerType type;
    lockerState state;
    string packageId;
    string pinCode;

    static int lockerCounter;

public:
    Locker(const lockerType type);

    bool isAvailable() const;

    void assignPackage(const string &packageId, const string &pinCode);

    bool verifyPin(const string &pinCode) const;

    bool release();

    string getId() const;
    lockerType getType() const;
    lockerState getState() const;
    string getPackageId() const;
    // string getPinCode() const;
};