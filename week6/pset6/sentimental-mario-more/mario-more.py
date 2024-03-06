# Importing the get_int function from cs50 python module
from cs50 import get_int


# Main function that calls all other functions
def main():
    """This function is the function that calls all othr functions. It has no parameters or returbn values."""
    height = valid_height()
    build_pyramid(height)


# This function gets a valid height from the user
def valid_height():
    """This function get a valid height from the user. It has no parameters and returns an integer called height"""
    while True:
        height = get_int("Height: ")
        if 0 < height <= 8:
            return height


# Prints "#" a specified number of times
def print_hash(hash):
    """
    This function prints "#" a specified number of times with no new-line. It has one parameter, an integer called
    hash and it has no return value.
    """
    for i in range(hash):
        print("#", end="")


# Prints space("  ") a specified number of times
def print_spaces(spaces):
    """
    This function prints space("  ") a specified number of times with no new-line. It has one parameter, an integer
    called spaces and has no return value
    """
    for i in range(spaces):
        print(" ", end="")


# This function builds two pyramids beside each other as in mario
def build_pyramid(height):
   """
   This function builds two pyramids side-by-side. It has one parameter, an integer called height and has no 
   return value
   """
    for i in range(height):
        space = height - (i + 1)
        hash = i + 1
        print_spaces(space)
        print_hash(hash)
        print("  ", end="")
        print_hash(hash)
        print()


# Calling the main function
if __name__ == "__main__":
       main()
