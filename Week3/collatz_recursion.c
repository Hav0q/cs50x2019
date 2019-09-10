#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int collatz(int n)
{
    if (n == 1)
    {
        return 0;
    }
    else if (n % 2 == 0)
    {
        return 1 + collatz(n / 2);
    }
    else
    {
        return 1 + collatz(3 * n + 1 );
    }
}

int main(void)
{
    int result = 0;
    string userInput = get_string("Give me a number: ");
    result = atoi(userInput);
    result = collatz(result);
    printf("Steps required: %i\n", result);
}