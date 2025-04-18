#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AZ 26

int is_digit(string s);

int main(int argc, string argv[])
{
    // Validating argv input
    if (argc != 2 || argc > 2 || atoi(argv[1]) < 0 || is_digit(argv[1]) != 0)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    int input = atoi(argv[1]);

    // Prompting for plaintext
    string plaintext = get_string("plaintext:  ");

    // Encipher and printing ciphertext
    printf("ciphertext: ");
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        // If lowercase
        if (islower(plaintext[i]))
        {
            if (plaintext[i] - 'a' + input < AZ)
            {
                printf("%c", plaintext[i] + input);
            }
            else if (plaintext[i] - 'a' + input >= AZ)
            {
                printf("%c", (plaintext[i] - 'a' + input) % AZ + 'a');
            }
        }
        // If uppercase
        else if (isupper(plaintext[i]))
        {
            if (plaintext[i] - 'A' + input < AZ)
            {
                printf("%c", plaintext[i] + input);
            }
            else if (plaintext[i] - 'A' + input >= AZ)
            {
                printf("%c", (plaintext[i] - 'A' + input) % AZ + 'A');
            }
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}

// decimal digit
int is_digit(string s)
{
    int j = 0;
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        // printf("%i %i %i\n", isalpha(s[i]), ispunct(s[i]), isspace(s[i]));
        // if (isalpha(s[i]) || ispunct(s[i]) || isspace(s[i]))
        if (!isdigit(s[i]))
            j++;
    }
    // printf("%i\n", j);
    return j;
}
