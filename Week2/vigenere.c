#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int shift(char c);

int main(int argc, string argv[])
{
    int letter = 0;
    
    if (argc == 2)
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (!isalpha(argv[1][i]))
            {
                letter++;
            }
        }
    }
    else
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    
    if (letter > 0)
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    else
    {
        int klen = strlen(argv[1]);
        int j = 0;
        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            int key = shift(argv[1][j % klen]);
            //printf("%i\n", key);
            if islower(plaintext[i])
            {
                printf("%c", (((plaintext[i] + key - 97) % 26) + 97));
                j++;
            }
            else if isupper(plaintext[i])
            {
                printf("%c", (((plaintext[i] + key - 65) % 26) + 65));
                j++;
            }
            else
            {
                printf("%c", plaintext[i]);
            }
        }
        printf("\n");
    }
}

int shift(char c)
{
    int number = 0;
    if islower(c)
    {
        number = c - 97;
    }
    else if isupper(c)
    {
        number = c - 65;
    }
    return number;
}
