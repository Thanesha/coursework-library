#ifndef _MEMBER_H_
#define _MEMBER_H_
#include "person.h"
#include "details.h"
#include "book.h"
#include <vector>

class Member : public Person
{
private:
    std::string memberID;
    std::vector<Book> booksLoaned;

public:
    Member(std::string memberID, std::string name, std::string address, 
    std::string email) : Person(name, address, email), memberID(memberID) {}
    Member(){}
    Member(details *array);
    

    std::string getMemberID() { return memberID; }
    

    std::vector<Book> getBooksBorrowed() { return booksLoaned; }
    void setBooksBorrowed(Book book);


};
#endif

