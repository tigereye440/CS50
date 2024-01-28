#include <cs50.h>
#include <stdio.h>

//Defining constant global variables
const int QUARTERS = 25;
const int DIMES = 10;
const int NICKELS = 5;
const int PENNIES = 1;

// Coin function prototype
int coins(int change);

int main(void)
{
    int change_owed;

    //Prompting user for integer input
    do
    {
        change_owed = get_int("Enter your change in cents: ");
    }
    while (change_owed < 0);

    printf("Coins:  %i\n", coins(change_owed));
}


// Change function
int coins(int change)
{
    int remainder = 0;
    int quarters = change / QUARTERS;
    remainder = change - (quarters * QUARTERS);
    int dimes = remainder / DIMES;
    remainder = remainder - (dimes * DIMES);
    int nickels = remainder / NICKELS;
    remainder = remainder - (nickels * NICKELS);
    int pennies = remainder / PENNIES;
    remainder = remainder - (pennies * PENNIES);

    int coins = quarters + dimes + nickels + pennies;
    return coins;
}
