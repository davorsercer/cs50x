#include <cs50.h>
#include <stdio.h>

int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);
int calculate_quarters(int cents);

// Magic Numbers

#define DIME_VALUE 10
#define NICKEL_VALUE 5
#define PENNIE_VALUE 1
#define QUARTER_VALUE 25

// Greedy Algorithms for quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢)

int main(void)
{
    // Promp user for change owned, unit: cents
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    // Calculating quarters and subtracting that value fron int cent
    int quarters = calculate_quarters(cents);
    cents -= quarters * QUARTER_VALUE;

    // Calculating dimes and subtracting that value fron int cent
    int dimes = calculate_dimes(cents);
    cents -= dimes * DIME_VALUE;

    // Calculating nickels and subtracting that value fron int cent
    int nickels = calculate_nickels(cents);
    cents -= nickels * NICKEL_VALUE;

    // Calculating pennies and subtracting that value is not needed
    int pennies = calculate_pennies(cents);

    int sum = quarters + dimes + nickels + pennies;
    printf("%i\n", sum);
}

int calculate_quarters(int cents)
{
    int coins = 0;
    int coin_value = QUARTER_VALUE;
    while (cents >= coin_value)
    {
        coins++;
        cents -= coin_value;
    }
    return coins;
}

int calculate_dimes(int cents)
{
    int coins = 0;
    int coin_value = DIME_VALUE;
    while (cents >= coin_value)
    {
        coins++;
        cents -= coin_value;
    }
    return coins;
}

int calculate_nickels(int cents)
{
    int coins = 0;
    int coin_value = NICKEL_VALUE;
    while (cents >= coin_value)
    {
        coins++;
        cents -= coin_value;
    }
    return coins;
}

int calculate_pennies(int cents)
{
    int coins = 0;
    int coin_value = PENNIE_VALUE;
    while (cents >= coin_value)
    {
        coins++;
        cents -= coin_value;
    }
    return coins;
}
