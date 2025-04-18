#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int scoring(string word);

// Points assigned to each letter of the alphabet
int scrabblePoints[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                        1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    // Promt user for two words
    string player1 = get_string("Player 1: ");
    // string player1 = "Aok";
    string player2 = get_string("Player 2: ");
    // string player2 = "aakosigdjesi";

    // Score for each player
    int score1 = scoring(player1);
    int score2 = scoring(player2);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int scoring(string word)
{
    int score = 0;
    for (int i = 0, l = strlen(word); i < l; i++)
    {
        if (isupper(word[i]))
        {
            score += scrabblePoints[word[i] - 65]; // 65 is for upper case A in ASCII table
        }
        else if (islower(word[i]))
        {
            score += scrabblePoints[word[i] - 97]; // 97 is for lower case a in ASCII table
        }
    }
    return score;
}
