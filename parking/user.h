#pragma once
#include <string>

class User
{
private:
    std::string id;
    std::string name;
    std::string email;
    std::string phone;

public:
    User(std::string id, std::string name, std::string email, std::string phone);

    std::string getId() const;
    std::string getName() const;
    std::string getEmail() const;
    std::string getPhone() const;
};
