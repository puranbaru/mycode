import random

#########################
# CALCULATE_EXPECTED
#########################
def calculate_expected():
    # Create individual variables for expected values
    expected_2 = expected_3 = expected_4 = expected_5 = expected_6 = expected_7 = expected_8 = expected_9 = expected_10 = expected_11 = expected_12 = 0

    # Get the probabilities of getting each value.
    # For a 12-sided die, each side has an equal chance of landing face up.
    expected_2 = 1/12 * 100
    expected_3 = 1/12 * 100
    expected_4 = 1/12 * 100
    expected_5 = 1/12 * 100
    expected_6 = 1/12 * 100
    expected_7 = 1/12 * 100
    expected_8 = 1/12 * 100
    expected_9 = 1/12 * 100
    expected_10 = 1/12 * 100
    expected_11 = 1/12 * 100
    expected_12 = 1/12 * 100

    return expected_2, expected_3, expected_4, expected_5, expected_6, expected_7, expected_8, expected_9, expected_10, expected_11, expected_12

#########################
# MAIN
#########################
def main():
    # Get the number of iterations to roll the dice
    total_iterations = int(input("Enter the number of times to roll: "))

    # Create individual variables to capture the counts
    count_2 = count_3 = count_4 = count_5 = count_6 = count_7 = count_8 = count_9 = count_10 = count_11 = count_12 = 0

    # Loop through each iteration and roll the dice
    for _ in range(total_iterations):
        ## To roll the dice twice
        roll = random.randint(2, 12) 

        # Update counts based on the rolled number
        if roll == 2:
            count_2 += 1
        elif roll == 3:
            count_3 += 1
        elif roll == 4:
            count_4 += 1
        elif roll == 5:
            count_5 += 1
        elif roll == 6:
            count_6 += 1
        elif roll == 7:
            count_7 += 1
        elif roll == 8:
            count_8 += 1
        elif roll == 9:
            count_9 += 1
        elif roll == 10:
            count_10 += 1
        elif roll == 11:
            count_11 += 1
        elif roll == 12:
            count_12 += 1

    # Print the results 
    print("Total iterations: ", total_iterations)
    print("Number   Rolls    Percent  Expected  Difference")

    # Define expected values
    expected_values = calculate_expected()
    
    # Loop through the individual variables and compare with expected values
    print(f"    2 {count_2:6d}       {count_2 / total_iterations * 100:.2f}%    {expected_values[0]:.2f}% \t {count_2 - expected_values[0]:.2f}%")
    print(f"    3 {count_3:6d}       {count_3 / total_iterations * 100:.2f}%    {expected_values[1]:.2f}% \t {count_3 - expected_values[1]:.2f}%")
    print(f"    4 {count_4:6d}       {count_4 / total_iterations * 100:.2f}%    {expected_values[2]:.2f}% \t {count_4 - expected_values[2]:.2f}%")
    print(f"    5 {count_5:6d}       {count_5 / total_iterations * 100:.2f}%    {expected_values[3]:.2f}% \t {count_5 - expected_values[3]:.2f}%")
    print(f"    6 {count_6:6d}       {count_6 / total_iterations * 100:.2f}%    {expected_values[4]:.2f}% \t {count_6 - expected_values[4]:.2f}%")
    print(f"    7 {count_7:6d}       {count_7 / total_iterations * 100:.2f}%    {expected_values[5]:.2f}% \t {count_7 - expected_values[5]:.2f}%")
    print(f"    8 {count_8:6d}       {count_8 / total_iterations * 100:.2f}%    {expected_values[6]:.2f}% \t {count_8 - expected_values[6]:.2f}%")
    print(f"    9 {count_9:6d}       {count_9 / total_iterations * 100:.2f}%    {expected_values[7]:.2f}% \t {count_9 - expected_values[7]:.2f}%")
    print(f"   10 {count_10:6d}       {count_10 / total_iterations * 100:.2f}%    {expected_values[8]:.2f}% \t {count_10 - expected_values[8]:.2f}%")
    print(f"   11 {count_11:6d}       {count_11 / total_iterations * 100:.2f}%    {expected_values[9]:.2f}% \t {count_11 - expected_values[9]:.2f}%")
    print(f"   12 {count_12:6d}       {count_12 / total_iterations * 100:.2f}%    {expected_values[10]:.2f}% \t {count_12 - expected_values[10]:.2f}%")


main()

