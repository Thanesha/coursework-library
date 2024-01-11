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

// Store details of a mmeber from Add member functionality
 struct addMembers
    {
        std::string addname;
        std::string addemail;
        std::string addaddress;
        std::string addmemberID;

    };
#endif