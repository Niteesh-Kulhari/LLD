#include "user.h"
using namespace std;

User::User(const string &name, const string &email, userType type) : name(name), email(email), type(type)
{
    id = "USR_" + to_string(++userCounter);
}

string User::getId() const
{
    return id;
}

string User::getName() const
{
    return name;
}

string User::getEmail() const
{
    return email;
}

userType User::getType() const
{
    return type;
}
