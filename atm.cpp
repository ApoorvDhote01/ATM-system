#include <iostream>
#include <iomanip>

using namespace std;

class ATM {
private:
    double balance;

public:
    ATM() : balance(0) {}

    void displayMenu() {
        cout << "ATM Menu:" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Exit" << endl;
    }

    void checkBalance() {
        cout << "Your balance is: $" << fixed << setprecision(2) << balance << endl;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposit successful. New balance is: $" << fixed << setprecision(2) << balance << endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds. Withdrawal failed." << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal successful. New balance is: $" << fixed << setprecision(2) << balance << endl;
        }
    }
};

int main() {
    ATM atm;
    int choice;
    double amount;

    do {
        atm.displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                atm.checkBalance();
                break;
            case 2:
                cout << "Enter amount to deposit: $";
                cin >> amount;
                atm.deposit(amount);
                break;
            case 3:
                cout << "Enter amount to withdraw: $";
                cin >> amount;
                atm.withdraw(amount);
                break;
            case 4:
                cout << "Thank you for using the ATM. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
