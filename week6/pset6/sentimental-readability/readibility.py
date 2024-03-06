# Importing the string module
import string


# Main function
def main():
    """Main function of the code"""
    text = input('Enter a text to analyze: ')
    index = calculate_index(text)
    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")


# Count the number of letters and words in the text
def count_letters_words(text):
    """
    This function counts the number of words and letters in the given text and
    return the two variables. It takesw in one argument, string called text
    """
    words = text.split()
    num_words = 0
    num_letters = 0
    punctuation = string.punctuation
    for word in words:
        num_words += 1
        for letter in word:
            if letter in punctuation:
                pass
            else:
                num_letters += 1
    return num_letters, num_words


# Count the number of sentences in the text
def count_sentences(text):
    """
    This function counts the number of sentences present in the given sentence.
    It takes one argument, string called text and return an integer called sentences
    """
    punctuations = ['.', '?', '!']
    sentences = 0
    for char in text:
        if char in punctuations:
            sentences += 1
    return sentences


# Determine the type of grade one is in
def calculate_index(text):
    """
    This functions uses the Coleman-Liau index to determine the type of grade a given text is in.
    It takes one argument called text which is a string and calculates the Coleman-Liau index and
    then returns the index which is a string.
    """
    letters, words = count_letters_words(text)
    average_letters = letters / words * 100
    average_sentences = count_sentences(text) / words * 100
    index = round(0.0588 * average_letters - 0.296 * average_sentences - 15.8)
    return index


if __name__ == "__main__":
    main()
