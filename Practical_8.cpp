
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class BankAccount
{
private:
    string accountHolder;
    int accountNumber;
    double balance;

public:
    BankAccount(string name, int number, double amount)
    {
        accountHolder = name;
        accountNumber = number;
        balance = amount;
    }

    void deposit(double amount)
    {
        try
        {
            if (amount <= 0)
            {
                throw invalid_argument(
                    "Deposit amount must be greater than zero.");
            }

            balance = balance + amount;
            cout << "Deposit successful!" << endl;
            cout << "Deposited Amount: Rs. " << amount << endl;
            cout << "Updated Balance: Rs. " << balance << endl;
        }
        catch (const exception &e)
        {
            cout << "Exception: " << e.what() << endl;
        }
    }

    void withdraw(double amount)
    {
        try
        {
            if (amount <= 0)
            {
                throw invalid_argument(
                    "Withdrawal amount must be greater than zero.");
            }

            if (amount > balance)
            {
                throw runtime_error(
                    "Insufficient balance for withdrawal.");
            }

            balance = balance - amount;
            cout << "Withdrawal successful!" << endl;
            cout << "Withdrawn Amount: Rs. " << amount << endl;
            cout << "Remaining Balance: Rs. " << balance << endl;
        }
        catch (const exception &e)
        {
            cout << "Exception: " << e.what() << endl;
        }
    }

    void displayBalance()
    {
        cout << "\nAccount Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: Rs. " << balance << endl;
    }
};

int main()
{
    int choice;
    double amount;

    BankAccount account("Demo User", 1001, 5000);

    do
    {
        cout << "\n================================";
        cout << "\n BANK ACCOUNT MANAGEMENT SYSTEM";
        cout << "\n================================";
        cout << "\n1. Deposit Money";
        cout << "\n2. Withdraw Money";
        cout << "\n3. Check Balance";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter deposit amount: Rs. ";
                cin >> amount;
                account.deposit(amount);
                break;

            case 2:
                cout << "Enter withdrawal amount: Rs. ";
                cin >> amount;
                account.withdraw(amount);
                break;

            case 3:
                account.displayBalance();
                break;

            case 4:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}

