#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("What's yout name?\n");
    printf("hello, %s\n", name);
}
