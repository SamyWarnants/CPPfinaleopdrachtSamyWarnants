// main.cpp
#include "Calculator.h"
int main() {
    Calculator calculator;

    bool exitRequested = false;
    int choice;
    do {
        choice = calculator.processInput();
        if (choice == 7) {
            exitRequested = true;
        }
    } while (!exitRequested);  // Continue looping until the exit flag is set

    return 0;
}
