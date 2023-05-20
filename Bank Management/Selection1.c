#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
int customerCount = 0;

struct Info {
    char FirstName[20];
    char LastName[20];
    int AccNumber;
    float Balance;
};



void Selection1(){
                        system("cls");
                printf("\nCustomer List\n");
                printf("*******************************\n");

                char filename[40];
                struct Info customer;
                //customer.AccNumber = 0;
                        FILE * Fpointer = fopen("Customers.txt", "r");

                        sprintf(filename, "%s %s.txt", customer.FirstName, customer.LastName);






                    if (Fpointer != NULL) {
                    customerCount = 0;
                    while (fscanf(Fpointer, "Name: %s %s\nAccount number: %d\nBalance: %f\n*****************************\n",
                    customer.FirstName, customer.LastName, &customer.AccNumber, &customer.Balance) == 4) {
                    printf("Account Number: %d\nName: %s %s\n\n", customer.AccNumber, customer.FirstName, customer.LastName);
                    customerCount++;
                }
                printf("Customer Accounts: %d", customerCount);
                fclose(Fpointer);
                    }



                printf("\nEnter an account number: ");
                int accNumber;



                char input_acc[100];
                fgets(input_acc, 100, stdin);
                input_acc[strcspn(input_acc, "\n")] = 0; // Remove the newline character

                if (is_valid_integer(input_acc)) {
                    accNumber = atoi(input_acc);
                } else {
                    accNumber = -1; // Set to an invalid account number if the input is not a valid integer
                }





                system("cls");
                //while (getchar() != '\n');

                Fpointer = fopen("Customers.txt", "r");
                int account_found = 0;

                if (Fpointer != NULL) {
                    while (fscanf(Fpointer, "Name: %s %s\nAccount number: %d\nBalance: %f\n*****************************\n",
                        customer.FirstName, customer.LastName, &customer.AccNumber, &customer.Balance) == 4) {
                        if (customer.AccNumber == accNumber) {
                            account_found = 1;
                            printf("\n*****************************\nName: %s %s\nAccount Number: %d\nBalance: $%.2f\n", customer.FirstName, customer.LastName, customer.AccNumber, customer.Balance);
                            break;
                        }
                    }
                    fclose(Fpointer);
                } else {
                    printf("Error: Could not open file.\n");
                }

                // Display the error message only if the account is not found
                if (!account_found) {
                    printf("Error: Please Enter Valid Account Number.\n");
                }

                printf("\n\nPress any key to return to the main menu...");
                getchar();
}
