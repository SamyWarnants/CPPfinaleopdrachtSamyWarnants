// Calculator.cpp
#include "Calculator.h"
#include <iostream>
#include <sstream>
#include <cmath>

Calculator::Calculator() : memory(0.0), previousInput("") {}

void Calculator::displayMenu() const {
    std::cout << "Calculator Menu:\n";
    std::cout << "1. Add\n";
    std::cout << "2. Subtract\n";
    std::cout << "3. Multiply\n";
    std::cout << "4. Divide\n";
    std::cout << "5. Square Root\n";
    std::cout << "6. Memory Recall\n";
    std::cout << "7. Exit\n";
}

int Calculator::processInput() {
    displayMenu();

    int choice;
    std::cout << "Enter your choice (1-7): ";
    std::cin >> choice;

    if (choice >= 1 && choice <= 4) {
        double operand1, operand2;
        std::cout << "Enter first operand: ";
        std::cin >> operand1;

        std::cout << "Enter second operand: ";
        std::cin >> operand2;

        char operation;
        std::cout << "Enter operation (+, -, *, /): ";
        std::cin >> operation;

        performCalculation(operand1, operand2, operation);
    } else if (choice == 5) {
        double operand;
        std::cout << "Enter operand for square root: ";
        std::cin >> operand;

        double result = sqrt(operand);
        showResult(result);
    } else if (choice == 6) {
        showResult(memory);
    } else if (choice == 7) {
        std::cout << "Exiting the calculator. Goodbye!\n";
    } else {
        std::cout << "Invalid choice. Please try again.\n";
    }

    return choice;  // Return choice
}

void Calculator::performCalculation(double operand1, double operand2, char operation) {
    double result;
    switch (operation) {
    case '+':
        result = operand1 + operand2;
        break;
    case '-':
        result = operand1 - operand2;
        break;
    case '*':
        result = operand1 * operand2;
        break;
    case '/':
        if (operand2 != 0) {
            result = operand1 / operand2;
        } else {
            std::cout << "Error: Division by zero\n";
            return;
        }
        break;
    default:
        std::cout << "Invalid operation. Please try again.\n";
        return;
    }

    memory = result;
    showResult(result);
}

void Calculator::showResult(double result) {
    std::cout << "Result: " << result << "\n";
    previousInput = std::to_string(result);
}
