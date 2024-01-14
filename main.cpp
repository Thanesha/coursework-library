#include "program.h"
#include <iostream>
#include <string>
#include <limits>
#include <fstream>


using namespace std;
int main() {
    Member member;
    Person person;
    string filename = "member.txt";

    addMember(person);
    saveMemberToFile(member, person, filename);
    displayMemberDetails(member);

    return 0;
}



