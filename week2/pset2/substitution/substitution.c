#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Function Hoisting
bool repeated(string standard);
bool is_alpha(string standard);
string substitute(string cipher, string text);

// Main Function
int main(int argc, string argv[])
{
    string argument = argv[1];

    // Checking for an argumnet
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (argc == 2)
    {
        // Argument validation
        if (strlen(argument) < 26)
        {
            printf("Key must be 26 character long\n");
            return 1;
        }
        else if (!is_alpha(argument))
        {
            printf("Key must only contain alphabetic characters\n");
            return 1;
        }
        else if (repeated(argument))
        {
            printf("Key cannot contain repeated letters.\n");
            return 1;
        }
        else
        {
            string plaintxt = get_string("plaintext: ");
            string ciphertxt = substitute(argument, plaintxt);
            printf("ciphertext: %s\n", ciphertxt);
        }
    }
}

// Function for checking if any letter has been repeated
bool repeated(string standard)
{
    bool repeat = false;
    int n = strlen(standard);
    for (int i = 0; i < n; i++)
    {
        char temp = standard[i];
        standard[i] = ' ';
        for (int j = 0; j < n; j++)
        {
            if (temp == standard[j])
            {
                repeat = true;
                break;
            }
        }
        standard[i] = temp;
    }
    return repeat;
}

// Function for checking if every letter is alphabetical
bool is_alpha(string standard)
{
    bool alpha = true;
    for (int i = 0, n = strlen(standard); i < n; i++)
    {
        if (!isalpha(standard[i]))
        {
            alpha = false;
            break;
        }
    }
    return alpha;
}

// Function for performing the substitution
string substitute(string cipher, string text)
{
    int len = strlen(text);
    string encrypt = text;

    for (int i = 0; i < len; i++)
    {
        int text_index = 0;
        if (isalpha(text[i]))
        {
            if (islower(text[i]))
            {
                text_index = text[i] - 'a';
                encrypt[i] = tolower(cipher[text_index]);
            }
            else if (isupper(text[i]))
            {
                text_index = text[i] - 'A';
                encrypt[i] = toupper(cipher[text_index]);
            }
            printf("%i\n",text_index);
        }

        else if (isspace(text[i]))
        {
            encrypt[i] = ' ';
        }
        else
        {
            encrypt[i] = text[i];
        }
    }
    return encrypt;
}
