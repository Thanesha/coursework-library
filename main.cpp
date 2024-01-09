#include "library.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

void clearScreen()
{
    cout << "\033[2J\033[1;1H"; // ANSI escape sequence to clear terminal screen
}