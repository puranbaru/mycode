import random

#########################
# ROLL_DICE
#########################
def roll_dice():
    return random.randint(1, 6) + random.randint(1, 6)

#########################
# CALCULATE_EXPECTED
#########################
def calculate_expected():
    # Create individual variables to capture the expected values
    expected_2 = expected_3 = expected_4 = expected_5 = expected_6 = expected_7 = expected_8 = expected_9 = expected_10 = expected_11 = expected_12 = 0

    # Calculate the sums of rolls and populate expected
    for die1 in range(1, 7):
        for die2 in range(1, 7):
            roll_sum = die1 + die2
            if roll_sum == 2:
                expected_2 += 1
            elif roll_sum == 3:
                expected_3 += 1
            elif roll_sum == 4:
                expected_4 += 1
            elif roll_sum == 5:
                expected_5 += 1
            elif roll_sum == 6:
                expected_6 += 1
            elif roll_sum == 7:
                expected_7 += 1
            elif roll_sum == 8:
                expected_8 += 1
            elif roll_sum == 9:
                expected_9 += 1
            elif roll_sum == 10:
                expected_10 += 1
            elif roll_sum == 11:
                expected_11 += 1
            elif roll_sum == 12:
                expected_12 += 1
    
    # Now divide total expected sum values by all possibilities
    expected_2 /= 36
    expected_3 /= 36
    expected_4 /= 36
    expected_5 /= 36
    expected_6 /= 36
    expected_7 /= 36
    expected_8 /= 36
    expected_9 /= 36
    expected_10 /= 36
    expected_11 /= 36
    expected_12 /= 36

    return expected_2, expected_3, expected_4, expected_5, expected_6, expected_7, expected_8, expected_9, expected_10, expected_11, expected_12

#########################
# MAIN
#########################
def main():
    total_iterations = int(input("Enter the number of times to roll the dice: "))
    rolls_count = {}
    expected_values = calculate_expected()

    print("total iterations:", total_iterations)
    print("number   rolls percent   expected    difference")

    for roll_sum, count in enumerate(rolls_count.values(), start=2):
        percentage = count / total_iterations * 100
        exp_value = expected_values[roll_sum - 2] * 100
        difference = percentage - exp_value
        print(f"{roll_sum:6d} {count:4d}      {percentage:.2f}%    {exp_value:.2f}%    {difference:.2f}%")


main()
