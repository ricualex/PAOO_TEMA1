#include "header.h"

void myFunction() {
    std::cout<< "Hello from myFUnction" <<std::endl;
}

void login() {
    const std::string defaultUsername = "user";
    const std::string defaultPassword = "user";
    std::string username;
    std::string password;
    while (true) {
    std::cout << "Login" << std::endl;
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    if (username == defaultUsername && password == defaultPassword) {
        std::cout << "Login successful!" << std::endl;
        break;
    } else {
        std::cout << "Invalid credentials. Please try again." << std::endl;
    }
    }
}