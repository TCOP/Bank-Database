#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
void Selection1();
void Selection2();
void Selection3();


struct Info {
    char FirstName[20];
    char LastName[20];
    int AccNumber;
    float Balance;
};



int is_valid_integer(const char *str) {
    while (*str) {
        if (!isdigit(*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}




int main()
{
    int Selection;
    int customerCount = 0;

    while (1) {
        system("cls");
        printf("\n*******************************\n");
        printf("\nWelcome to World Bank!\n");
        printf("\nPlease Enter a Selection Below!\n");
        printf("\n1: View Customers\n");
        printf("2: View Total Assets\n");
        printf("3: Administrator View\n");
        printf("4: Exit\n");
        printf("\n*******************************\n");
        char input[100];
        fgets(input, 100, stdin);
        input[strcspn(input, "\n")] = 0; // Remove the newline character

        if (is_valid_integer(input)) {
            Selection = atoi(input);
        } else {
            Selection = 0; // Set to an invalid selection if the input is not a valid integer
        }

        if (Selection == 1) {

            Selection1();

        } else if (Selection == 2) {

            Selection2();

        } else if (Selection == 3) {

            Selection3();

        } else if (Selection == 4) {

            Selection4();

            return 0;
        } else {
            printf("\nInvalid selection. Press Enter to return to the main menu...");
            getchar();
        }
    }

    return 0;
}
