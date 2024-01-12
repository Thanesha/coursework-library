#include "person.h"
#include "member.h"
#include "book.h"
#include <sstream>
#include <vector>

Member::Member(std::string memberID, std::string name, std::string address, 
    std::string email) : Person(name, address, email), memberID(memberID) {}
Member::Member(){}
Member::Member(details *array) : Person(array)
{
    //set the detail about member
    setName(array->name);
    setAddress(array->address);
    setEmail(array->email);
    memberID = array->memberId;
}
void Member::setBooksBorrowed(Book book)
 { booksLoaned.push_back(book); }

std::string Member::getMemberID() { return memberID; }
std::vector<Book> Member::getBooksBorrowed() { return booksLoaned; }

