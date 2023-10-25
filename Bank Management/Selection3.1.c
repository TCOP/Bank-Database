#include <stdio.h>
#include "Selection3.1.h"


struct Info {
    char FirstName[20];
    char LastName[20];
    int AccNumber;
    float Balance;
};

        FILE * Fpointer;


void add_new_customer(int customerCount) {

            char filename[40];
                    struct Info new_customer;
                    new_customer.AccNumber = customerCount + 1;
                    customerCount++;




                    printf("Enter Customer First Name: ");
                    scanf("%s", new_customer.FirstName);
                    while (getchar() != '\n');

                    printf("Enter Customer Last Name: ");
                    scanf("%s", new_customer.LastName);
                    while (getchar() != '\n');

                    printf("Enter Account Number: ");
                    scanf("%d", &new_customer.AccNumber);
                    while (getchar() != '\n');

                    printf("Enter Balance (No Commas): $");
                    scanf("%f", &new_customer.Balance);
                    while (getchar() != '\n');

                    sprintf(filename, "Customers.txt");
                    Fpointer = fopen(filename , "a");

                        if (Fpointer == NULL){
                        printf("Error: Could not create file.\n");
                        return 1;
                        }

                    fprintf(Fpointer, "Name: %s %s\nAccount number: %d\nBalance: %.2f\n*****************************\n", new_customer.FirstName, new_customer.LastName, new_customer.AccNumber, new_customer.Balance);
                    fclose(Fpointer);



}
