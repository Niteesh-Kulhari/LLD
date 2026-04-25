#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <vector>
using namespace std;

class User
{

private:
    string userId;
    string userName;
    string email;
    int reputation;
    vector<string> badges;
    bool active;

public:
    User(string userId, string userName, string email);
    string getUserId() const;
    string getUserName() const;
    string getEmail() const;
    int getReputation() const;
    const vector<string> &getBadges() const;
    bool isActive() const;

    void updateReputation(int points);
    void addBadges(string &badge);
    void setActive(bool status);
    void displayInfo() const;
};

#endif