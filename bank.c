#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int account_number;
    float balance;
} Customer;

Customer customers[100];
int num_customers = 0;

void add_customer(char *name, int account_number, float balance) {
    strcpy(customers[num_customers].name, name);
    customers[num_customers].account_number = account_number;
    customers[num_customers].balance = balance;
    num_customers++;
}

void remove_customer(int account_number) {
    for (int i = 0; i < num_customers; i++) {
        if (customers[i].account_number == account_number) {
            for (int j = i; j < num_customers - 1; j++) {
                customers[j] = customers[j + 1];
            }
            num_customers--;
            break;
        }
    }
}

void update_customer(int account_number, char *name, float balance) {
    for (int i = 0; i < num_customers; i++) {
        if (customers[i].account_number == account_number) {
            strcpy(customers[i].name, name);
            customers[i].balance = balance;
            break;
        }
    }
}

void view_customers() {
    printf("Name\tAccount Number\tBalance\n");
    for (int i = 0; i < num_customers; i++) {
        printf("%s\t%d\t%.2f\n", customers[i].name, customers[i].account_number, customers[i].balance);
    }
}

void deposit(int account_number, float amount) {
    for (int i = 0; i < num_customers; i++) {
        if (customers[i].account_number == account_number) {
            customers[i].balance += amount;
            break;
        }
    }
}

void withdraw(int account_number, float amount) {
    for (int i = 0; i < num_customers; i++) {
        if (customers[i].account_number == account_number) {
            if (customers[i].balance >= amount) {
                customers[i].balance -= amount;
            } else {
                printf("Insufficient balance\n");
            }
            break;
        }
    }
}

int main() {
    int choice;
    char name[50];
    int account_number;
    float balance;
    float amount;

    while (1) {
        printf("1. Add customer\n");
        printf("2. Remove customer\n");
        printf("3. Update customer\n");
        printf("4. View customers\n");
        printf("5. Deposit\n");
        printf("6. Withdraw\n");
        printf("7. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter account number: ");
                scanf("%d", &account_number);
                printf("Enter balance: ");
                scanf("%f", &balance);
                add_customer(name, account_number, balance);
                break;
            case 2:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                remove_customer(account_number);
                break;
            case 3:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter balance: ");
                scanf("%f", &balance);
                update_customer(account_number, name, balance);
                break;
            case 4:
                view_customers();
                break;
            case 5:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                printf("Enter amount: ");
                scanf("%f", &amount);
                deposit(account_number, amount);
                break;
            case 6:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                printf("Enter amount: ");
                scanf("%f", &amount);
                withdraw(account_number, amount);
                break;
            case 7:
                exit(0);
        }
    }

    return 0;
}
