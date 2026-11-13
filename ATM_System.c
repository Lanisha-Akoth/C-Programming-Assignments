#include <stdio.h>
#include <stdlib.h>

// Function declarations
int login(int storedPIN);
void checkBalance(double balance);
void deposit(double *balance);
void withdraw(double *balance);

int main()
{
    int storedPIN = 1234;
    int choice;
    double balance = 5000.00;

    // Login verification
    if (login(storedPIN))
    {
        printf("\nLogin successful!\n");

        // ATM menu
        do
        {
            printf("\n===== ATM MENU =====\n");
            printf("1. Balance Inquiry\n");
            printf("2. Deposit\n");
            printf("3. Withdraw\n");
            printf("4. Exit\n");

            printf("\nEnter your choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
                case 1:
                    checkBalance(balance);
                    break;

                case 2:
                    deposit(&balance);
                    break;

                case 3:
                    withdraw(&balance);
                    break;

                case 4:
                    printf("\nThank you for using our ATM. Goodbye!\n");
                    break;

                default:
                    printf("\nInvalid choice. Please try again.\n");
            }

        } while (choice != 4);
    }
    else
    {
        printf("\nAccess denied. Please contact your bank.\n");
    }

    return 0;
}

// Function definition for login
int login(int storedPIN)
{
    int enteredPIN;
    int attempts = 0;

    while (attempts < 3)
    {
        printf("Enter your PIN: ");
        scanf("%d", &enteredPIN);

        if (enteredPIN == storedPIN)
        {
            return 1;
        }
        else
        {
            attempts++;
            printf("Incorrect PIN. Attempts remaining: %d\n",
                   3 - attempts);
        }
    }

    return 0;
}

// Function definition for balance inquiry
void checkBalance(double balance)
{
    printf("\nYour current balance is: KSh %.2f\n", balance);
}

// Function definition for deposit
void deposit(double *balance)
{
    double amount;

    printf("\nEnter amount to deposit: KSh ");
    scanf("%lf", &amount);

    if (amount > 0)
    {
        *balance = *balance + amount;

        printf("Deposit successful!\n");
        printf("New balance: KSh %.2f\n", *balance);
    }
    else
    {
        printf("Invalid amount. Enter a positive amount.\n");
    }
}

// Function definition for withdrawal
void withdraw(double *balance)
{
    double amount;

    printf("\nEnter amount to withdraw: KSh ");
    scanf("%lf", &amount);

    if (amount <= 0)
    {
        printf("Invalid amount. Enter a positive amount.\n");
    }
    else if (amount > *balance)
    {
        printf("Insufficient balance!\n");
    }
    else
    {
        *balance = *balance - amount;

        printf("Withdrawal successful!\n");
        printf("Remaining balance: KSh %.2f\n", *balance);
    }
}

