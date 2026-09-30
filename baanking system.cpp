#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Transaction {
public:
    string type;
    double amount;
    string details;

    Transaction(string t, double a, string d) {
        type = t;
        amount = a;
        details = d;
    }

    void showTransaction() {
        cout << type << " : Rs. " << fixed << setprecision(2)
             << amount << " - " << details << endl;
    }
};

class Account {
private:
    int accountNumber;
    double balance;
    vector<Transaction> transactions;

public:
    Account(int accNo, double initialBalance) {
        accountNumber = accNo;
        balance = initialBalance;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    double getBalance() {
        return balance;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Invalid amount.\n";
            return;
        }

        balance += amount;

        transactions.push_back(
            Transaction("Deposit", amount, "Money added to account")
        );

        cout << "Amount deposited successfully.\n";
    }

    bool withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid amount.\n";
            return false;
        }

        if (amount > balance) {
            cout << "Insufficient balance.\n";
            return false;
        }

        balance -= amount;

        transactions.push_back(
            Transaction("Withdrawal", amount, "Money withdrawn")
        );

        cout << "Amount withdrawn successfully.\n";
        return true;
    }

    void addTransfer(double amount, string message) {
        transactions.push_back(
            Transaction("Transfer", amount, message)
        );
    }

    void showTransactions() {
        if (transactions.empty()) {
            cout << "No transactions found.\n";
            return;
        }

        cout << "\n--- Transaction History ---\n";

        for (int i = 0; i < transactions.size(); i++) {
            transactions[i].showTransaction();
        }
    }

    void showAccount() {
        cout << "\nAccount Number : " << accountNumber << endl;
        cout << "Balance        : Rs. "
             << fixed << setprecision(2) << balance << endl;
    }
};

class Customer {
private:
    string name;
    string phone;
    Account account;

public:
    Customer(string n, string p, int accNo, double initialBalance)
        : account(accNo, initialBalance) {

        name = n;
        phone = p;
    }

    int getAccountNumber() {
        return account.getAccountNumber();
    }

    Account& getAccount() {
        return account;
    }

    void showCustomerDetails() {
        cout << "\n--- Customer Details ---\n";
        cout << "Name  : " << name << endl;
        cout << "Phone : " << phone << endl;
        account.showAccount();
    }
};

vector<Customer> customers;

int findAccount(int accountNumber) {
    for (int i = 0; i < customers.size(); i++) {
        if (customers[i].getAccountNumber() == accountNumber) {
            return i;
        }
    }

    return -1;
}

void createAccount() {
    string name, phone;
    int accountNumber;
    double initialBalance;

    cout << "\nEnter customer name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter phone number: ";
    cin >> phone;

    cout << "Enter account number: ";
    cin >> accountNumber;

    if (findAccount(accountNumber) != -1) {
        cout << "Account number already exists.\n";
        return;
    }

    cout << "Enter initial deposit: ";
    cin >> initialBalance;

    if (initialBalance < 0) {
        cout << "Invalid initial balance.\n";
        return;
    }

    customers.push_back(
        Customer(name, phone, accountNumber, initialBalance)
    );

    cout << "Account created successfully.\n";
}

void depositMoney() {
    int accountNumber;
    double amount;

    cout << "\nEnter account number: ";
    cin >> accountNumber;

    int index = findAccount(accountNumber);

    if (index == -1) {
        cout << "Account not found.\n";
        return;
    }

    cout << "Enter amount to deposit: ";
    cin >> amount;

    customers[index].getAccount().deposit(amount);
}

void withdrawMoney() {
    int accountNumber;
    double amount;

    cout << "\nEnter account number: ";
    cin >> accountNumber;

    int index = findAccount(accountNumber);

    if (index == -1) {
        cout << "Account not found.\n";
        return;
    }

    cout << "Enter amount to withdraw: ";
    cin >> amount;

    customers[index].getAccount().withdraw(amount);
}

void transferMoney() {
    int senderAccount, receiverAccount;
    double amount;

    cout << "\nEnter your account number: ";
    cin >> senderAccount;

    int senderIndex = findAccount(senderAccount);

    if (senderIndex == -1) {
        cout << "Sender account not found.\n";
        return;
    }

    cout << "Enter receiver account number: ";
    cin >> receiverAccount;

    int receiverIndex = findAccount(receiverAccount);

    if (receiverIndex == -1) {
        cout << "Receiver account not found.\n";
        return;
    }

    if (senderAccount == receiverAccount) {
        cout << "You cannot transfer money to the same account.\n";
        return;
    }

    cout << "Enter amount to transfer: ";
    cin >> amount;

    if (amount <= 0) {
        cout << "Invalid amount.\n";
        return;
    }

    if (amount > customers[senderIndex].getAccount().getBalance()) {
        cout << "Insufficient balance.\n";
        return;
    }

    customers[senderIndex].getAccount().withdraw(amount);

    customers[receiverIndex].getAccount().deposit(amount);

    customers[senderIndex].getAccount().addTransfer(
        amount,
        "Money transferred to account " + to_string(receiverAccount)
    );

    customers[receiverIndex].getAccount().addTransfer(
        amount,
        "Money received from account " + to_string(senderAccount)
    );

    cout << "Money transferred successfully.\n";
}

void showCustomer() {
    int accountNumber;

    cout << "\nEnter account number: ";
    cin >> accountNumber;

    int index = findAccount(accountNumber);

    if (index == -1) {
        cout << "Account not found.\n";
        return;
    }

    customers[index].showCustomerDetails();
}

void showHistory() {
    int accountNumber;

    cout << "\nEnter account number: ";
    cin >> accountNumber;

    int index = findAccount(accountNumber);

    if (index == -1) {
        cout << "Account not found.\n";
        return;
    }

    customers[index].getAccount().showTransactions();
}

int main() {
    int choice;

    cout << "==============================\n";
    cout << "       SIMPLE BANKING SYSTEM\n";
    cout << "==============================\n";

    do {
        cout << "\n\n1. Create Account";
        cout << "\n2. Deposit Money";
        cout << "\n3. Withdraw Money";
        cout << "\n4. Transfer Money";
        cout << "\n5. Customer Details";
        cout << "\n6. Transaction History";
        cout << "\n7. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            createAccount();
            break;

        case 2:
            depositMoney();
            break;

        case 3:
            withdrawMoney();
            break;

        case 4:
            transferMoney();
            break;

        case 5:
            showCustomer();
            break;

        case 6:
            showHistory();
            break;

        case 7:
            cout << "\nThank you for using the banking system!\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 7);

    return 0;
}