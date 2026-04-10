#include<iostream>
using namespace std;

class Account {
protected:
    string owner;
    double balance;
public:
    Account(string o, double b) {
        owner = o;
        balance = b;
    }
    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }
    virtual void withdraw(double amount) {
        if(amount > balance) {
            cout << "Insufficient balance" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        }
    }
    virtual void display() {
        cout << "Owner: " << owner << "\nBalance: " << balance << endl;
    }
};

class SavingsAccount : public Account {
    double interestRate;
public:
    SavingsAccount(string o, double b, double r) : Account(o, b) {
        interestRate = r;
    }
    void addInterest() {
        double interest = balance * interestRate / 100;
        balance += interest;
        cout << "Interest added: " << interest << endl;
    }
    void display() override {
        cout << "Savings Account\n";
        cout << "Owner: " << owner << "\nBalance: " << balance << "\nRate: " << interestRate << "%" << endl;
    }
};

class CurrentAccount : public Account {
    double overdraftLimit;
public:
    CurrentAccount(string o, double b, double limit) : Account(o, b) {
        overdraftLimit = limit;
    }
    void withdraw(double amount) override {
        if(amount > balance + overdraftLimit) {
            cout << "Exceeds overdraft limit" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        }
    }
    void display() override {
        cout << "Current Account\n";
        cout << "Owner: " << owner << "\nBalance: " << balance << "\nOverdraft Limit: " << overdraftLimit << endl;
    }
};

int main() {
    SavingsAccount sa("Akhilesh", 5000, 5);
    sa.deposit(1000);
    sa.addInterest();
    sa.display();

    cout << endl;

    CurrentAccount ca("Rahul", 2000, 500);
    ca.withdraw(2400);
    ca.display();

    return 0;
}