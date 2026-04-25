#include "User.hpp"
#include <iostream>

User::User(string userId, string userName, string email)
    : userId(userId), userName(userName), email(email), reputation(1), active(true) {}

string User::getUserId() const
{
    return userId;
}

string User::getUserName() const
{
    return userName;
}

string User::getEmail() const
{
    return email;
}

int User::getReputation() const
{
    return reputation;
}

const vector<string> &User::getBadges() const
{
    return badges;
}

bool User::isActive() const
{
    return active;
}

void User::updateReputation(int points)
{
    reputation += points;
}

void User::addBadges(string &badge)
{
    badges.push_back(badge);
}

void User::setActive(bool status)
{
    active = status;
}

void User::displayInfo() const
{
    cout << "User: " << userName << " (Id: " << userId << ")" << endl;
    cout << "Email: " << email << endl;
    cout << "Reputation: " << reputation << endl;
    cout << "Status: " << (active ? "Active" : "Inactive") << endl;

    if (!badges.empty())
    {
        cout << "Badges:" << endl;

        for (const auto &badge : badges)
        {
            cout << "- " << badge << endl;
        }
    }
}