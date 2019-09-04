#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float change = 0;
    do
    change = get_float("Change owed: ");
    while (change <= 0);
    printf("$%.2f\n", change);
    int coins = round(change*100);
    int dollars = 0;
    int quarts = 0;
    int tens = 0;
    int cents = 0;
 
    if (coins >= 100)
    {
        dollars = coins / 100;
        coins = coins % 100;
    }

    if (coins >= 25)
    {
        quarts = coins / 25;
        coins = coins % 25;
    }
    
    if (coins >= 10)
    {
        tens = coins / 10;
        coins = coins % 10;
    }
    
    printf("dollars: %i, quarts: %i, tens: %i, cents: %i \n", dollars, quarts, tens, coins);
}
