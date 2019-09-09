#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int collatz(int n)
{
    int steps = 0;
    while (n > 1)
    {
        if (n % 2 == 0)
        {
            n = n/2;
            steps += 1;
        }
        else if (n % 2 != 0)
        {
            n = 3 * n + 1;
            steps += 1;
        }
    }
    return steps;
}

int main (void)
{
    int collatz(int n);
    string thatNumber = get_string("Give me a number: ");
    int sameNumber = atoi(thatNumber);
    int result = collatz(sameNumber);
    printf("Steps required: %i\n", result);
}