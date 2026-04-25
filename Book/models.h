#ifndef MODELS_H
#define MODELS_H
#include "string"
using namespace std;

enum class BookGenere
{
    Fictional,
    Literature,
    Science
};
enum class BookStatus
{
    Reserved,
    Available
};
enum class PaymentType
{
    Cash,
    UPI
};

struct User
{
    string id;
    string email;
    string name;
    string phoneNo;
};

struct Book
{
    string id;
    string name;
    string author;
    BookStatus bookStatus;
    BookGenere bookGenere;
};

#endif