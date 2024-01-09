#include "library.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>
#include <map> 
using namespace std;

void addMember(vector<Member> &arr)
 {
    Member Member;
    ofstream file("Member.txt");
    cout << "Enter member ID: ";
    int memberID;
    cin >> memberID;
    if (cin.fail()) {
        cout << "Error: Invalid input." << endl;
        return;
    }

    cout << "Enter member name: ";
    string name;
    cin >> name;

    members.push_back(Member{memberID, name, vector<Book>()});
    cout << "Member added successfully." << endl;
}