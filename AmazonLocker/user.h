#pragma once
#include "string"
using namespace std;

enum class userType
{
    Consumer,
    Delivery
};

class User
{
    string id;
    string name;
    string email;
    userType type;

    static int userCounter;

public:
    User(const string &name,
         const string &email, userType type);

    string getId() const;
    string getName() const;
    string getEmail() const;
    userType getType() const;
};