#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "Cart.h"
using namespace std;

class User
{
private:
    int userId;
    string name;
    string address;
    Cart *cart;

public:
    User(int userId, const string &name, const string &address)
    {
        this->userId = userId;
        this->name = name;
        this->address = address;
        cart = new Cart();
    }

    ~User()
    {
        delete cart;
    }

    string getName()
    {
        return name;
    }

    string setName(const string &name)
    {
        this->name = name;
    }

    string getAddress()
    {
        return address;
    }

    string setAddress(const string &address)
    {
        this->address = address;
    }

    Cart *getCart()
    {
        return cart;
    }
};

#endif