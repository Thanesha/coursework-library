#ifndef _PROGRAM_H_
#define _PROGRAM_H_

#include "details.h"
#include "book.h"
#include "librarian.h"
#include "person.h"
#include "member.h"

#include <iostream>
#include <string>

// return the number of books to be loaded from the file

bool checkFile(const std::string &FILENAME);

// return the number of books to be loaded from the file

int number(const std::string &FILENAME);

//the size of dyanmic array to be created and load the vehicles from files
void size(const std::string &FILENAME);
//load file and assign to array
void loadFile(const std::string &FILENAME);
//display the main menu
void mainMenu(const std::string &FILENAME);
//clear screen
void header(std::string header);
//y/n choice
bool choices(std::string &choice);
//add member
void addMember();
//issue a book to a member..choosen by booktypeid
void issueBook();
//return a book
void returnBook(int bookID, int memberID);
void displayBorrowedBooks(int memberID);
void calcFine(int memberID);
//check datatype
void checkDetails(addMembers &addMembersObject);
//check with existing member
bool checkmember(addMembers &addMembersObject);
//display member added
void display(addMembers &addmembersObject, std::string name);

//increase size of array
bool appendArray(addMembers &addmembersObject);
//new member asssign with array positions
void positions(details *&Members, addMembers &addmembersObject);
//check for bookid
bool checkBookId(std::string selectedBookid, std::string &bookCategory, int &bookIndex);
//list all book types
void listAll();
// vector of person class
void assignpersonArrayToVector();

void table(char intersectionBorder, char topBottomBorder, int colWidth);


void drawPressAnyKey();
//quit option
void quit(const std::string &FILENAME);

void saveData(const std::string &FILENAME);

#endif