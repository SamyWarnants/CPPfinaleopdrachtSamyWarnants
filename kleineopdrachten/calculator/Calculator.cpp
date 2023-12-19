#include "Calculator.h"
#include <iostream>
#include <cmath>
#include <limits>

Calculator::Calculator() : memory(0.0), previousInput("") {}

void Calculator::displayMenu() const {
    std::cout << "Calculator Menu: Select the calculation you would like to do:\n";
    std::cout << "1. Add\n";
    std::cout << "2. Subtract\n";
    std::cout << "3. Multiply\n";
    std::cout << "4. Divide\n";
    std::cout << "5. Square Root\n";
    std::cout << "6. Memory Recall\n";
    std::cout << "7. Exit\n";
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
            std::cout << "Error: Division by zero is not allowed.\n";
            return;
        }
        break;
    default:
        std::cout << "Invalid operation. Please try again.\n";
        return;
    }

    memory = result;           // Store the result in memory
    showResult(result);
}

void Calculator::showResult(double result) {
    std::cout << "Result: " << result << '\n';
}

int Calculator::processInput() {
    displayMenu();

    int choice;
    std::cout << "Enter your choice (1-7): ";
    std::cin >> choice;

    if (std::cin.fail()) {
        std::cout << "Invalid input. Please enter a numeric value.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return processInput();
    }

    if (choice >= 1 && choice <= 4) {
        double operand1, operand2;
        std::cout << "Enter first operand: ";
        std::cin >> operand1;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a numeric value.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return processInput();
        }

        std::cout << "Enter second operand: ";
        std::cin >> operand2;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a numeric value.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return processInput();
        }

        char operation;
        switch (choice) {
        case 1:
            operation = '+';
            break;
        case 2:
            operation = '-';
            break;
        case 3:
            operation = '*';
            break;
        case 4:
            operation = '/';
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            return choice;
        }

        performCalculation(operand1, operand2, operation);
    } else if (choice == 5) {
        double operand;
        std::cout << "Enter a number for square root: ";
        std::cin >> operand;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a numeric value.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return processInput();
        }

        double result = sqrt(operand);
        memory = result;           // Store the result in memory
        showResult(result);
    } else if (choice == 6) {
        showResult(memory);
    } else if (choice == 7) {
        std::cout << "Exiting the calculator. Goodbye!\n";
    } else {
        std::cout << "Invalid choice. Please try again.\n";
    }

    return choice;
}
