#ifndef _DETAILS_H_
#define _DETAILS_H_
#include <string>

struct details
{
    std::string name;
    std::string email;
    std::string address;
    std::string memberId;
};
struct Books
{
    std::string bookname;
    std::string bookID;
    std::string authorfirstname;
    std::string authorlastname;
    std::string bookType;
};

// Store details of a mmeber from Add member functionality
 struct addMembers
    {
        std::string addname;
        std::string addemail;
        std::string addaddress;
        std::string addmemberID;

    };
#endif