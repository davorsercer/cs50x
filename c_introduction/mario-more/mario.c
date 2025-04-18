#include <cs50.h>
#include <stdio.h>

void print_hash(int hashes, int spaces);

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    for (int i = 0; i < height; i++)
    {
        print_hash(i + 1, height - i - 1);
    }
}

void print_hash(int hashes, int spaces)
{
    for (int i = 0; i < spaces; i++)
    {
        printf(" ");
    }
    for (int i = 0; i < hashes; i++)
    {
        printf("#");
    }
    printf("  ");
    for (int i = 0; i < hashes; i++)
    {
        printf("#");
    }
    printf("\n");
}
