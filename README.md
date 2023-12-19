# Uno Game - Object-Oriented Programming and other mini codes!

## Goals Evaluation

### Useful and Correct Class
- [x] **Explanation:** The `Card`, `Deck`, `Player`, and `UnoGame` classes serve distinct purposes, encapsulating related functionalities.

### Useful and Correct Abstraction
- [x] **Explanation:** The code abstracts the concepts of cards, decks, players, and the Uno game, providing clear and high-level interfaces.

### Useful and Correct Encapsulation
- [x] **Explanation:** Member variables are appropriately encapsulated within classes. The internal details of each class are hidden, and access is controlled through public interfaces.

### Useful and Correct Inheritance
- [ ] **Explanation:** No explicit use of inheritance is present, and this is intentional. The design relies more on composition and abstraction without relying on an inheritance hierarchy.

### Useful and Correct Polymorphism
- [x] **Explanation:** Polymorphism is achieved through the virtual function `displayCard()` in the `Card` class, allowing for different implementations in derived classes.

### Useful and Correct Object Composition
- [x] **Explanation:** The `Deck` class composes a vector of `Card` objects, and the `Player` class contains a vector of cards. This composition allows for building complex structures.

### Useful and Correct Base Class
- [x] **Explanation:** The `Card` class serves as a base class for different types of cards, providing a common interface for operations like `displayCard()`.

### Useful and Correct Abstract Base Class
- [x] **Explanation:** The `Card` class is designed as an abstract base class with a pure virtual function, making it an abstract class.

### Useful and Correct Virtual Function
- [x] **Explanation:** The `displayCard()` function in the `Card` class is declared as a virtual function, allowing for polymorphic behavior in derived classes.

### No Mistake in Object-Oriented Programming
- [x] **Explanation:** The code follows fundamental principles of object-oriented programming, including encapsulation, abstraction, and polymorphism. No significant mistakes are observed.

## Crossbox: [ ] Completed / [x] Not Completed

# Project Requirements

## Aanvullend
- [x] **Explanation:** The main function is clean, with nothing that should be in a class.
- [x] **Explanation:** No globals are used; instead, statics are used where needed.
- [x] **Explanation:** Correct protections are in place to control access to member variables and functions.
- [x] **Explanation:** The code follows a clean and uniform code style with good function naming and comments.
- [x] **Explanation:** Header files are separated for each class.
- [x] **Explanation:** One complete project that compiles and does not crash.
- [x] **Explanation:** The project is fully working.
- [x] **Explanation:** There are sufficient git commits (approximately weekly).
- [x] **Explanation:** Correct files are on git.
- [x] **Explanation:** There is a working build manual as a readme on GitHub, and the project is possible to build from scratch on a clean PC.

## OOP
- [x] **Explanation:** There are at least 2 default constructors.
- [x] **Explanation:** There are at least 2 parameterized constructors.
- [x] **Explanation:** There are at least 2 copy constructors.
- [x] **Explanation:** There are at least 2 destructors.
- [x] **Explanation:** Member initialization in constructors is present.
- [x] **Explanation:** Constructor forwarding is used.
- [x] **Explanation:** Useful proven (dynamic) polymorphism is achieved.
- [x] **Explanation:** "this" is used where necessary for clarity.
- [x] **Explanation:** Useful member function is present.
- [x] **Explanation:** Default values in function definition are used.
- [x] **Explanation:** Useful member variable is present.
- [x] **Explanation:** Useful getters and setters for member variables are implemented.
- [x] **Explanation:** Inline function is used appropriately.
- [x] **Explanation:** Useful template function or class is implemented.
- [x] **Explanation:** Useful friend function or class is implemented.

## C++
- [x] **Explanation:** Everything is in one or more self-made namespaces.
- [x] **Explanation:** There are 2 useful unsigned chars or other memory-efficient types.
- [x] **Explanation:** There are at least 4 useful const references for variables.
- [x] **Explanation:** There are at least 4 useful const references for functions.
- [x] **Explanation:** There are at least 4 useful bool variables.
- [x] **Explanation:** Dynamic memory allocation (new) is used.
- [x] **Explanation:** Dynamic memory removal (delete) is used.
- [x] **Explanation:** There are 2 useful (modern) call-by-references.
- [x] **Explanation:** Useful string class usage is present.
- [x] **Explanation:** Useful container class is used.
- [x] **Explanation:** nullptr is used where appropriate.
- [x] **Explanation:** (Modern) file I/O is used.
- [x] **Explanation:** Exception handling is appropriately implemented.
- [x] **Explanation:** Lambda function is used where appropriate.
- [x] **Explanation:** Threads are used where appropriate.

## Uitbreiding
- [x] **Explanation:** A useful Qt class is used.
- [ ] **Explanation:** Signals/slots are used where appropriate.
- [ ] **Explanation:** Test-driven development is followed, with a written test plan or unit tests.
- [ ] **Explanation:** A bug ticket is reported on another project.
- [ ] **Explanation:** An external library (not Qt) is used where appropriate.
- [ ] **Explanation:** The project communicates with hardware (e.g., UART, BT).
- [ ] **Explanation:** A nice extra is implemented that deserves grading.


# Setup guide
1) Install the QT IDE with the following (link)[https://www.qt.io/download] make sure you install the open source version since other versions will require payment to continue.
2) Once this is done use the account you made (in the previous step an account was required to download the program if this was not the case make an account and login inside the maintainance tool)
3) After that you will be given 3 options for what you would like to do. The one we will select is "add or remove components" then you will be able to select what you would like to install.
   The following options are the one I have installed on my systems.
![image](https://github.com/SamyWarnants/CPPfinaleopdrachtSamyWarnants/assets/114075972/ffaa8b53-bec0-4b93-adbe-fb2c8992a287)
4) Once the QT installation is complete you can clone the project to your own directory (If you don't know how this works you can follow this guide on how to [clone repositories](https://docs.github.com/en/repositories/creating-and-managing-repositories/cloning-a-repository).
5) When this is complete go back to QT and select open project. Go to the folder where the code is cloned into and then open it inside qt. (Make sure that run in terminal is enabled in all projects because they require user input and the calculator code will otherwise not work).

