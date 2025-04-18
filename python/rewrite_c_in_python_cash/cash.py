from cs50 import get_float

# Coin values
dime = 10
nickel = 5
pennie = 1
quarter = 25

# Promp user for change owned, unit: dollars
while True:
    dollars = get_float("Change in dollars, please: ")
    if dollars > 0:
        break


def main():

    # Converting dollars to cents, floats to int
    cents = int(dollars * 100)

    # Calculating quarter coins and subtracting that value fron int cent
    quarters = calculate_quarters(cents)
    remaining_cents = cents - quarters * quarter

    # Calculating dime coins and subtracting that value fron int cent
    dimes = calculate_dimes(remaining_cents)
    remaining_cents -= dimes * dime

    # Calculating nickel coins and subtracting that value fron int cent
    nickels = calculate_nickels(remaining_cents)
    remaining_cents -= nickels * nickel

    # Calculating pennie coins and subtracting that value fron int cent
    pennis = calculate_pennis(remaining_cents)

    # Summing up all coins and printing the sum
    coins = quarters + dimes + nickels + pennis
    print(coins)


def calculate_quarters(n):
    coins = 0
    while n >= quarter:
        coins += 1
        n -= quarter
    return coins


def calculate_dimes(n):
    coins = 0
    while n >= dime:
        coins += 1
        n -= dime
    return coins


def calculate_nickels(n):
    coins = 0
    while n >= nickel:
        coins += 1
        n -= nickel
    return coins


def calculate_pennis(n):
    coins = 0
    while n >= pennie:
        coins += 1
        n -= pennie
    return coins


main()
