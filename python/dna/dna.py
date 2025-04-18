import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Missing proper CLA: .csv and .txt")
        sys.exit(1)

    # TODO: Read database file into a variable
    dna_db = []
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        for row in reader:
            dna_db.append(row)
    '''
    # Print dna_db
    print()
    print("DNA DB:")
    for row in dna_db:
        print(row)
    '''
    # TODO: Read DNA sequence file into a variable
    dna_seq = ""
    with open(sys.argv[2]) as file:
        reader = csv.reader(file)
        for row in reader:
            dna_seq = row[0]

    # Print DNA sequence
    # print(f"DNA sequence: {dna_seq}")

    # TODO: Find longest match of each STR in DNA sequence
    str = dict()
    for i, key in enumerate(dna_db[0]):
        if i == 0:
            continue
        # print(f"DB key {i}: {key}")
        str[key] = longest_match(dna_seq, key)
    # print(str)

    # TODO: Check database for matching profiles
    for row in dna_db:

        str_comp_1 = ""
        for i, value in enumerate(row.values()):
            if i == 0:
                continue
            str_comp_1 += f"{value}"
        # print()
        # print(str_comp_1)

        str_comp_2 = ""
        for key in str:
            str_comp_2 += f"{str[key]}"
        # print(str_comp_2)

        if str_comp_1 == str_comp_2:
            return print(row["name"])

    print("No match")


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
