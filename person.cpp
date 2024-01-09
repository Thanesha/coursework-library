#include "person.h"
#include <string>

//constructor 
Person::Person(std::string name, std::string address, std::string email) : name(name), address(address), email(email) {}

Person::~Person(){} // deconstructor

//setter functions
    void Person::setName(std::string name)
    {   this->name = name;

    }

    void Person::setAddress(std::string address)
    { this->address = address; 
    
    }
    void Person::setEmail(std::string email) 
    { this->email = email; 
    
    }
//getter function
    std::string Person::getName() 
    { return name;
    
    } 
    std::string Person::getAddress() 
    { return address; 
    
    }
    std::string Person::getEmail() 
    { return email; 
    
    }
