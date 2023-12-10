// people.h
#ifndef PEOPLE_H
#define PEOPLE_H

#include <string>
#include <vector>

namespace MyNamespace {

class Person {
private:
    std::string name;
    int age;

public:
    // Default constructor
    Person();

    // Parameterized constructor
    Person(const std::string& name, int age);

    // Copy constructor
    Person(const Person& other);

    // Destructor
    virtual ~Person();

    // Member initialization in constructors
    Person(const std::string& name, int age, bool isStudent);

    // Display person information
    virtual void displayInfo() const;

    // Getters and setters
    std::string getName() const;
    void setName(const std::string& name);
    int getAge() const;
    void setAge(int age);

    // Member function with default value
    void celebrateBirthday(bool surprise = true);

    // Template function
    template <typename T>
    void printValue(const T& value) const;

    // Friend class declaration
    friend class FriendClass;
};

class Student : public Person {
private:
    int studentID;
    std::string gender;

public:
    // Default constructor using constructor forwarding
    using Person::Person;

    // Parameterized constructor
    Student(const std::string& name, int age, int studentID, const std::string& gender);

    // Copy constructor
    Student(const Student& other);

    // Destructor
    ~Student();

    // Member function with dynamic polymorphism
    void displayInfo() const override;

    // Additional member function
    void studySubject(const std::string& subject);

    // Static member variable
    static int totalStudents;

    // Static member function
    static int getTotalStudents();
};

class Teacher : public Person {
private:
    std::string subject;

public:
    // Default constructor using constructor forwarding
    using Person::Person;

    // Parameterized constructor
    Teacher(const std::string& name, int age, const std::string& subject);

    // Copy constructor
    Teacher(const Teacher& other);

    // Destructor
    ~Teacher();

    // Member function with dynamic polymorphism
    void displayInfo() const override;

    // Additional member function
    void teachClass() const;

    // Static member variable
    static int totalTeachers;

    // Static member function
    static int getTotalTeachers();
};

class FriendClass {
public:
    // Friend function
    void friendFunction(const Person& person) const;
};

} // namespace MyNamespace

#endif // PEOPLE_H
