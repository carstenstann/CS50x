#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    // Obtain height of pyramid
    do
    {
        h = get_int("%s", "Height: ");
    }
    while (h < 1 || h > 8);
    
    // Print pyramid
    for (int i = 0; i < h; i++)
    {
        // Right align pyrmaid blocks using spaces
        for (int s = i; s < h - 1; s++)
        {
            printf(" ");
        }
        // Pringt pyrmaid blocks
        for (int b = 0; b < i + 1; b++)
        {
            printf("#");
        }
        printf("\n");
    }
}
