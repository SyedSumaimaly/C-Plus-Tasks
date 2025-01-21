#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

struct Transaction {
    string type;
    double amount;
    string date;
    double remainingBalance;
};

struct Customer {
    int accountNumber;
    int pin;
    string name;
    double balance;
    string accountType;
    vector<Transaction> transactionHistory;
};

vector<Customer> customers;

string getCurrentDateTime() {
    time_t now = time(0);
    char* dt = ctime(&now);
    return string(dt);
}

void createAccount() {
    Customer newCustomer;
    cout << "Enter Account Number: ";
    cin >> newCustomer.accountNumber;
    cout << "Enter PIN: ";
    cin >> newCustomer.pin;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, newCustomer.name);
    cout << "Enter Account Type (Checking/Savings): ";
    cin >> newCustomer.accountType;
    cout << "Enter Initial Deposit: ";
    cin >> newCustomer.balance;

    customers.push_back(newCustomer);
    cout << "Account created successfully!\n";
}

int validatePIN(int accountNumber, int pin) {
    for (size_t i = 0; i < customers.size(); i++) {
        if (customers[i].accountNumber == accountNumber && customers[i].pin == pin) {
            return i;
        }
    }
    return -1;
}

void checkBalance(int index) {
    cout << "Your current balance is: " << customers[index].balance << " USD\n";
}

void depositMoney(int index) {
    double amount;
    cout << "Enter amount to deposit: ";
    cin >> amount;

    customers[index].balance += amount;
    customers[index].transactionHistory.push_back({"Deposit", amount, getCurrentDateTime(), customers[index].balance});
    cout << "Amount deposited successfully!\n";
}

void withdrawMoney(int index) {
    double amount;
    cout << "Enter amount to withdraw: ";
    cin >> amount;

    if (amount > customers[index].balance) {
        cout << "Insufficient funds!\n";
    } else {
        customers[index].balance -= amount;
        customers[index].transactionHistory.push_back({"Withdrawal", amount, getCurrentDateTime(), customers[index].balance});
        cout << "Amount withdrawn successfully!\n";
    }
}

void transferFunds(int index) {
    int targetAccount;
    double amount;
    cout << "Enter target account number: ";
    cin >> targetAccount;
    cout << "Enter amount to transfer: ";
    cin >> amount;

    if (amount > customers[index].balance) {
        cout << "Insufficient funds!\n";
        return;
    }

    for (size_t i = 0; i < customers.size(); i++) {
        if (customers[i].accountNumber == targetAccount) {
            customers[index].balance -= amount;
            customers[i].balance += amount;

            customers[index].transactionHistory.push_back({"Transfer Out", amount, getCurrentDateTime(), customers[index].balance});
            customers[i].transactionHistory.push_back({"Transfer In", amount, getCurrentDateTime(), customers[i].balance});

            cout << "Funds transferred successfully!\n";
            return;
        }
    }
    cout << "Target account not found!\n";
}

void viewTransactionHistory(int index) {
    cout << "Transaction History:\n";
    for (const auto& t : customers[index].transactionHistory) {
        cout << t.type << ": " << t.amount << " USD on " << t.date << " | Balance: " << t.remainingBalance << " USD\n";
    }
}

void menu() {
    int choice;
    while (true) {
        cout << "\n1. Create Account\n2. Login (Existing Account)\n3. Exit\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            createAccount();
        } else if (choice == 2) {
            int accountNumber, pin, index, attempts = 0;
            cout << "Enter Account Number: ";
            cin >> accountNumber;

            while (attempts < 3) {
                cout << "Enter PIN: ";
                cin >> pin;
                index = validatePIN(accountNumber, pin);

                if (index != -1) {
                    cout << "Login successful!\n";
                    int subChoice;
                    do {
                        cout << "\n1. Check Balance\n2. Deposit Money\n3. Withdraw Money\n4. Transfer Funds\n5. View Transaction History\n6. Logout\nEnter your choice: ";
                        cin >> subChoice;

                        switch (subChoice) {
                            case 1: checkBalance(index); break;
                            case 2: depositMoney(index); break;
                            case 3: withdrawMoney(index); break;
                            case 4: transferFunds(index); break;
                            case 5: viewTransactionHistory(index); break;
                            case 6: cout << "Logging out...\n"; break;
                            default: cout << "Invalid choice!\n";
                        }
                    } while (subChoice != 6);
                    break;
                } else {
                    attempts++;
                    cout << "Invalid PIN. Attempts left: " << 3 - attempts << "\n";
                }
            }

            if (attempts == 3) {
                cout << "Account locked due to multiple incorrect PIN attempts.\n";
            }
        } else if (choice == 3) {
            cout << "Exiting the system. Goodbye!\n";
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }
}

int main() {
    menu();
    return 0;
}