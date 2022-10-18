#include <iostream>

using namespace std;

float balance = 0;
int anotherTransaction;

void transaction() 
{
    int choice;
    cout << "\nEnter any option to be served!\n" << endl;
    cout << "1. Withdraw" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Balance\n" << endl;
    cout << ">>";
    cin >> choice;
    int amountToWithDraw;
    int amountToDeposit;

    switch(choice)
    {
        case 1:
            // Withdraw
            cout << "\nPlease enter amount to withdraw: ";
            cin >> amountToWithDraw;
            if (amountToWithDraw > balance)
            {
                cout << "There is no insufficient funds in your account" << endl;
                cout << "Do you want another transaction?\nPress 1 to proceed and 2 to exit" << endl;
                cout << ">>";
                cin >> anotherTransaction;
                if (anotherTransaction == 1)
                    transaction();
            }
            else
            {
                balance -= amountToWithDraw;
                cout << "You have withdrawn $" << amountToWithDraw << ".00 and you balance is $" << balance << ".00" << endl;
                cout << "Do you want another transaction?\nPress 1 to proceed and 2 to exit \n" << endl;
                cout << ">>";
                cin >> anotherTransaction;
                if (anotherTransaction == 1)
                    transaction();
            }
            break;

        case 2:
            // Deposit
            cout << "\nPlease enter amount to deposit: ";
            cin >> amountToDeposit;

            balance += amountToDeposit;

            cout << "Thank you for depositing, new balance is $" << balance << ".00" << endl;
            cout << "Do you want another transaction?\nPress 1 to proceed and 2 to exit\n" << endl;
            cout << ">>";
            cin >> anotherTransaction;
            if (anotherTransaction == 1)
                transaction();
            break;
        
        case 3:
            cout << "Your bank amount balance is: " << balance << endl;
            cout << "Do you want another transaction?\nPress 1 to proceed and 2 to exit \n" << endl;
            cout << ">>";
            cin >> anotherTransaction;
            if (anotherTransaction == 1)
                transaction();
            break;
    }
}

int main()
{
    transaction();
    return 0;
}