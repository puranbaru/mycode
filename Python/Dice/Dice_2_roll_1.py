import random

#########################
# ROLL_DICE
#########################
def roll_dice():
    return random.randint(1, 6) + random.randint(1, 6)

#########################
# MAIN
#########################
def main():
    total_iterations = int(input("Enter the number of times to roll the dice: "))

    # Create individual variables to capture the counts
    count_2 = count_3 = count_4 = count_5 = count_6 = count_7 = count_8 = count_9 = count_10 = count_11 = count_12 = 0

    # Loop through each iteration and roll the dice
    for _ in range(total_iterations):
        roll = roll_dice()

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
    print("Number   Rolls    Percent")
    print(f"    2 {count_2:6d}      {count_2 / total_iterations * 100:.2f}%")
    print(f"    3 {count_3:6d}      {count_3 / total_iterations * 100:.2f}%")
    print(f"    4 {count_4:6d}      {count_4 / total_iterations * 100:.2f}%")
    print(f"    5 {count_5:6d}      {count_5 / total_iterations * 100:.2f}%")
    print(f"    6 {count_6:6d}      {count_6 / total_iterations * 100:.2f}%")
    print(f"    7 {count_7:6d}      {count_7 / total_iterations * 100:.2f}%")
    print(f"    8 {count_8:6d}      {count_8 / total_iterations * 100:.2f}%")
    print(f"    9 {count_9:6d}      {count_9 / total_iterations * 100:.2f}%")
    print(f"   10 {count_10:6d}      {count_10 / total_iterations * 100:.2f}%")
    print(f"   11 {count_11:6d}      {count_11 / total_iterations * 100:.2f}%")
    print(f"   12 {count_12:6d}      {count_12 / total_iterations * 100:.2f}%")


main()
