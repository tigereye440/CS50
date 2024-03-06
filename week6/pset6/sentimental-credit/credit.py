# Main function
def main():
    """This is the main function that calls other functions. It has no arguments and has no return value"""
    credit_card_num, card_num_length = get_card_info()
    checksum_val = check_sum(credit_card_num)
    card_start_digits = get_first_2_digits(credit_card_num)
    card_type = type_of_card(card_start_digits, card_num_length)

    if (checksum_val and (card_type is not None)):
        print(card_type)
    else:
        print("INVALID")


# Get the card information such as card number and number length
def get_card_info():
    """
    This function retrieves information about the card such as the credit card number and the length of the number
    It returns these two values.
    """
    while True:
        credit_card = input("Enter your credit card number: ")
        if (credit_card.isdigit()):
            return int(credit_card), len(credit_card)


def check_sum(card_num):
    """
     Determines the checksum of the card to make sure it is a valid card. It has one argument, the card_num
     which is the card number and return true if the checksum and valid and vice versa
     """
    odd_pos = 0
    even_pos = 0
    first = 0
    last = 0
    even_num = 0
    counter = 1

    while (card_num != 0):
        if (counter % 2 == 0):
            even_num = (card_num % 10) * 2

            if even_num > 9:
                first = int(even_num % 10)
                last = int(even_num / 10)
                even_pos += (first + last)

            else:
                even_pos += even_num
            card_num = int(card_num / 10)

        else:
            odd_pos += card_num % 10
            card_num = int(card_num / 10)
        counter += 1

    if (counter % 2 == 0):
        temp = odd_pos
        odd_pos = even_pos
        even_pos = temp

    return (even_pos + odd_pos) % 10 == 0


# Determine the type of card
def type_of_card(starting_digit, length):
    """
    This function determines the type of card (AMEX, MASTERCARD or VISA). It has one parameter, the length
    of the card number and the first 2 digits of the card number. It returns a string which is the type of card
    """
    amex = [34, 37]
    mastercard = [51, 52, 53, 54, 55]

    if (length == 15 and starting_digit in amex):
        return "AMEX"

    elif (length == 16 and starting_digit in mastercard):
        return "MASTERCARD"

    elif ((length == 13 or length == 16) and (int(starting_digit / 10) == 4)):
        return "VISA"
    else:
        return


# Get the first 2 digits of the card number
def get_first_2_digits(card_num):
    """This function extracts the first two digits from the card number. It takes one argument and returns a double digit integer"""
    string_card_num = str(card_num)
    first_2_digits = string_card_num[:2]
    # print(f"first_2_digits: {first_2_digits}")
    return int(first_2_digits)

if __name__ == "__main__":
    main()
