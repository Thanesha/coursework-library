#include "program.h"
#include <iostream>
#include <string>
#include <limits>
#include <fstream>


using namespace std;
int main(int argc, char *argv[])
{
       const std::string FILENAME = argv[1];
 // check if the file exists and load the book details from file
    if (checkFile(FILENAME))
    {   
        size(FILENAME);
        mainMenu(FILENAME);
        return 0;
    }
    else
    {
        return 1;
    }

    Member member;
    Person person;
    string filename = "member.txt";

    addMember(person);
    saveMemberToFile(member, person, filename);
    displayMemberDetails(member);

    return 0;
}


