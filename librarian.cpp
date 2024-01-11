    #include "librarian.h"
    #include "person.h"
    #include "book.h"
    #include <sstream>
    
    Librarian:: Librarian(std::string staffID, std::string name, std::string address, std::string email, int salary) : Person(name, address, email), staffID(staffID), salary(salary) {} 
    void addMember() {} 
    void issueBook(int bookID, int memberID) {}
    void returnBook(int bookID, int memberID) {}
    void displayBorrowedBooks(int memberID) {}
    void calcFine(int memberID) {}

    std::string Librarian::getStaffID(){
        return staffID;
    }
    void Librarian::setStaffID(std::string staffID){
        this->staffID = staffID;
    }

    int Librarian::getSalary(){
        return salary;
    }
    void Librarian::setsalary(int salary){
        this->salary=salary;
    }

