#ifndef _BOOK_H_
#define _BOOK_H_

#include "person.h"
#include "member.h"
#include <sstream>
#include <vector>
#include <ctime>


class Book
{
private:
    int bookID;
    std::string bookName;
    std::string authorFirstName;
    std::string authorLastName;
    std::string bookType;
    std::time_t  dueDate;
    Member *borrower;

public:
Book(int bookID, std::string bookName, std::string authorFirstName, std::string authorLastName) : bookID(bookID), bookName(bookName), authorFirstName(authorFirstName), authorLastName(authorLastName)
 {}

    int getBookID() { return bookID; }
    std::string getBookName() { return bookName; }

    std::string getAuthorFirstName() { return authorFirstName; }
    std::string getAuthorLastName() { return authorLastName; }

   std::time_t  getDueDate() { return dueDate; }
    void setDueDate( std::time_t  dueDate);

    void borrowBook(Member *borrower,  std::time_t  dueDate);

};
#endif