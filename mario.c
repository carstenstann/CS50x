#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    do
    {
        h = get_int("%s", "Height: ");
    }
    while (h < 1 || h > 8 );

    for (int i = 0; i < h; i++)
    {
        for (int j = i; j < h - 1; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}
