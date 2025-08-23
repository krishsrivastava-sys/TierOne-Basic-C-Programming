#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

struct Bank {
    int id;
    char holder[50];
    int balance;
};

static void clear_stdin(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {}
}

int main(void) {
    struct Bank *accounts = NULL; // Dynamic array of accounts
    int count = 0;                // Number of accounts
    char choice;
    int on_hand;
    int optchoice;
    int cid;

    printf("Welcome to the GAIA Banks!\n");

    // Account creation loop
    while (true) {
        printf("\nWould you like to create a new bank account? (y/n): ");
        if (scanf(" %c", &choice) != 1) {
            clear_stdin();
            printf("Invalid input. Please enter y or n.\n");
            continue;
        }
        choice = (char)tolower((unsigned char)choice);

        if (choice == 'y') {
            // Increase number of accounts
            int new_count = count + 1;
            struct Bank *tmp = realloc(accounts, new_count * sizeof(struct Bank));
            if (tmp == NULL) {
                printf("Memory allocation failed!\n");
                free(accounts);
                return 1;
            }
            accounts = tmp;
            count = new_count;

            // Fill in details of new account
            accounts[count - 1].id = count;

            printf("Enter the name of the account holder: ");
            if (scanf(" %49[^\n]", accounts[count - 1].holder) != 1) {
                clear_stdin();
                printf("Invalid name input. Skipping account creation.\n");
                // shrink back to previous size
                count--;
                accounts = realloc(accounts, count > 0 ? count * sizeof(struct Bank) : 0);
                continue;
            }

            printf("Set the default balance: ");
            if (scanf("%d", &accounts[count - 1].balance) != 1) {
                clear_stdin();
                printf("Invalid balance input. Skipping account creation.\n");
                count--;
                accounts = realloc(accounts, count > 0 ? count * sizeof(struct Bank) : 0);
                continue;
            }

            if (accounts[count - 1].balance < 0) {
                printf("Negative balance not allowed. Setting to 0.\n");
                accounts[count - 1].balance = 0;
            }

            printf("[+] Account created successfully with ID: %d\n", accounts[count - 1].id);
        } else if (choice == 'n') {
            printf("\n[i] Account creation finished.\n");
            break;
        } else {
            printf("Invalid choice. Please enter y or n.\n");
        }
    }

    // Operations menu
    while (true) {
        printf("\nChoose what operations you wish to perform:\n");
        printf("1. Check the list of bank accounts.\n");
        printf("2. Withdraw Money from a bank account.\n");
        printf("3. Deposit Money in a bank account.\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &optchoice) != 1) {
            clear_stdin();
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        if (optchoice == 1) {
            printf("\n=== List of Accounts Created ===\n");
            if (count == 0) {
                printf("[i] No accounts found.\n");
            } else {
                for (int i = 0; i < count; i++) {
                    printf("ID: %d | Holder: %s | Balance: %d\n",
                           accounts[i].id, accounts[i].holder, accounts[i].balance);
                }
            }

        } else if (optchoice == 2) {
            if (count == 0) {
                printf("No accounts exist. Create one first.\n");
                continue;
            }

            printf("Enter the ID of the account: ");
            if (scanf("%d", &cid) != 1) {
                clear_stdin();
                printf("Invalid input for account ID.\n");
                continue;
            }
            if (cid < 1 || cid > count) {
                printf("Please enter a valid id!\n");
                continue;
            }

            char name[50];
            strcpy(name, accounts[cid - 1].holder);
            int balance = accounts[cid - 1].balance;

            printf("The account (ID:%d | Holder: %s) has a balance of: $%d.\n", cid, name, balance);
            printf("How much cash do you wish to withdraw? ");
            if (scanf("%d", &on_hand) != 1) {
                clear_stdin();
                printf("Invalid amount.\n");
                continue;
            }

            if (on_hand <= 0) {
                printf("Please enter a positive amount.\n");
                continue;
            }
            if (accounts[cid - 1].balance < on_hand) {
                printf("Insufficient balance.\n");
                continue;
            }

            accounts[cid - 1].balance -= on_hand;
            printf("[INFO] Withdrawal successful. Money at hand: %d. New balance: %d\n",
                   on_hand, accounts[cid - 1].balance);

        } else if (optchoice == 3) {
            if (count == 0) {
                printf("No accounts exist. Create one first.\n");
                continue;
            }

            printf("Enter the ID of the account: ");
            if (scanf("%d", &cid) != 1) {
                clear_stdin();
                printf("Invalid input for account ID.\n");
                continue;
            }
            if (cid < 1 || cid > count) {
                printf("Please enter a valid id!\n");
                continue;
            }

            char name[50];
            strcpy(name, accounts[cid - 1].holder);
            int balance = accounts[cid - 1].balance;

            printf("The account (ID:%d | Holder: %s) has a balance of: $%d.\n", cid, name, balance);
            printf("How much cash do you wish to deposit? ");
            if (scanf("%d", &on_hand) != 1) {
                clear_stdin();
                printf("Invalid amount.\n");
                continue;
            }

            if (on_hand <= 0) {
                printf("Please enter a positive amount.\n");
                continue;
            }

            accounts[cid - 1].balance += on_hand;
            printf("[INFO] Deposit successful. New balance: %d\n", accounts[cid - 1].balance);

        } else if (optchoice == 4) {
            printf("Exiting...\n");
            break;

        } else {
            printf("Unknown option. Please choose 1-4.\n");
        }
    }

    free(accounts); // Clean up memory before exit
    return 0;
}