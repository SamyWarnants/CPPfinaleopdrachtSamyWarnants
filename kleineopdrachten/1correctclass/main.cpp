// main.cpp
#include "people.h"
#include <iostream>

int main() {
    Student student("Alice Smith", 20, 12345);

    // Accessing attributes through public methods (abstraction)
    std::cout << "Student Name: " << student.getName() << ", Age: " << student.getAge() << ", Student ID: " << student.getStudentID() << std::endl;

    return 0;
}
