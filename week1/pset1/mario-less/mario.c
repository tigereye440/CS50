#include <cs50.h>
#include <stdio.h>

void print_hash(int hash);

int main(void)
{
    int height = 0;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    for (int i = 0; i < height; i++)
    {
        int space = height - i;
        for (int j = 1; j < space; j++)
        {
            printf(" ");
        }
        int hash = height - space;
        print_hash(hash);
        printf("\n");
    }
}

void print_hash(int hash)
{
    for (int k = 0; k <= hash; k++)
    {
        printf("#");
    }
}
