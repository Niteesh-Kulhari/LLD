#ifndef MENUITEM_H
#define MENUITEM_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MenuItem
{
private:
    string code;
    string name;
    int price;

public:
    MenuItem(const string &code, const string &name, const int &price)
    {
        this->code = code;
        this->name = name;
        this->price = price;
    }

    string getName()
    {
        return name;
    }

    string getCode()
    {
        return code;
    }

    int getPrice()
    {
        return price;
    }

    void setCode(const string &code)
    {
        this->code = code;
    }

    void setName(const string &name)
    {
        this->name = name;
    }

    void setprice(const int &price)
    {
        this->price = price;
    }
};

#endif