#include <cs50.h>
#include <stdio.h>

int adding1(long int card_no);
int adding2(long int card_no);

// Luhn’s Algorithm
int main(void)
{
    // Card no. prompt
    int long card_no;
    do
    {
        card_no = get_long("Please enter yout credit card number: ");
    }
    while (card_no < 0);

    // Checking card no. validation
    int addition = adding1(card_no) + adding2(card_no);
    // printf("%i\n", addition);

    int validation = addition % 10;
    // validation == 0 ? printf("VALID\n") : printf("INVALID\n");

    if (validation == 0)
    {
        int master_16 = card_no / 100000000000000;
        int amex_15 = card_no / 10000000000000;
        int visa_16 = card_no / 1000000000000000;
        int visa_13 = card_no / 1000000000000;

        if (master_16 > 50 && master_16 < 56)
        {
            printf("MASTERCARD\n");
        }
        else if (amex_15 == 34 || amex_15 == 37)
        {
            printf("AMEX\n");
        }
        else if (visa_16 == 4 || visa_13 == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

// Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add
// those products’ digits together.
int adding1(long int card_no)
{
    // Extracing every other digit, starting with the number’s second-to-last digit.
    int a = card_no % 100 / 10; // 2nd_to_last_digit

    int long crippled_card_no;
    crippled_card_no = card_no / 100;    // last 2 digits removed
    int b = crippled_card_no % 100 / 10; // 4th_to_last_digit

    crippled_card_no /= 100;             // last 2 digits removed
    int c = crippled_card_no % 100 / 10; // 6th_to_last_digit

    crippled_card_no /= 100;             // last 2 digits removed
    int d = crippled_card_no % 100 / 10; // 8th_to_last_digit

    crippled_card_no /= 100;             // last 2 digits removed
    int e = crippled_card_no % 100 / 10; // 10th_to_last_digit

    crippled_card_no /= 100;             // last 2 digits removed
    int f = crippled_card_no % 100 / 10; // 12th_to_last_digit

    crippled_card_no /= 100;             // last 2 digits removed
    int g = crippled_card_no % 100 / 10; // 14th_to_last_digit

    crippled_card_no /= 100;             // last 2 digits removed
    int h = crippled_card_no % 100 / 10; // 16_to_last_digit

    // Checking extraction
    // printf("%i %i %i %i %i %i %i %i\n", a, b, c, d, e, f, g, h);

    // Multiply that every other digit by 2
    a *= 2;
    b *= 2;
    c *= 2;
    d *= 2;
    e *= 2;
    f *= 2;
    g *= 2;
    h *= 2;

    // Checking multiplication
    // printf("%i %i %i %i %i %i %i %i\n", a, b, c, d, e, f, g, h);

    // If we get 2 digit product, we need to separate it in 2 single digits with extra variables
    int z, y, x, w, v, u, t, s;
    z = y = x = w = v = u = t = s = 0;

    if (a > 9)
    {
        z = a % 10;
        a /= 10;
    }

    if (b > 9)
    {
        y = b % 10;
        b /= 10;
    }

    if (c > 9)
    {
        x = c % 10;
        c /= 10;
    }

    if (d > 9)
    {
        w = d % 10;
        d /= 10;
    }

    if (e > 9)
    {
        v = e % 10;
        e /= 10;
    }

    if (f > 9)
    {
        u = f % 10;
        f /= 10;
    }

    if (g > 9)
    {
        t = g % 10;
        g /= 10;
    }

    if (h > 9)
    {
        s = h % 10;
        h /= 10;
    }

    // Checking seplaration
    // printf("%i %i %i %i %i %i %i %i\n", a, b, c, d, e, f, g, h);
    // printf("%i %i %i %i %i %i %i %i\n", z, y, x, w, v, u, t, s);

    // Adding those products’ digits
    int addition = a + b + c + d + e + f + g + h + z + y + x + w + v + u + t + s;

    // printf("%i\n", addition);
    return addition;
}

// Sum of the digits that weren’t multiplied by 2
int adding2(long int card_no)
{
    // Extracing every other digit that weren’t multiplied by 2 (starting from the end):
    int a = card_no % 10; // last_digit

    int long crippled_card_no;
    crippled_card_no = card_no / 100; // last 2 digits removed
    int b = crippled_card_no % 10;    // 3th_to_last_digit

    crippled_card_no /= 100;       // last 2 digits removed
    int c = crippled_card_no % 10; // 5th_to_last_digit

    crippled_card_no /= 100;       // last 2 digits removed
    int d = crippled_card_no % 10; // 7th_to_last_digit

    crippled_card_no /= 100;       // last 2 digits removed
    int e = crippled_card_no % 10; // 9th_to_last_digit

    crippled_card_no /= 100;       // last 2 digits removed
    int f = crippled_card_no % 10; // 11th_to_last_digit

    crippled_card_no /= 100;       // last 2 digits removed
    int g = crippled_card_no % 10; // 13th_to_last_digit

    crippled_card_no /= 100;       // last 2 digits removed
    int h = crippled_card_no % 10; // 15_to_last_digit

    // Checking extraction
    // printf("%i %i %i %i %i %i %i %i\n", a, b, c, d, e, f, g, h);

    int addition = a + b + c + d + e + f + g + h;

    // printf("%i\n", addition);
    return addition;
}
