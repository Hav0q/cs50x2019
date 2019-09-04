#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 0;
    do
    height = get_int("Height:");
    while(height<1 || height>8);
    if (height>0 && height<9)
    {
        for (int x=height; x>0; x--)
        {
            for (int y=0; y<x-1; y++)
            {
                printf(" ");
            }
            for (int y=0; y<=height-x; y++)
            {
                printf("#");
            }
            printf("  ");
            for (int z=0; z<=height-x; z++)
            {
                printf("#");
            }
            printf("\n");
        }
    }
}
