#include "book.h"
#include <string>

Book::Book(int bookID, std::string bookName, std::string authorFirstName, std::string authorLastName) : bookID(bookID), bookName(bookName), authorFirstName(authorFirstName), 
     authorLastName(authorLastName) {}
void Book::borrowBook(Member *borrower,  std::time_t  dueDate)
{    this->borrower = borrower;
     this->dueDate = dueDate;
}
     void Book::setDueDate(std::time_t  dueDate)
      { this->dueDate = dueDate; }

       int Book::getBookID() { return bookID; }
    std::string Book::getBookName() { return bookName; }

    std::string Book::getAuthorFirstName() { return authorFirstName; }
    std::string Book::getAuthorLastName() { return authorLastName; }

    std::time_t  Book::getDueDate() { return dueDate; }