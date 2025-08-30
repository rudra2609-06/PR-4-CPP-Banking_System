#include <iostream>
using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(int accountNumber, string accountHolderName, double balance)
    {
        this->accountNumber = accountNumber;
        this->accountHolderName = accountHolderName;
        this->balance = balance;
    }

    virtual void deposit(double amount)
    {
        cout << "Amount " << amount << " successfully deposited" << endl;
        balance += amount;
    }

    virtual void withdraw(double amount)
    {
        if (balance >= amount)
        {
            cout << "Withdrawal successful" << endl;
            balance -= amount;
        }
        else
        {
            cout << "Insufficient Balance" << endl;
        }
    }

    double getBalance(void)
    {
        return balance;
    }

    virtual void displayAccountInfo()
    {
        cout << "------------ Account Details ------------" << endl;
        cout << "Account Number: " << this->accountNumber << endl;
        cout << "Account Holder Name: " << this->accountHolderName << endl;
        cout << "Account Balance: " << this->balance << endl;
    }

    int getAccountNumber(void)
    {
        return accountNumber;
    }

    virtual float calculateInterest() = 0;
};

class SavingsAccount : public BankAccount
{
private:
    float interestRate;

public:
    SavingsAccount(int accountNumber, string accountHolderName, double balance, float interestRate)
        : BankAccount(accountNumber, accountHolderName, balance)
    {
        this->interestRate = interestRate;
    }

    float calculateInterest() override
    {
        return (getBalance() * interestRate) / 100.0;
    }

    void displayAccountInfo()
    {
        BankAccount::displayAccountInfo();
        cout << "Interest Rate: " << this->interestRate << "%" << endl;
        cout << "Interest Earned: " << calculateInterest() << endl;
    }
};

class CheckingAccount : public BankAccount
{
private:
    double overdraftLimit;

public:
    CheckingAccount(int accountNumber, string accountHolderName, double balance, double overdraftLimit)
        : BankAccount(accountNumber, accountHolderName, balance)
    {
        this->overdraftLimit = overdraftLimit;
    }

    void checksOverdraft(double amount)
    {
        cout << "Amount you want to withdraw: " << amount << endl;
        if (getBalance() - amount >= -overdraftLimit)
        {
            cout << "Withdrawal Allowed" << endl;
            BankAccount::withdraw(amount);
        }
        else
        {
            cout << "Withdrawal Not Allowed (exceeds overdraft limit)" << endl;
        }
    }

    void deposit(double amount)
    {
        BankAccount::deposit(amount);
    }

    void withdraw(double amount)
    {
        if (getBalance() + overdraftLimit >= amount)
        {
            cout << "Withdrawal successful" << endl;
            BankAccount::withdraw(amount);
        }
        else
        {
            cout << "It exceeds the overdraft limit" << endl;
        }
    }

    float calculateInterest()
    {
        return 0.0;
    }

    void displayAccountInfo()
    {
        BankAccount::displayAccountInfo();
        cout << "Overdraft Limit: " << this->overdraftLimit << endl;
    }
};

class FixedDepositAccount : public BankAccount
{
private:
    int term;
    float interestRate;

public:
    FixedDepositAccount(int accountNumber, string accountHolderName, double balance, int term, double interestRate)
        : BankAccount(accountNumber, accountHolderName, balance)
    {
        this->term = term;
        this->interestRate = interestRate;
    }

    void deposit(double amount)
    {
        cout << "You cannot deposit in a Fixed Deposit account" << endl;
    }

    void withdraw(double amount)
    {
        cout << "You cannot withdraw from a Fixed Deposit account" << endl;
    }

    float calculateInterest() override
    {
        return (getBalance() * interestRate * term) / 100;
    }

    void displayAccountInfo()
    {
        BankAccount::displayAccountInfo();
        cout << "Term (years): " << this->term << endl;
        cout << "Interest Rate: " << this->interestRate << "%" << endl;
        cout << "Interest Earned: " << calculateInterest() << endl;
    }
};

class BankingRegistry
{
private:
    BankAccount *acc[100];
    int accCount = 0;

public:
    void addNewAccount(BankAccount *a)
    {
        acc[accCount++] = a;
        cout << "Account added successfully!" << endl << endl;
    }

