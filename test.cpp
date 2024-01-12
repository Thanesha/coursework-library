#define CATCH_CONFIG_MAIN

#include <iostream>
#include "catch.hpp"
#include "person.h"
#include "member.h"
#include "book.h"
#include "librarian.h"
#include "details.h"
#include "program.h"

TEST_CASE("Check file existance", "[checkFile]")
{
    SECTION("Correct File used")
    {
        std::string fileName = "library_books.csv";
        bool result = checkFile(fileName);
        REQUIRE(result == true);
    }
}

TEST_CASE("Determine number of Books in file", "[determineSize]")
{
    std::string fileName = "library_books.csv";
    int bookSize = number(fileName);

    SECTION("Correct number of books")
    {
        REQUIRE(bookSize == 1000);
    }
    SECTION("Incorrect number of Books")
    {
        REQUIRE(bookSize != 999);
    }
}
TEST_CASE("Test person", "[person()]")
{
    Person person;
    person.setName("mike");
    person.setAddress("London");
    person.setEmail("mike12@gmail.com");

    REQUIRE(person.getName() == "mike");
    REQUIRE(person.getAddress() == "london");
    REQUIRE(person.getEmail() == "mike12@gmail.com");
}
TEST_CASE("Test book", "[book()]")
{
    Book book;

    REQUIRE(book.getAuthorFirstName() == "Jack");
    REQUIRE(book.getAuthorLastName() == "london");
    REQUIRE(book.getBookID() == 1);
    REQUIRE(book.getBookName() == "A Daughter of the Snows");

}
TEST_CASE("Test lib", "[lib()]")
{
    Librarian lib;
    lib.setsalary(10000);
    lib.setStaffID("S0001");

    REQUIRE(lib.getSalary() == 10000);
    REQUIRE(lib.getStaffID() == "S0001");

}
