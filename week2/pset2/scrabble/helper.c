#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
    string name = get_string("Name: ");

    for (int i = 0; i < strlen(name); i++)
    {
        if (isalnum(name[i]))
        {
            printf("Valid character\n");
        }
        else
        {
            printf("Invalid character\n");
        }
    }
}
