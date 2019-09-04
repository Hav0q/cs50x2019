#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = get_int("Height: ");
    if (height>0 && height<9)
    {
        for (int x=height-1; x>=0; x--)
        {
            for (int y=0; y<x; y++)
            {
                printf(" ");
            }   
            for (int z=0; z<height-x; z++)
            {
                 printf("#");
            }
            printf("\n");
        }
    }
}
