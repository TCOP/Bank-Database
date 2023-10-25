#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>


struct Info {
    char FirstName[20];
    char LastName[20];
    int AccNumber;
    float Balance;
};








void Selection2(){


                system("cls");
                printf("World Bank\n*******************************\n\n");



                float total_balance = 0;
                struct Info customer;
                FILE * Fpointer = fopen("Customers.txt", "r");


                if(Fpointer != NULL){
                    while(fscanf(Fpointer, "Name: %s %s\nAccount number: %d\nBalance: %f\n*****************************\n",
                customer.FirstName, customer.LastName, &customer.AccNumber, &customer.Balance) == 4) {
                total_balance += customer.Balance;
            }
                fclose(Fpointer);
                printf("Total Assets Under Management: $%.2f\n", total_balance);

                } else {
                    printf("Error: Could not open file.\n");
                }


            printf("\n\nPress any key to return to the main menu...");
            getchar();



}
