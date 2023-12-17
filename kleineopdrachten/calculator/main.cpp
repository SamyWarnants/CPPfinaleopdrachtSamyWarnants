// main.cpp
#include "Calculator.h"

int main() {
    Calculator calculator;

    int choice;
    do {
        choice = calculator.processInput();
    } while (choice != 7);  // Continue looping until the user chooses to exit

    return 0;
}
