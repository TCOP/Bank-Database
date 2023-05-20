#include <stdio.h>
#include <stdlib.h>
#include <limits.h>




struct Info {
    char FirstName[20];
    char LastName[20];
    int AccNumber;
    float Balance;
};








int main()
{
    int Selection;
    int customerCount = 0;
    printf("\n*******************************\n");
    printf("\nWelcome to World Bank!\n");
    printf("\nPlease Enter a Selection Below!\n");
    printf("\n1: View Customers\n");
    printf("2: View Total Assets\n");
    printf("3: Administrator View\n");
    printf("4: Exit\n");
    printf("\n*******************************\n");
    scanf("%d", &Selection);
    while (getchar() != '\n');





    if(Selection == 1){
        system("cls");
        printf("\nCustomer List\n");
        printf("*******************************\n");

        char filename[40];
        struct Info customer;
        //customer.AccNumber = 0;
                FILE * Fpointer = fopen("Customers.txt", "r");

                sprintf(filename, "%s %s.txt", customer.FirstName, customer.LastName);






            if (Fpointer != NULL) {
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
        scanf("%d", &accNumber);
        system("cls");
        while (getchar() != '\n');

        Fpointer = fopen("Customers.txt", "r");
        if (Fpointer != NULL) {
            while (fscanf(Fpointer, "Name: %s %s\nAccount number: %d\nBalance: %f\n*****************************\n",
                customer.FirstName, customer.LastName, &customer.AccNumber, &customer.Balance) == 4) {
                if (customer.AccNumber == accNumber) {
                    printf("\n*****************************\nName: %s %s\nAccount Number: %d\nBalance: $%.2f\n", customer.FirstName, customer.LastName, customer.AccNumber, customer.Balance);
                    break;
                }
            }
            fclose(Fpointer);
        } else {
            printf("Error: Could not open file.\n");
        }
        getchar();
    }








     if (Selection == 2){

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
            getchar();



    } if (Selection == 3){
        int Selection2;
        system("cls");
        FILE * Fpointer;
        printf("Administrator View\n");
        printf("\n*******************************\n");
        printf("\nPlease Make a Selection:\n");
        printf("1: Add New Customer\n");
        printf("2: Edit Current Customer\n");
        printf("3: Remove Customer\n");
        scanf("%d", &Selection2);
        while (getchar() != '\n');
            if (Selection2 == 1){
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
    }   if (Selection2 == 2) {
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
                }
            }









    } else if (Selection == 4){
        system("cls");
        printf("\n*******************************\n");
        printf("Thank you for Banking with us Today!\n");
        printf("Press any Key to Exit");
        printf("\n*******************************\n");
        getchar();
        return 0;

    }



    return 0;
}
