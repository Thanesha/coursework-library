#include "program.h"
#include <chrono>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <limits>
#include <ctime>
#include "../../../../../../msys64/ucrt64/include/c++/13.1.0/bits/algorithmfwd.h"
#include "book.h"
using namespace std;

int currentSize = 0;
int maxSize = 0;

details *memberDetails;


std::vector<Member *> member;
bool checkFile(const std::string &FILENAME)
{
    std::ifstream myFile(FILENAME);
    if (myFile.fail())
    {
        std::cout << "Error:  file not found" << std::endl;
        return 0;
    }
    else
    {
        myFile.close();

        return 1;
    }

}
void size(const std::string &FILENAME)
{
    number(FILENAME);
    memberDetails = new details[currentSize];
    loadFile(FILENAME);
}

void mainMenu(const std::string &FILENAME)
{
    std::string option;

    do
    {
        std::cout << "------- MAIN MENU --------" << std::endl;
        std::cout << "1. Add Member" << std::endl;
        std::cout << "2. Issue book" << std::endl;
        std::cout << "3. Return book" << std::endl;
        std::cout << "4. Display all books borrowed" << std::endl;
        std::cout << "5. Calculate a fine" << std::endl;
        std::cout << "6. Quit" << std::endl;
        std::cout << std::endl
                  << "Enter your choice: ";
        std::cin >> option;

        // Add member option
        if (option == "1")
        {
            header("Add Member");
            addMember();
        }
        // Issue a book option
        else if (option == "2")
        {
            header("issue a book");
            issueBook();
        }
        // Return a book option
        else if (option == "3")
        {
            header("Return a book");
            returnBook;
        }
        // Display books borrowed option
        else if (option == "4")
        {
            header("Display books borrowed");
            displayBorrowedBooks;
        }
        // calculate a fine option

        else if (option == "5")
        {
            header("fine calculated");
            calcFine;
        }
        // Quit option
        else if (option == "6")
        {
            quit(FILENAME);
        }
        else if (option != "6")
        {
            std::cout << std::endl
                      << "Invalid choice. Please enter 1, 2, 3, 4, 5 or 6" << std::endl
                      << std::endl;
        };

    } while (option != "6");
};
// Clear the screen
void header(std::string header)
{
    std::cout << "\x1B[2J\x1B[H";
    std::cout << "-------- " << header << " --------" << std::endl;
};

bool choice(std::string &choice)
{
    if (choice != "n" && choice != "y")
    {
        std::cout << "Wrong input. Enter y (YES) or n (NO)." << std::endl
                  << std::endl;
        return true;
    }
    else
    {
        return false;
    }
}
void addMember(int memberID, const std::string& name, const std::string& address, const std::string& email) {
    std::ofstream memberFile;
    memberFile.open("member.txt", std::ios_base::app);

    if (memberFile.is_open()) {
        memberFile << memberID << " " << name << " " << address << " "<< email << std::endl;
        memberFile.close();

        std::cout << "Member ID: " << memberID << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Address: " << address << std::endl;
        std::cout << "email: " << email << std::endl;
    } else {
        std::cout << "Unable to open the file." << std::endl;
    }
}

void issueBook(Member *member, Book *book) {
        std::time_t currentTime;
        std::time(&currentTime);

        book->borrowBook(member, currentTime + (3 * 24 * 60 * 60));

         // Store issued book in member file
        std::ofstream memberFile;
        memberFile.open("member.txt", std::ios::app);
        memberFile << member->getMemberID() << " " << book->getBookID() << std::endl;
        memberFile.close();
}
void returnBook(int memberID, int bookID) {
    // Retrieve the list of issued books for the member
    std::vector<std::pair<int, int>> issuedBooks;
    std::ifstream memberFile;
    memberFile.open("member.txt");

    while (memberFile >> issuedBooks.back().first >> issuedBooks.back().second) {
        issuedBooks.push_back(std::make_pair(0, 0));
    }

    memberFile.close();

    // Find the book with the given book ID and member ID in the issued book list
    auto bookIterator = std::find_if(issuedBooks.begin(), issuedBooks.end(), [=](const std::pair<int, int>& book) {
        return book.first == memberID && book.second == bookID;
    });

    // If the book is found, remove it from the issued book list
    if (bookIterator != issuedBooks.end()) {
        issuedBooks.erase(bookIterator);
    }

    // Overwrite the member file with the updated issued book list
    std::ofstream newMemberFile;
    newMemberFile.open("member.txt");

    for (const auto& book : issuedBooks) {
        newMemberFile << book.first << " " << book.second << std::endl;
    }

    newMemberFile.close();
}

