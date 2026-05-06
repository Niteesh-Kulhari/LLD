#ifndef CART_H
#define CART_H

#include <string>
#include <vector>
#include "MenuItem.h"
#include "Restaurant.h"
using namespace std;

class Cart
{
private:
    Restaurant *restaurant;
    vector<MenuItem> items;

public:
    Cart()
    {
        restaurant = nullptr;
    }

    void addItem(const MenuItem &item)
    {
        if (!restaurant)
        {
            cerr << "Cart: set a restaurant before adding items." << endl;
            return;
        }
        items.push_back(item);
    }

    double getTotalCost()
    {
        double sum = 0;
        for (auto i : items)
        {
            sum += i.getPrice();
        }
        return sum;
    }

    void clearCart()
    {
        items.clear();
        restaurant = nullptr;
    }

    bool isEmpty()
    {
        if (!items.empty())
            return true;
        return false;
    }
};

#endif