#include <string> // Include the necessary header for string

class CreditCard {
private:
    std::string cardNumber;
    double balance;
    std::string expireDate;
    std::string cvv;

public:
    CreditCard(std::string number, double initialBalance, std::string expiration, std::string cvv);
    CreditCard(const CreditCard& old_card);
    ~CreditCard();
    std::string getCardNumber(); 
    double getBalance();
    std::string getExpireDate(); 
    std::string getCVV();
    void setBalance(double newBalance); 
    void makePurchase(double amount);
    void transferMoney(CreditCard& targetCard, double amount);
    void deposit(double amount);
    CreditCard& operator=(const CreditCard& other);
};