void displayBorrowedBooks(int memberID) {
    // Retrieve the list of issued books for the member
    std::vector<std::pair<int, int>> issuedBooks;
    std::ifstream memberFile;
    memberFile.open("member.txt");

    while (memberFile >> issuedBooks.back().first >> issuedBooks.back().second) {
        issuedBooks.push_back(std::make_pair(0, 0));
    }

    memberFile.close();

    // Display the books borrowed by the member
    std::cout << "Books borrowed by member with ID " << memberID << ":" << std::endl;
    for (const auto& book : issuedBooks) {
        if (book.first == memberID) {
            std::cout << "Book ID: " << book.second << std::endl;
        }
    }
}
// Function to calculate fine for a single book
 int calculateFine(const std::tm& dueDate, const std::string& today) {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);
    std::tm input_date = {};
    std::istringstream(buf) >> std::get_time(&input_date, "%Y-%m-%d");
    time_t timeNow = std::mktime(&input_date);
    long int timeDue = std::mktime(&dueDate) / 86400;
    long int timeNowLong = timeNow / 86400;
    int overdueDays = timeNowLong - timeDue;
    if (overdueDays > 0) {
        return overdueDays;
    }
    return 0;
}

// Function to convert date string to time_t
std::time_t date2time(const std::tm& dueDate) {
    return std::mktime(&dueDate);
}
void calcFine(int memberID) {
    // Retrieve the list of issued books for the member
    std::vector<std::pair<int, int>> issuedBooks;
    std::ifstream memberFile("member.txt");
    if (!memberFile.is_open()) {
        std::cerr << "Error: Unable to open member file" << std::endl;
        return;
    }

    while (memberFile >> issuedBooks.back().first >> issuedBooks.back().second) {
        issuedBooks.push_back(std::make_pair(0, 0));
    }

    memberFile.close();

    // Retrieve the book information
    std::vector<std::pair<int, std::pair<std::string, std::string>>> bookInfo;
    std::ifstream bookFile("library_books.csv");
    if (!bookFile.is_open()) {
        std::cerr << "Error: Unable to open book file" << std::endl;
        return;
    }

    while (bookFile >> bookInfo.back().first >> bookInfo.back().second.first >> bookInfo.back().second.second) {
        bookInfo.push_back(std::make_pair(0, std::make_pair(std::string(), std::string())));
    }

    bookFile.close();

    std::time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);
    std::string today(buf);
    int totalFine = 0;
    for (const auto& book : issuedBooks) {
        if (book.first == memberID) {
            int bookIndex = -1;
            for (size_t i = 0; i < bookInfo.size(); ++i) {
                if (bookInfo[i].first == book.second) {
                    bookIndex = i;
                    break;
                }
            }

            if (bookIndex != -1) {
                std::tm dueDate = {};
                std::istringstream(bookInfo[bookIndex].second.second) >> std::get_time(&dueDate, "%Y-%m-%d");
                int fine = calculateFine(dueDate, today);
                totalFine += fine;
                if (fine > 0) {
                    std::cout << bookInfo[bookIndex].second.first << " - " << bookInfo[bookIndex].second.second << " - £" << fine << std::endl;
                }
            }
        }
    }

    if (totalFine > 0) {
        std::cout << "Total Fine: £" << totalFine << std::endl;
    } else {
        std::cout << "No overdue books." << std::endl;
    }
}