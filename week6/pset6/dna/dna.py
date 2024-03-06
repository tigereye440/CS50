import csv
import sys


def main():

    # TODO: Check for command-line usage
    if (len(sys.argv) != 3):
        print('Usage: python dna.py [database_file] [sequence_file]')
        return

    # TODO: Read database file into a variable
    rows = {}
    with open(sys.argv[1]) as file:
        database = csv.DictReader(file)
        for row in database:
            name = row['name']
            sequences = {key: int(value) for key, value in row.items() if key != 'name'}
            rows[name] = sequences

    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2], encoding='utf-8') as f:
        sequence = f.read()

    # TODO: Find longest match of each STR in DNA sequence
    strs = database.fieldnames[1:]
    matches = {}
    for str in strs:
        matches.update({str: (longest_match(sequence, str))})

    # TODO: Check database for matching profiles
    persons = rows.keys()

    for person in persons:
        value = rows.get(person)
        if (value == matches):
            print(person)
            return
    else:
        print('No match')
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


if __name__ == "__main__":
    main()
