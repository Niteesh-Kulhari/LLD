#ifndef SERVICES_H
#define SERVICES_H
#include "models.h"
#include "repository.h"
#include "pricing.h"
#include "payments.h"
#include <vector>

class SearchServive
{
    Repository &bookRepository;

public:
    SearchServive(Repository &bookRepository) : bookRepository(bookRepository);

    vector<Book> searchByAuthor(string author)
    {
        vector<Book> temp;

        for (auto &book : bookRepository.getAll())
        {
            if (book.author == author)
                temp.push_back(book);
        }
        return temp;
    }

    Book *searchByName(string name)
    {
        vector<Book> books = bookRepository.getAll();
        for (auto &book : books)
        {
            if (book.name == name)
                return &book;
        }

        return nullptr;
    }

    vector<Book> searchByGenere(BookGenere Genere)
    {
        vector<Book> books = bookRepository.getAll();
        vector<Book> ans;
        for (auto &book : books)
        {
            if (book.bookGenere == Genere)
            {
                ans.push_back(book);
            }
        }

        return ans;
    }
};

class LibraryService
{
    BookingRepository &bookingRepo;
    Repository &bookRepo;

public:
    bool issueBook(User user, vector<Book> books, system_clock::time_point from, system_clock::time_point to, string mode)
    {
        vector<Book> toIssue;

        for (auto &book : books)
        {
            if (book.bookStatus == BookStatus::Available)
                toIssue.push_back(book);
        }
        // Marked the books as reserved
        bookRepo.reserveBooks(toIssue);
        FlatPricingStrategy pricing;
        double amount = pricing.calculatePrice(toIssue, from, to);
        Payment pay(mode);
        pay.pay(amount);
    }

    bool cancelBooking(const string &bookingId)
    {
        Booking *booking = bookingRepo.getBooking(bookingId);
        if (!booking)
        {
            cout << "There is no booking for this" << endl;
        }
        bookingRepo.deleteBooking(booking->id);
        bookRepo.isAvailable(booking->books);
    }
};

#endif