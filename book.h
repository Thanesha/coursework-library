#ifndef _BOOK_H_
#define _BOOK_H_

#include "member.h"
#include "person.h"
class Book 
{
private:
    int bookID;
    std::string bookName;
    std::string authorFirstName;
    std::string authorLastName;
    std::string bookType;
    time_t  dueDate;
    Member *borrower;

public:
 Book(int bookID, std::string bookName, std::string authorFirstName, std::string authorLastName) : bookID(bookID), bookName(bookName), authorFirstName(authorFirstName), authorLastName(authorLastName)
 {}
 Book(){}
    int getBookID() { return bookID; }
    std::string getBookName() { return bookName; }

    std::string getAuthorFirstName() { return authorFirstName; }
    std::string getAuthorLastName() { return authorLastName; }

    time_t  getDueDate() { return dueDate; }
    void setDueDate( time_t  dueDate);

    void borrowBook(Member *borrower,  time_t  dueDate);

};
#endif