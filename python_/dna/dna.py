import csv
import sys


def main():

    # Ensure correct usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py database.csv sequence.txt")

    # Read database file into a variable
    database = open(sys.argv[1], "r")
    reader = csv.reader(database)
    titles = next(reader)
    # Read DNA sequence file into a variable
    file = open(sys.argv[2], "r")
    read_file = file.read()

    # Find longest match of each STR in DNA sequence
    slist = []
    for i in titles:
        if not i == "name":
            match = longest_match(read_file, i)
            slist.append(match)
    for s, i in enumerate(slist):
        slist[s] = str(slist[s])

    # Check database for matching profiles
    for row in reader:
        check = []
        check = list(row)
        if check[1:] == slist:
            print(check[0])
            return 0
    print("No Match")
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


main()
