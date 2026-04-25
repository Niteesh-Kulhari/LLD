#ifndef REPOSITORY_H
#define REPOSITORY_H
#include "models.h"
#include "bookings.h"
#include <unordered_map>
#include <vector>

class Repository
{
    unordered_map<string, Book> bookDB;

    // ADD, Delete, Update
public:
    void addBook(const Book &book)
    {
        bookDB[book.id] = book;
    }

    void deleteBook(const Book &book)
    {
        bookDB.erase(book.id);
    }

    void updateBook(const Book &book, string name)
    {
        bookDB[book.id].name = name;
    }

    bool isAvailable(vector<Book> books)
    {
        for (auto &book : books)
        {
            book.bookStatus = BookStatus::Available;
        }
        return true;
    }

    bool reserveBooks(vector<Book> &books)
    {
        for (auto &book : books)
        {
            bookDB[book.id].bookStatus = BookStatus::Reserved;
        }
        return true;
    }

    bool markAvailable(const Book &book)
    {
        if (bookDB[book.id].bookStatus == BookStatus::Reserved)
        {
            bookDB[book.id].bookStatus = BookStatus::Available;
            return true;
        }
        return false;
    }

    vector<Book> getAll()
    {
        vector<Book> temp;
        for (auto &book : bookDB)
        {
            temp.push_back(book.second);
        }
        return temp;
    }
};

class BookingRepository
{
    unordered_map<string, Booking> bookingDB;
    // AddBooking, DeleteBooking, updateBooking
public:
    bool addBooking(Booking &booking)
    {
        bookingDB[booking.id] = booking;
        return true;
    }

    bool deleteBooking(const string &bookingId)
    {
        auto it = bookingDB.find(bookingId);
        if (it == bookingDB.end())
            return false; // not found

        bookingDB.erase(it);
        return true;
    }

    Booking *getBooking(const string &bookingId)
    {
        if (bookingDB.find(bookingId) != bookingDB.end())
            return &bookingDB[bookingId];
        return nullptr;
    }
};

#endif