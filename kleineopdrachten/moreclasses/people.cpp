// people.cpp
#include "people.h"
#include <iostream>
#include <algorithm>

namespace MyNamespace {

// Person class implementations

Person::Person() : name(""), age(0) {}

Person::Person(const std::string& name, int age) : name(name), age(age) {}

Person::Person(const Person& other) : name(other.name), age(other.age) {}

Person::~Person() {
    std::cout << "Sorting: " << getName() << std::endl;
}

Person::Person(const std::string& name, int age, bool isStudent) : name(name), age(age) {
    if (isStudent) {
        // Additional initialization for students
    }
}

void Person::displayInfo() const {
    std::cout << "Person: " << name << ", Age: " << age << std::endl;
}

std::string Person::getName() const {
    return name;
}

void Person::setName(const std::string& name) {
    this->name = name;
}

int Person::getAge() const {
    return age;
}

void Person::setAge(int age) {
    this->age = age;
}

void Person::celebrateBirthday(bool surprise) {
    if (surprise) {
        std::cout << getName() << " is surprised on their birthday!" << std::endl;
    } else {
        std::cout << getName() << " has a normal birthday celebration." << std::endl;
    }
}

template <typename T>
void Person::printValue(const T& value) const {
    std::cout << "Value: " << value << std::endl;
}

// Student class implementations

int Student::totalStudents = 0;

Student::Student(const std::string& name, int age, int studentID, const std::string& gender)
    : Person(name, age), studentID(studentID), gender(gender) {
    ++totalStudents;
}

Student::Student(const Student& other) : Person(other), studentID(other.studentID), gender(other.gender) {
    ++totalStudents;
}

Student::~Student() {
    std::cout << "Sorting: " << getName() << std::endl;
    --totalStudents;
}

void Student::displayInfo() const {
    std::cout << "Student: " << getName() << ", Age: " << getAge() << ", Student ID: " << studentID << ", Gender: " << gender << std::endl;
}

void Student::studySubject(const std::string& subject) {
    std::cout << getName() << " is studying " << subject << std::endl;
}

int Student::getTotalStudents() {
    return totalStudents;
}

// Teacher class implementations

int Teacher::totalTeachers = 0;

Teacher::Teacher(const std::string& name, int age, const std::string& subject)
    : Person(name, age), subject(subject) {
    ++totalTeachers;
}

Teacher::Teacher(const Teacher& other) : Person(other), subject(other.subject) {
    ++totalTeachers;
}

Teacher::~Teacher() {
    std::cout << "Sorting: " << getName() << std::endl;
    --totalTeachers;
}

void Teacher::displayInfo() const {
    std::cout << "Teacher: " << getName() << ", Age: " << getAge() << ", Subject: " << subject << std::endl;
}

void Teacher::teachClass() const {
    std::cout << getName() << " is teaching a class." << std::endl;
}

int Teacher::getTotalTeachers() {
    return totalTeachers;
}

// Friend function implementation

void FriendClass::friendFunction(const Person& person) const {
    std::cout << "Friend Function accessed private member of Person: " << person.name << std::endl;
}

} // namespace MyNamespace
