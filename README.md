# Uno Game - Object-Oriented Programming

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

## Crossbox: [ ] Completed / [ ] Not Completed


# Setup guide
1) Install the QT IDE with the following (link)[https://www.qt.io/download] make sure you install the open source version since other versions will require payment to continue.
2) Once this is done use the account you made (in the previous step an account was required to download the program if this was not the case make an account and login inside the maintainance tool)
3) After that you will be given 3 options for what you would like to do. The one we will select is "add or remove components" then you will be able to select what you would like to install.
   The following options are the one I have installed on my systems.
![image](https://github.com/SamyWarnants/CPPfinaleopdrachtSamyWarnants/assets/114075972/ffaa8b53-bec0-4b93-adbe-fb2c8992a287)
4) Once the QT installation is complete you can clone the project to your own directory.
5) When this is complete go back to QT and select open project. Go to the folder where the code is cloned into and then open it inside qt. (Make sure that run in terminal is enabled in all projects because they require user input).

