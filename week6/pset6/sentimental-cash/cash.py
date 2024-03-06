# Import the get_float function from the cs50 python module
from cs50 import get_float

# Define globals
QUARTERS = 0.25
DIMES = 0.10
NICKELS = 0.05
PENNIES = 0.01

# Main function
def main():
  """This is the main function of the code. It has no parameters and no return value.  """
    print(coins(valid_input()))

# This function gets an input from the user and makes sure the input is valid
def valid_input():
  """
  This function gets the input that is assigned to the change_owed variable. It has 
  no parameters and returns a floating point value called change_owed
  """
    while True:
        change_owed = get_float("Enter your change in cents: ")
        if (change_owed > 0):
            return change_owed

# This function calculate the number of coins a user will get
def coins(change):
  """
  This function calculates the number of change a user will get based on the change supplied. 
  It has one parameter, change, which is supplied by calling the valid_input() function. It 
  returns an integer called coins which is the number of coins the user will get.
  """
    remainder = 0
    quarters = change / QUARTERS
    remainder = round(change - (int(quarters) * QUARTERS), 2)
    dimes = remainder / DIMES
    remainder = round(remainder - (int(dimes) * DIMES), 2)
    nickels = remainder / NICKELS
    remainder = round(remainder - (int(nickels) * NICKELS), 2)
    pennies = remainder / PENNIES
    remainder = round(remainder - (int(pennies) * PENNIES), 2)

    coins = int(quarters) + int(dimes) + int(nickels) + int(pennies)
    return coins


if __name__ == "__main__":
    # Calling the main function
    main()
