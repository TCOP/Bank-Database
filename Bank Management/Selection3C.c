#include <stdio.h>
#include "Selection3.3.h"

struct Info {
    char FirstName[20];
    char LastName[20];
    int AccNumber;
    float Balance;
};




    void Selection3C(){

                                system("cls");
                printf("Select Account you wish to remove \n*****************************\n");

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

                int removeCustomer;
                printf("Account Number: ");
                scanf("%d", &removeCustomer);
                getchar();

                int found = -1;
                for (int i = 0; i < num_customers; i++) {
                    if (customers[i].AccNumber == removeCustomer) {
                        found = i;
                        break;
                    }
                }

                if (found != -1) {
                    for (int i = found; i < num_customers - 1; i++) {
                        customers[i] = customers[i + 1];
                    }
                    num_customers--;

                    printf("Customer removed successfully!\n");

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
                } else {
                    printf("Account not found. No changes made.\n");
                    getchar();
                }

}
