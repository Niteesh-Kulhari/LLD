#pragma once
#include "string"
using namespace std;

enum class packageSize
{
    Small,
    Medium,
    Large
};

class Package
{
    string id;
    string userId;
    packageSize size;

    static int packageCounter;

public:
    Package(const string &userId, packageSize size);

    string getId() const;
    string getUserId() const;
    packageSize getSize() const;
};