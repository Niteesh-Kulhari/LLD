#ifndef RESTAURANT_MANAGER_H
#define RESTAURANT_MANAGER_H

#include <string>
#include <vector>
#include <algorithm>
#include "../models/Restaurant.h"
using namespace std;

class RestaurantManager
{

private:
    vector<Restaurant *> restaurants;
    static RestaurantManager *instance;

    RestaurantManager()
    {
        // private Constructor
    }

public:
    static RestaurantManager *getInstance()
    {
        if (!instance)
        {
            instance = new RestaurantManager();
        }
        return instance;
    }

    void addRestaurant(Restaurant *res)
    {
        restaurants.push_back(res);
    }

    vector<Restaurant *> searchByLocation(const string &location)
    {
        vector<Restaurant *> res;

        transform(location.begin(), location.end(), location.begin(), ::tolower);

        for (auto r : restaurants)
        {
            string rl = r->getLocation();
            transform(rl.begin(), rl.end(), rl.begin(), ::tolower);
            if (location == rl)
                res.push_back(r);
        }

        return res;
    }
};

RestaurantManager *RestaurantManager::instance = nullptr;

#endif