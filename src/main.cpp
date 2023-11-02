#include <iostream>
#include "header.h"
#include "CreditCard.hpp"
std::vector<CreditCard> bank1;
std::vector<CreditCard> backupCards;

int findCard(std::string cardNumberToFind, std::vector<CreditCard>cards) {
    for (int i = 0; i<cards.size(); i++) {
        if (cards[i].getCardNumber() == cardNumberToFind) {
            return i;
            break;
        }
    }
    return -1;
}

void transferMoneyOption() {
    std::string initialCardNumber, targetCardNumber;
    std::cout << "Enter the card number to transfer from: ";
    std::cin >> initialCardNumber;
    int indexInitial = findCard(initialCardNumber, bank1);
    std::cout << "Enter the card number to transfer to: ";
    std::cin >> targetCardNumber;
    int indexTarget = findCard(targetCardNumber, bank1);
    bank1[indexInitial].transferMoney(bank1[indexTarget], 200.0);
}

void makePurchaseOption(double amount) {
    std::string cardNumberToPurchase;
    std::cout << "Enter the card number to use: ";
    std::cin >> cardNumberToPurchase;
    int index = findCard(cardNumberToPurchase, bank1);
    bank1[index].makePurchase(amount);
}

void deleteCardOption() {
    std::string cardNumberToDelete;
    std::cout << "Enter the card number to delete: ";
    std::cin >> cardNumberToDelete;
    int index = findCard(cardNumberToDelete, bank1);
    CreditCard backupCard = CreditCard(bank1[index]);
    bank1.erase(bank1.begin() + index);
    std::cout<<backupCard.getBalance()<<std::endl;
    backupCards.push_back(backupCard);
}

void depositOption(double amount) {
    std::string cardNumberToDeposit;
    std::cout << "Enter the card number to use: ";
    std::cin >> cardNumberToDeposit;
    int index = findCard(cardNumberToDeposit, bank1);
    bank1[index].deposit(amount);
}

void showCurrentCards(int option) {
    if (option == 5) {
        for (int i = 0; i<bank1.size(); i++) {
            std::cout << "Card Number: " << bank1[i].getCardNumber() << ", Balance: $" << bank1[i].getBalance() << std::endl;
        }
    }
    if (option == 6) {
        for (int i = 0; i<backupCards.size(); i++) {
            std::cout << "Card Number: " << backupCards[i].getCardNumber() << ", Balance: $" << backupCards[i].getBalance() << std::endl;
        }
    }
    else std::cout<<"Invalid option"<<std::endl;

}

void testOperator() {
    CreditCard card1("1234-1234", 1000.0, "11/23", "123");
    CreditCard card2("5678-5678", 750.0, "12/23", "456");
    card2 = card1;
    std::cout<<card2.getCardNumber()<<" "<<card2.getBalance()<<std::endl;
}

int main() {
    CreditCard creditCard = CreditCard("0000-0000", 1000.0, "12/25", "123");
    bank1.push_back(CreditCard("0000-0000", 1000.0, "12/25", "123"));
    bank1.push_back(CreditCard("1111-1111", 750.0, "08/24", "456"));
    bank1.push_back(CreditCard("2222-2222", 1500.0, "06/26", "789"));

    login();
    
    int choice;
    while (true) {
        std::cout << "Main Menu" << std::endl;
        std::cout << "1. Make Transfer." << std::endl;
        std::cout << "2. Make Purchase." << std::endl;
        std::cout << "3. Delete Card." << std::endl;
        std::cout << "4. Deposit." << std::endl;
        std::cout << "5. Show current cards." << std::endl;
        std::cout << "6. Show temporary cards." << std::endl;
        std::cout << "7. Test operator." << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        double amount;

        switch (choice) {
            case 1:
                transferMoneyOption();
                break;
            case 2:
                std::cout<<"Insert cost of the product: ";
                std::cin>>amount;
                makePurchaseOption(amount);
                break;
            case 3:
                deleteCardOption();
                break;
            case 4:
                std::cout<<"Insert amount to deposit: ";
                std::cin>>amount;
                depositOption(amount);
                break;
            case 5:
                showCurrentCards(5);
                break;
            case 6:
                showCurrentCards(6);
                break;
            case 7:
                testOperator();
                break;
            case 0:
                std::cout << "Exiting the program." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please select a valid option." << std::endl;
        }
    }
    return 0;
}
