#ifndef _LIBRARIAN_H_
#define _LIBRARIAN_H_

#include "person.h"
#include "member.h"
#include "book.h"
class Librarian : public Person
{
    private:
        std::string staffID;
        int salary;
        std::vector<Member> members;
    public:
        Librarian(std::string staffID, std::string name, std::string address,
         std::string email, int salary) : Person(name, address, email), staffID(staffID), salary(salary) {}
        Librarian(){} // default constructor

       // getter for staff ID
       std::string getStaffID(){\
           return staffID;\
       }\
       // getter for staff ID
        std::string getStaffID();
       // setter for staff ID
        void setStaffID(std::string staffID);
        // getter for salary
        int getSalary();
        // setter for salary
        void setsalary(int salary);
};

#endif
