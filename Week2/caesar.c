#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    bool valid = 1;
    int key = 0;
    string plaintext = "";
    string ciphertext = "";
    int c = 0;
    
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        key = atoi(argv[1]);
    }
    
    if (key > 0 && strlen(argv[1]) > 0)
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (!isdigit(argv[1][i]))
            {
                valid = 0;
            }
        }
    }
    
    if (valid == 1)
    {
        printf("Success\n");
        plaintext = get_string("plaintext: ");
        printf("ciphertext: ");
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            if islower(plaintext[i])
            {
                printf("%c", (((plaintext[i] + key) - 97) % 26) + 97);
            }
            else if isupper(plaintext[i])
            {
                printf("%c", (((plaintext[i] + key) - 65) % 26) + 65);
            }
            else
            {
                printf("%c", plaintext[i]);
            }
        }
        printf("\n");
    }
    else if (valid == 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //printf("%i\n", key);
}
