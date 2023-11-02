#include "CreditCard.hpp"
#include <iostream>

CreditCard::CreditCard(std::string number, double initialBalance, std::string expiration, std::string cvv) {
    cardNumber = number;
    balance = initialBalance;
    expireDate = expiration;
    this->cvv = cvv;
}

CreditCard::CreditCard(const CreditCard& old_card) {
    cardNumber = old_card.cardNumber;
    balance = old_card.balance;
    expireDate = old_card.expireDate;
    cvv = old_card.cvv;
}

CreditCard::~CreditCard() {
    // std::cout << "Destroyed CreditCard with card number: " << cardNumber << std::endl;
}

std::string CreditCard::getCardNumber() {
    return cardNumber;
}

double CreditCard::getBalance() {
    return balance;
}

std::string CreditCard::getExpireDate() {
    return expireDate;
}

std::string CreditCard::getCVV() {
    return cvv;
}

void CreditCard::setBalance(double newBalance) {
    balance = newBalance;
}

void CreditCard::makePurchase(double amount) {
    if (amount <= getBalance()) {
        setBalance(getBalance() - amount);
        std::cout << "Purchase successful." << std::endl;
        std::cout << "New balance: " << getBalance() << std::endl;
    } else {
        std::cout << "Insufficient balance." << std::endl;
        std::cout << "Current balance: " << getBalance() << std::endl;
    }
}

void CreditCard::transferMoney(CreditCard& targetCard, double amount) {
    if (amount > 0 && amount <= getBalance()) {
        setBalance(getBalance() - amount);
        targetCard.setBalance(targetCard.getBalance() + amount);
        std::cout << "Transfer successful. $" << amount << " transferred to card " << targetCard.getCardNumber() << std::endl;
    } else {
        std::cout << "Transfer failed. Insufficient balance or invalid amount." << std::endl;
    }
}

void CreditCard::deposit(double amount) {
    setBalance(getBalance() + amount);
    std::cout << "Deposit successful." << std::endl;
    std::cout << "New balance: " << getBalance() << std::endl;
}

CreditCard& CreditCard::operator=(const CreditCard& other) {
    if (this == &other) {
        return *this;
    }
    balance = other.balance;
    return *this;
}