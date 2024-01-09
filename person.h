#ifndef _PERSON_H_
#define _PERSON_H_

#include <string>
class Person 
{
private:
    std::string name;
    std::string address;
    std::string email;

public:
    Person(std::string name, std::string address, std::string email) : name(name), address(address), email(email) {}
    
     //setter
    void setName(std::string name) { this->name = name; } 
    void setAddress(std::string address) { this->address = address; }
    void setEmail(std::string email) { this->email = email; }
    // getter 
    std::string getName() { return name; } 
    std::string getAddress() { return address; }
    std::string getEmail() { return email; }
    
};
#endif