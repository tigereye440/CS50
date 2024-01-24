#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Hoisting functions
string type_card(int starting_digit, int length);
int getFirst2Digits(long card_num);
int checksum(long card_num);

// Main code
int main(void)
{
    long credit_card = get_long("Enter credit card number: ");
    int checksum_val = checksum(credit_card);
    int card_num_length = floor(log10(credit_card)) + 1;
    int card_start_digits = getFirst2Digits(credit_card);
    bool valid = false;
    string card_type = type_card(card_start_digits, card_num_length);

    if (checksum_val % 10 == 0)
    {
        printf("%s\n", card_type);
    }
    else
    {
        printf("INVALID\n");
    }
}

// Calculate the checksum for the provided credit card
int checksum(long card_num)
{
    int odd_pos, even_pos, first, last;
    odd_pos = 0;
    even_pos = 0;
    int even_num = 0;
    int counter = 1;

    while (card_num != 0)
    {
        if (counter % 2 == 0)
        {
            even_num = (card_num % 10) * 2;
            if (even_num > 9)
            {
                first = even_num % 10;
                last = even_num / 10;
                even_pos += (first + last);
            }
            else
            {
                even_pos += even_num;
            }
            card_num /= 10;
        }
        else
        {
            odd_pos += card_num % 10;
            card_num /= 10;
        }
        counter++;
    }

    if (counter % 2 == 0)
    {
        int temp = odd_pos;
        odd_pos = even_pos;
        even_pos = temp;
    }
    return (even_pos + odd_pos);
}

// Determine the type of credit card
string type_card(int starting_digit, int length)
{
    if (length == 15 && (starting_digit == 34 || starting_digit == 37))
    {
        return "AMEX";
    }
    else if (length == 16 &&
             (starting_digit == 51 || starting_digit == 52 || starting_digit == 53 || starting_digit == 54 || starting_digit == 55))
    {
        return "MASTERCARD";
    }
    else if ((length == 13 || length == 16) && (starting_digit >= 40 && starting_digit < 50))
    {
        return "VISA";
    }
    else
    {
        return "INVALID";
    }
}

// get first two digits of card number
int getFirst2Digits(long card_num)
{
    long first_2_digits = card_num;
    while (first_2_digits >= 100)
    {
        first_2_digits /= 10;
    }
    return first_2_digits;
}
