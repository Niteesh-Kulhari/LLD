#include "package.h"
#include "string"
using namespace std;

Package::Package(const string &userId, packageSize size) : userId(userId), size(size)
{
    id = "PKG_" + to_string(++packageCounter);
}

string Package::getId() const
{
    return this->id;
}

string Package::getUserId() const
{
    return this->userId;
}

packageSize Package::getSize() const
{
    return this->size;
}