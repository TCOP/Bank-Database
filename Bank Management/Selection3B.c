#include <stdio.h>
#include "Selection3.2.h"

struct Info {
    char FirstName[20];
    char LastName[20];
    int AccNumber;
    float Balance;
};




void Selection3B(void){

                system("cls");
                printf("Select Account you wish to edit \n*****************************\n");

                struct Info customer;
                struct Info customers[1000]; // maximum 1000 customers
                int num_customers = 0;

                FILE *Fpointer = fopen("Customers.txt", "r");

                if (Fpointer != NULL) {
                    while (fscanf(Fpointer, "Name: %s %s\nAccount number: %d\nBalance: %f\n*****************************\n",
                                  customer.FirstName, customer.LastName, &customer.AccNumber, &customer.Balance) == 4) {
                        customers[num_customers] = customer;
                        printf("Account Number: %d\nName: %s %s\n\n", customer.AccNumber, customer.FirstName, customer.LastName);
                        num_customers++;
                    }
                    fclose(Fpointer);
                }

                int editCustomer;
                printf("Account Number: ");
                scanf("%d", &editCustomer);
                getchar();

                for (int i = 0; i < num_customers; i++) {
                    if (customers[i].AccNumber == editCustomer) {
                        printf("\n*****************************\nName: %s %s\nAccount Number: %d\nBalance: $%.2f\n",
                               customers[i].FirstName, customers[i].LastName, customers[i].AccNumber, customers[i].Balance);

                        printf("Enter new first name: ");
                        scanf("%s", customers[i].FirstName);
                        getchar();

                        printf("Enter new last name: ");
                        scanf("%s", customers[i].LastName);
                        getchar();

                        printf("Enter new account number: ");
                        scanf("%d", &customers[i].AccNumber);
                        getchar();

                        printf("Enter new balance: ");
                        scanf("%f", &customers[i].Balance);
                        getchar();

                        printf("Account edited successfully!\n");
                        break;
                    }
                }

                // Write the updated customer information back to the file
                Fpointer = fopen("Customers.txt", "w");
                if (Fpointer != NULL) {
                    for (int i = 0; i < num_customers; i++) {
                        fprintf(Fpointer, "Name: %s %s\nAccount number: %d\nBalance: %.2f\n*****************************\n",
                                customers[i].FirstName, customers[i].LastName, customers[i].AccNumber, customers[i].Balance);
                    }
                    fclose(Fpointer);
                } else {
                    printf("Error: Could not open file.\n");
                    getchar();

                }

}
