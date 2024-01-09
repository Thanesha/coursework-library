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
    
    ofstream file("Member.txt");
    cout << "Enter member ID: ";
    int memberID;
    cin >> memberID;
    if (cin.fail()) {
        cout << "Error: Invalid input." << endl;
        return;
    }

    cout << "Enter member name: ";
    std::string name;
    cin >> name;

    cout << "Enter member address: ";
    std::string address;
    cin >> address;

    cout << "Enter member name: ";
    std::string name;
    cin >> name;

    arr.emplace_back(memberID, name);
    cout << "Member added successfully." << endl;
}