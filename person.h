#ifndef _PERSON_H_
#define _PERSON_H_

#include <string>
#include "details.h"
class Person 
{
private:
    std::string name;
    std::string address;
    std::string email;

public:
    Person(std::string name, std::string address, std::string email) : name(name), address(address), email(email) {}
    Person(){}
    Person(details *array);
    virtual ~Person();


     //setter
    void setName(std::string name); 
    void setAddress(std::string address);
    void setEmail(std::string email);
    // getter 
    std::string getName() { return name; } 
    std::string getAddress() { return address; }
    std::string getEmail() { return email; }
};
#endif