#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_alpha(string s);
int is_duplicate(string s);

int main(int argc, string argv[])
{
    // Validating argv input
    if (argc != 2 || argc > 2 || strlen(argv[1]) != 26 || is_alpha(argv[1]) != 0 ||
        is_duplicate(argv[1]) != 0)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    string key = argv[1];
    string abc = "abcdefghijklmnopqrstuvwxyz";

    // Prompting for plaintext
    string pltxt = get_string("plaintext:  ");

    // Getting index number of abc array, encipher and printing ciphertext
    printf("ciphertext: ");
    for (int i = 0, len1 = strlen(pltxt); i < len1; i++)
    {
        // Printing non alpha, punctuation, spaces and tabs
        if (!isalpha(pltxt[i]) || ispunct(pltxt[i]) || pltxt[i] == '?' || isspace(pltxt[i]))
        {
            printf("%c", pltxt[i]);
        }
        // Encipher printing ciphertext
        for (int j = 0, len2 = strlen(abc); j < len2; j++)
        {
            if (pltxt[i] == abc[j])
            {
                printf("%c", tolower(key[j]));
            }
            else if (pltxt[i] == toupper(abc[j]))
            {
                printf("%c", toupper(key[j]));
            }
        }
    }
    printf("\n");
    return 0;
}

// Is plaintext alphabetical only
int is_alpha(string s)
{
    int j = 0;
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (!isalpha(s[i]))
            j++;
    }
    return j;
}

// Checking duplicates
int is_duplicate(string s)
{
    int k = 0;
    for (int i = 0, len = strlen(s); i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (s[i] == s[j])
                k++;
        }
    }
    return k;
}
