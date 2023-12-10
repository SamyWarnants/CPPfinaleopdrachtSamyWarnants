// main.cpp
#include "people.h"
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    using namespace MyNamespace;

    // Vector to store people (both students and teachers)
    std::vector<Person*> people;

    // Default constructor
    people.push_back(new Person());
    // Parameterized constructor
    people.push_back(new Person("John Doe", 25));
    // Another parameterized constructor with an additional parameter
    people.push_back(new Person("Alice", 30, true));

    // Copy constructors
    people.push_back(new Student("Copy", 22, 54321, "Male"));
    people.push_back(new Teacher("CopyTeacher", 40, "Math"));

    // Display total students and teachers using static member functions
    std::cout << "Total Students: " << Student::getTotalStudents() << std::endl;
    std::cout << "Total Teachers: " << Teacher::getTotalTeachers() << std::endl;

    // Friend function usage
    FriendClass friendObj;
    friendObj.friendFunction(*people[1]);

    // Dynamic polymorphism
    people.push_back(new Student("Bob Johnson", 22, 56789, "Female"));
    people.push_back(new Teacher("Ms. Smith", 35, "English"));

    // User input for creating a Person object (either Teacher or Student)
    std::string personType;
    std::cout << "Enter 'teacher' or 'student': ";
    std::cin >> personType;

    // User input for creating a person (either Teacher or Student)
    std::string personName;
    int personAge;

    std::cout << "Enter " << personType << " name: ";
    std::cin.ignore(); // Clear the newline character left in the input buffer
    std::getline(std::cin, personName);

    std::cout << "Enter " << personType << " age: ";
    std::cin >> personAge;

    if (personType == "teacher") {
        std::string subject;
        std::cout << "Enter teacher subject: ";
        std::cin >> subject;

        people.push_back(new Teacher(personName, personAge, subject));
    } else if (personType == "student") {
        int studentID;
        std::string studentGender;

        std::cout << "Enter student ID: ";
        std::cin >> studentID;

        std::cin.ignore(); // Clear the newline character left in the input buffer

        std::cout << "Enter student gender: ";
        std::getline(std::cin, studentGender);

        people.push_back(new Student(personName, personAge, studentID, studentGender));
    } else {
        std::cout << "Invalid person type\n";
        return 1; // Indicate failure
    }

    // Sorting options
    std::cout << "Choose sorting option:\n";
    std::cout << "1. Sort by ID (highest to lowest)\n";
    std::cout << "2. Sort alphabetically\n";
    std::cout << "3. Sort by age (low to high)\n";
    std::cout << "4. Separate students and teachers\n";

    int sortingOption;
    std::cin >> sortingOption;

    switch (sortingOption) {
    case 1:
        // Sort by ID (highest to lowest)
        std::sort(people.begin(), people.end(),
                  [](const Person* a, const Person* b) { return a->getAge() > b->getAge(); });
        break;
    case 2:
        // Sort alphabetically
        std::sort(people.begin(), people.end(),
                  [](const Person* a, const Person* b) { return a->getName() < b->getName(); });
        break;
    case 3:
        // Sort by age (low to high)
        std::sort(people.begin(), people.end(),
                  [](const Person* a, const Person* b) { return a->getAge() < b->getAge(); });
        break;
    case 4:
        // Separate students and teachers
        {
            std::vector<Person*> students;
            std::vector<Person*> teachers;
            for (Person* person : people) {
                if (dynamic_cast<Student*>(person)) {
                    students.push_back(person);
                } else if (dynamic_cast<Teacher*>(person)) {
                    teachers.push_back(person);
                }
            }

            std::cout << "Students:\n";
            for (const Person* student : students) {
                student->displayInfo();
            }

            std::cout << "Teachers:\n";
            for (const Person* teacher : teachers) {
                teacher->displayInfo();
            }
        }
        break;
    default:
        std::cout << "Invalid sorting option\n";
    }

    // Clean up allocated memory
    for (Person* person : people) {
        delete person;
    }

    return 0;
}
