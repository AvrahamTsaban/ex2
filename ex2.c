/******************
Name: Avraham Tsaban
Assignment: 2
*******************/

#include <stdio.h>

int main()
{
    // MAIN MENU LOOP
    int menuChoice;
    do {
        // Display menu options and get user choice
        printf("Welcome to our games, please choose an option:\n");
        printf("1. Ducky's Unity Game\n2. The Memory Game\n");
        printf("3. Professor Pat's Power Calculation\n4. The Duck Parade\n");
        printf("5. The Mystery of the Repeated Digits\n6. Good Night Ducks\n");
        scanf("%d", &menuChoice);
        switch (menuChoice)
        {
        // TASK 1: Ducky's Unity Game
            case 1: {
                // Get positive riddle number for ducky and validate it
                int riddleNumber;
                printf("please enter a positive number:\n");
                scanf("%d", &riddleNumber);
                while(riddleNumber <= 0) {
                    printf("Invalid number, please try again\n");
                    scanf("%d", &riddleNumber);
                } 
                // count 1 bits amount in riddle number (consuming it for efficient calculation)
                short corn = 0;
                while(riddleNumber > 0) {
                    if(riddleNumber & 1) {
                        ++corn;
                    }
                    riddleNumber >>= 1;
                }
                // Award corn to ducky :)
                printf("Ducky earns %d corns\n", corn);
                break;
            }

        // TASK 2: The Memory Game
            case 2: {
                // get a number of ducks and validate it
                const int maxMemoryDucks = 64;
                int ducksNumber;
                printf("please enter the number of ducks:\n");
                scanf("%d", &ducksNumber);
                while(ducksNumber > maxMemoryDucks || ducksNumber <= 0) {
                    printf("Invalid number, please try again\n");
                    scanf("%d", &ducksNumber);
                }
                printf("you entered %d ducks\n", ducksNumber);
                // Iterate over all ducks to get quak input from user
                unsigned long long quakList = 0;
                int doQuak;
                for(int i = 0; i < ducksNumber; i++) {
                    printf("duck %d do QUAK? 1 for yes, 0 for no\n", i+1);
                    // let user decide wether or not they quak (validating input)
                    scanf("%d", &doQuak);
                    while((doQuak < 0) || (doQuak > 1)) {
                        printf("Invalid number, please try again\n");
                        scanf("%d", &doQuak);
                    }
                    // store quak decision in bitmask
                    if(doQuak == 1) {
                        quakList |= ((unsigned long long)1 << i);
                    }
                }
                // Recall whom did quak and whom didn't
                unsigned long memoryScreen;
                for(int i = 0; i < ducksNumber; i++) {
                    // get the mask to point to the current i+1 duck
                    memoryScreen = (unsigned long long)1<<i;
                    // check if the duck quaked and print the appropriate message
                    if((quakList & memoryScreen) != 0) {
                        printf("duck number %d do Quak\n", i+1);
                    } else {
                        printf("duck number %d do Sh...\n", i+1);
                    }
                }
                break;
            }
        // TASK 3: Professor Pat's Power Calculation
            case 3: {
                // get base and exponent from user and validate them
                int base, exponent;
                int result = 1;
                printf("please enter the number\n");
                scanf("%d", &base);
                while(base < 0) {
                    printf("Invalid number, please try again\n");
                    scanf("%d", &base);
                } 
                printf("please enter the exponent\n");
                scanf("%d", &exponent);
                while(exponent < 0) {
                    printf("Invalid number, please try again\n");
                    scanf("%d", &exponent);
                } 
                // calculate power and print result
                for (; exponent > 0; exponent--)
                {
                    result *= base;
                }
                printf("your power is: %d\n", result);
                break;
            }
        // TASK 4: The Duck Parade
            case 4: {
                // get ducks number from user and validate their number
                int paradeLength;
                printf("please enter number of ducks:\n");
                scanf("%d", &paradeLength);
                while(paradeLength < 0) {
                    printf("Invalid number, please try again\n");
                    scanf("%d", &paradeLength);
                } 
                // setup counter and print the parade in rows until no ducks are left
                int counter;
                while (paradeLength > 0) {
                    // limit counter to 10 ducks per row
                    if (paradeLength > 10) {
                        counter = 10;
                        paradeLength -= 10;
                    } else {
                        counter = paradeLength;
                        paradeLength = 0;
                    }
                    // print the current row of ASCII ducks
                    int i;
                    for (i = 1; i <= counter; i++) {
                        printf("   _  \t\t");
                    }
                    printf("\n");
                    for (i = 1; i <= counter; i++) {
                        printf("__(o)>\t\t");
                    }
                    printf("\n");
                    for (i = 1; i <= counter; i++) {
                        printf("\\___) \t\t");
                    }
                    printf("\n");
                } 
                printf("\n");
                break;
            }
        // TASK 5: The Mystery of the Repeated Digits
            case 5: {
                // prompt user to provide the mysterious number and validate it
                int codeNumber;
                printf("please enter number\n");
                scanf("%d", &codeNumber);
                while(codeNumber <= 0) {
                    printf("Invalid number, please try again\n");
                    scanf("%d", &codeNumber);
                }
                // recognize repeated digits and print them
                unsigned int digitMask = 0;
                int currentDigit;
                // loop over all digits in the number
                while(codeNumber != 0) {
                    // get the last digit
                    currentDigit = codeNumber % 10;
                    // if the digit was already seen, prompt the user. else, mark it as seen
                    if ((digitMask & ((unsigned int)1 << currentDigit)) == 0) {
                        digitMask |= ((unsigned int)1 << currentDigit);
                    } else {
                        printf("%d appears more than once!\n", currentDigit);
                    }
                    // remove the last digit from the number
                    codeNumber /= 10;
                }
                break;
            }
        // TASK 6: EXIT
            case 6: {
                // print goodbye message 
                printf("Good night! See you at the pond tomorrow.\n");
                break;
                // the program exits because of the loop condition below
            }
        // in case of invalid input: print error messege and return to menu
            default: {
                printf("Invalid option, please try again\n");
                break;
            }
        }

    } while (menuChoice != 6);

    return 0;
}
