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
        Librarian(){}
        std::string getStaffID();
        void setStaffID(std::string staffID);

        int getSalary();
        void setsalary(int salary);
};

#endif