    void searchAccount(int accountNumber)
    {
        bool found = false;
        for (int i = 0; i < accCount; i++)
        {
            if (acc[i]->getAccountNumber() == accountNumber)
            {
                cout << endl << "---------- Account Found ----------" << endl;
                acc[i]->displayAccountInfo();
                cout << endl;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Account Not Found" << endl << endl;
        }
    }

    void displayAccount()
    {
        cout << endl << "------------- Accounts -------------" << endl;
        for (int j = 0; j < accCount; j++)
        {
            cout << "Account #" << (j + 1) << endl;
            acc[j]->displayAccountInfo();
            cout << endl;
        }
    }

    void withdrawFromAccount(int accountNumber, double amount)
    {
        bool found = false;
        for (int k = 0; k < accCount; k++)
        {
            if (acc[k]->getAccountNumber() == accountNumber)
            {
                cout << endl << "---------- Withdrawal ----------" << endl;
                acc[k]->withdraw(amount);
                cout << endl;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Account Not Found" << endl << endl;
        }
    }

    void depositToAccount(int accountNumber, double amount)
    {
        bool found = false;
        for (int k = 0; k < accCount; k++)
        {
            if (acc[k]->getAccountNumber() == accountNumber)
            {
                cout << endl << "---------- Deposit ----------" << endl;
                acc[k]->deposit(amount);
                cout << endl;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Account Not Found" << endl << endl;
        }
    }
};

	void inputAccountDetails(int &accountNumber, string &accountHolderName, double &balance, int accountCount)
	{
		cout << "Enter Account " << accountCount << " Details" << endl;
		cout << "Enter Account Number: ";
		cin >> accountNumber;
		cout << "Enter Account Holder Name: ";
		cin.ignore();
		getline(cin, accountHolderName);
		cout << "Enter Account Balance: ";
		cin >> balance;
	}

int main()
{
    BankingRegistry registry;
    int choice, size, i, j, k;
    int accNo, term;
    float interestRate;
    char choice_char;
    string accName;
    double accBalance, overdraftLimit, amount;

    do
    {
        cout << "---------- Banking System Menu ----------" << endl;
        cout << "1. Add Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Search Account by Number" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            do
            {
                cout << "Account Type:" << endl;
                cout << "A. Savings Account" << endl;
                cout << "B. Checking Account" << endl;
                cout << "C. Fixed Deposit Account" << endl;
                cout << "D. Back to Banking Menu" << endl;
                cout << "E. Exit Program" << endl;
                cout << "Enter choice: ";
                cin >> choice_char;
                cout << endl;

                switch (choice_char)
                {
                case 'A':
                    cout << "How many Savings Accounts do you want to open (max = 100): ";
                    cin >> size;
                    if (size <= 100)
                    {
                        for (i = 0; i < size; i++)
                        {
                            inputAccountDetails(accNo, accName, accBalance, i + 1);
                            cout << "Enter Interest Rate: ";
                            cin >> interestRate;
                            registry.addNewAccount(new SavingsAccount(accNo, accName, accBalance, interestRate));
                        }
                    }
                    else
                    {
                        cout << "Size should not exceed 100" << endl << endl;
                    }
                    break;

                case 'B':
                    cout << "How many Checking Accounts do you want to open (max = 100): ";
                    cin >> size;
                    if (size <= 100)
                    {
                        for (j = 0; j < size; j++)
                        {
                            inputAccountDetails(accNo, accName, accBalance, j + 1);
                            cout << "Enter Overdraft Limit: ";
                            cin >> overdraftLimit;
                            registry.addNewAccount(new CheckingAccount(accNo, accName, accBalance, overdraftLimit));
                        }
                    }
                    else
                    {
                        cout << "Size should not exceed 100" << endl << endl;
                    }
                    break;

                case 'C':
                    cout << "How many Fixed Deposit Accounts do you want to open (max = 100): ";
                    cin >> size;
                    if (size <= 100)
                    {
                        for (k = 0; k < size; k++)
                        {
                            inputAccountDetails(accNo, accName, accBalance, k + 1);
                            cout << "Enter Term (years): ";
                            cin >> term;
                            cout << "Enter Interest Rate: ";
                            cin >> interestRate;
                            registry.addNewAccount(new FixedDepositAccount(accNo, accName, accBalance, term, interestRate));
                        }
                    }
                    else
                    {
                        cout << "Size should not exceed 100" << endl << endl;
                    }
                    break;

                case 'D':
                    cout << "Back to banking menu" << endl << endl;
                    break;

                case 'E':
                    cout << "Exiting program..." << endl;
                    return 0;

                default:
                    cout << "Invalid Input" << endl << endl;
                }

            } while (choice_char != 'D');
            break;

        case 2:
            cout << "Enter Account Number: ";
            cin >> accNo;
            cout << "Enter amount you want to deposit: ";
            cin >> amount;
            registry.depositToAccount(accNo, amount);
            break;

        case 3:
            cout << "Enter Account Number: ";
            cin >> accNo;
            cout << "Enter amount you want to withdraw: ";
            cin >> amount;
            registry.withdrawFromAccount(accNo, amount);
            break;

        case 4:
            cout << "Enter Account Number to search: ";
            cin >> accNo;
            registry.searchAccount(accNo);
            break;

        case 0:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Enter valid input" << endl << endl;
        }

    } while (choice != 0);

    return 0;
}
