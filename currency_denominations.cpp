// Rahim Siddiq
// Project 1
// 09/24/2023

#include <stdio.h>

int main() 
{
    int numOf100s;                                          // Variables for number of denominations
    int numOf20s;
    int numOf10s;
    int numOf5s;
    int numOf1s;
    
    float money;
    int dollars;
    int coins;                                              // Variables for coins

    int numOfQuarters;                                      // Variables for coin denominations
    int numOfDimes;
    int numOfNickels;
    int numOfPennies;
   
    printf("Rahim Siddiq - Project 1\n\n");                 // Start header
    printf("Enter money: ");                                // Prompt for money
    scanf_s("%f", &money);

    dollars = (int)money;                                   // Convert to integer
    coins = (int)(money * 100) % 100;                       // Get amount of coins

    numOf100s = dollars / 100;                              // Find number of $100s
    dollars %= 100;                                         // Find remainder of dollars
    numOf20s = dollars / 20;
    dollars %= 20;
    numOf10s = dollars / 10;
    dollars %= 10;
    numOf5s = dollars / 5;
    dollars %= 5;
    numOf1s = dollars;                                      // Rest is single dollars

    numOfQuarters = coins / 25;                             // Find number of quarters
    coins %= 25;                                            // Find remainder of coins
    numOfDimes = coins / 10;
    coins %= 10;
    numOfNickels = coins / 5;
    coins %= 5;
    numOfPennies = coins;                                   // Rest is pennies

    printf("\nAmount of money: %6.2f\n", money);            // Display amount of money entered
    printf("Number of dollars %d\n\n", (int)money);         // Can't use "dollars", it is divided into denominations
    printf("Number of $100: %d\n", numOf100s);
    printf("Number of $20s: %d\n", numOf20s);
    printf("Number of $10s: %d\n", numOf10s);
    printf("Number of $5s: %d\n", numOf5s);
    printf("Number of $1s: %d\n", numOf1s);
    printf("\nNumber of Quarters: %d\n", numOfQuarters);
    printf("Number of Dimes: %d\n", numOfDimes);
    printf("Number of Nickels: %d\n", numOfNickels);
    printf("Number of Pennies: %d\n\n", numOfPennies);

    printf("Rahim Siddiq - End of Project 1\n");            // End footer

    return 0;
}