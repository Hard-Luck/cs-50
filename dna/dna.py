import csv
import sys


def main():

    # Ensure correct usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py database.csv sequence.txt")

    # Read database file into a variable
    reader = csv.reader(sys.argv[1])
    titles = next(reader)
    # Read DNA sequence file into a variable
    file = f"{sys.argv[2]}"

    # Find longest match of each STR in DNA sequence
    strs_list = []
    with open(file, "r") as f:
        for i in range(1, len(titles)):
            match = longest_match(titles[i],file)
            strs_list.append(match)


            # Check database for matching profiles
            for row in reader:
                if row == strs_list[1:]:
                    print(row[0])
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
