# Import the get_int function from cs50 python module
from cs50 import get_int

# Main function
def main():
    """This is the main function that calls other functions. It has no parameters and return values"""
    height = valid_height()
    build_pyramid(height)

# Gets the valid height for the pyramid
def valid_height():
    """
    This function accepts an input from the user and makes sure it is valid. It has no parameters.
    It return an integer, height which is the height of the pyramid.
    """
    while True:
        height = get_int("Height: ")
        if 0 < height <= 8:
            return height

# Prints "#" a specified number of times
def print_hash(hash):
    """
    This function prints "#" without a new-line a specified number of times. It has one parameter,
    an integer called hash. It has no return value.
    """
    for i in range(hash):
        print("#", end="")

# This function prints spaces("  ") a specified number of times.
def print_spaces(spaces):
    """
    This function prints spaces without a new-line  a specified number of times. It has one parameter,
    an integer called spaces. It has no return value.
    """
    for i in range(spaces):
        print(" ", end="")

# This function prints out a pyramid of specified height
def build_pyramid(height):
    """
    This function  builds a pyramid of a specific height aligned to the left. It has one parameter, 
    an integer called height and has no return value.
    """
    for i in range(height):
        space = height - (i + 1)
        hash = i + 1
        print_spaces(space)
        print_hash(hash)
        print()


# Calling the main function
if __name__ == "__main__":
    main()
