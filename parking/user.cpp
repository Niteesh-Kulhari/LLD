#include "string"
#include <vector>
#include <unordered_map>
using namespace std;

#include "user.h"

User::User(std::string id, std::string name, std::string email, std::string phone)
    : id(id), name(name), email(email), phone(phone) {}

std::string User::getId() const
{
    return id;
}

std::string User::getName() const
{
    return name;
}

std::string User::getEmail() const
{
    return email;
}

std::string User::getPhone() const
{
    return phone;
}
