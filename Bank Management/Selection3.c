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




void Selection3(){

    int customerCount = 0;
    int Selection2;
    char input[100];


            system("cls");
            FILE * Fpointer;
            printf("Administrator View\n");
            printf("\n*******************************\n");
            printf("\nPlease Make a Selection:\n");
            printf("1: Add New Customer\n");
            printf("2: Edit Current Customer\n");
            printf("3: Remove Customer\n");
            printf("4: Return to Main Menu\n");
            fgets(input, 100, stdin);
            input[strcspn(input, "\n")] = 0; // Remove the newline character

            if (is_valid_integer(input))
                    {
                Selection2 = atoi(input);
            } else {
                Selection2 = 0; // Set to an invalid selection if the input is not a valid integer
                    }


            if (Selection2 == 1) {

                Selection3A();

            } else if (Selection2 == 2) {

                Selection3B();

            } else if (Selection2 == 3) {

                Selection3C();

            } else if (Selection2 == 4) {

                printf("\nReturning to the main menu...");

            } else {

                printf("\nInvalid selection. Returning to the main menu...");
            }
            printf("\n\nPress any key to continue...");
            while (getchar() != '\n');
            getchar();
}
