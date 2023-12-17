// Calculator.h
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>

class Calculator {
private:
    double memory;
    std::string previousInput;

public:
    Calculator();

    void displayMenu() const;
    int processInput();
    void performCalculation(double operand1, double operand2, char operation); // Update this line
    void showResult(double result);
};

#endif // CALCULATOR_H
