// people.h
#ifndef PEOPLE_H
#define PEOPLE_H

#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    Person(std::string name, int age);
    std::string getName() const;
    int getAge() const;
    void setName(std::string name);
    void setAge(int age);
};

class Student : public Person {
private:
    int studentID;

public:
    Student(std::string name, int age, int studentID);
    int getStudentID() const;
    void setStudentID(int studentID);
};

// Implementations

Person::Person(std::string name, int age) : name(name), age(age) {}

std::string Person::getName() const {
    return name;
}

int Person::getAge() const {
    return age;
}

void Person::setName(std::string name) {
    this->name = name;
}

void Person::setAge(int age) {
    this->age = age;
}

Student::Student(std::string name, int age, int studentID) : Person(name, age), studentID(studentID) {}

int Student::getStudentID() const {
    return studentID;
}

void Student::setStudentID(int studentID) {
    this->studentID = studentID;
}

#endif // PEOPLE_H
