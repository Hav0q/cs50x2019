#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //Declaring card number, taking input from user and verifying if it's positive
    long number = 0;
    do
    number = get_long("Card Number: ");
    while (number <= 0);
    
    //Verifying number of characters
    int digits = 0;
    long verification = number;
    do
    {
        verification /= 10;
        digits++;
    } while (verification > 0);
    // Manual verification of the number of digits
    // printf("%i \n", digits);
   
    //Verifying number by card type (Visa 13/16, Mastercard 16, AMEX 15)
    if (digits != 13 && digits != 15 && digits != 16)
    {
        printf("INVALID\n");
    }
   
    //Digits allocation
    int digit1 = number % 10;
    int digit2 = number % 100 / 10;
    int digit3 = number % 1000 / 100;
    int digit4 = number % 10000 / 1000;
    int digit5 = number % 100000 / 10000;
    int digit6 = number % 1000000 / 100000;
    int digit7 = number % 10000000 / 1000000;
    int digit8 = number % 100000000 / 10000000;
    int digit9 = number % 1000000000 / 100000000;
    int digit10 = number % 10000000000 / 1000000000;
    int digit11 = number % 100000000000 / 10000000000;
    int digit12 = number % 1000000000000 / 100000000000;
    int digit13 = number % 10000000000000 / 1000000000000;
    int digit14 = (number / 10000000000000) % 10;
    int digit15 = (number / 100000000000000) % 10;
    int digit16 = (number / 1000000000000000) % 10;
    
    // Manual verification of digits if needed
    // printf("%i%i%i%i%i%i%i%i%i%i%i%i%i%i%i%i\n", digit16, digit15, digit14, digit13, digit12, digit11, digit10, digit9, digit8, digit7, digit6, digit5, digit4, digit3, digit2, digit1);

    // Validating with Luhn's Algorithm
    // Digits needed for validation
    int vdigit2 = (digit2 * 2) % 10 + ((digit2 * 2) % 100) / 10;
    int vdigit4 = (digit4 * 2) % 10 + ((digit4 * 2) % 100) / 10;
    int vdigit6 = (digit6 * 2) % 10 + ((digit6 * 2) % 100) / 10;
    int vdigit8 = (digit8 * 2) % 10 + ((digit8 * 2) % 100) / 10;
    int vdigit10 = (digit10 * 2) % 10 + ((digit10 * 2) % 100) / 10;
    int vdigit12 = (digit12 * 2) % 10 + ((digit12 * 2) % 100) / 10;
    int vdigit14 = (digit14 * 2) % 10 + ((digit14 * 2) % 100) / 10;
    int vdigit16 = (digit16 * 2) % 10 + ((digit16 * 2) % 100) / 10;
    int validation = 0;
    
    // Defining the checksums
    int checksum13 = vdigit2 + vdigit4 + vdigit6 + vdigit8 + vdigit10 + vdigit12 + digit1 + digit3 + digit5 + digit7 + digit9 + digit11 + digit13;
    int checksum15 = checksum13 + vdigit14 + digit15;
    int checksum16 = checksum15 + vdigit16;
    
    // Validation algorithm
    if (digits == 15 && (digit15 == 3 && (digit14 == 4 || digit14 == 7)) && checksum15 % 10 == 0)
    {
       printf("AMEX\n");
    }
    else if (digits == 13 && digit13 == 4 && checksum13 % 10 == 0)
    {
        printf("VISA\n");
    }
    else if (digits == 16 && digit16 == 4 && checksum16 % 10 == 0)
    {
        printf("VISA\n");
    }
    else if (digits == 16 && digit16 == 5 && (digit15 == 1 || digit15 == 2 || digit15 == 3 || digit15 == 4 || digit15 == 5) && checksum16 % 10 == 0)
    {
        printf("MASTERCARD\n");
    }
    else 
    {
        printf("INVALID\n");
    }
}
