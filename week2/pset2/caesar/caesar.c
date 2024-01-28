
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining function prototypes
bool is_digit(string key);
string encrypt(string plaintext, int key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caeser key\n");
        return 1;
    }
    else if (argc == 2)
    {
        string key = argv[1];
        if (!is_digit(key))
        {
            printf("Usage ./caesar key\n");
            return 1;
        }
        else
        {
            string plaintext = get_string("plaintext:  ");
            int encryption_key = atoi(key);
            string ciphertext = encrypt(plaintext, encryption_key);
            printf("Ciphertext: %s\n", ciphertext);
        }
        return 0;
    }
}

// Function for checking if every character of argument is a digit
bool is_digit(string key)
{
    bool isNumber = true;
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isdigit(key[i]))
        {
            isNumber = false;
            break;
        }
    }
    return isNumber;
}

// Function for performing the substitution
string encrypt(string plaintext, int key)
{
    int len = strlen(plaintext);
    string encrypted = plaintext;

    for (int i = 0; i < len; i++)
    {
        int text_index = 0;
        if (isalpha(plaintext[i]))
        {
            if (islower(plaintext[i]))
            {
                text_index = plaintext[i] - 'a';
                encrypted[i] = ((text_index + key) % 26) + 'a';
            }
            else if (isupper(plaintext[i]))
            {
                text_index = plaintext[i] - 'A';
                encrypted[i] = ((text_index + key) % 26) + 'A';
            }
        }
        else if (isspace(plaintext[i]))
        {
            encrypted[i] = ' ';
        }
        else
        {
            encrypted[i] = plaintext[i];
        }
    }
    return encrypted;
}
