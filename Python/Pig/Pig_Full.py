from random import randint

def win_condition(player_score, computer_score):
    return player_score >= 100 or computer_score >= 100

def roll_die():
    return randint(1, 6)

def player_turn(player_score):
    turn_total = 0
    while turn_total + player_score < 100:
        print(f'Roll: {roll_die()}')
        print(f'Turn total: {turn_total}        Roll/Hold?')
        round_input = input()
        if not round_input:
            roll = roll_die()
            print(f'Roll: {roll}')
            if roll == 1:
                print("Pig !!!")
                turn_total = 0
                break
            turn_total += roll
        else:
            break

    print(f'Turn Total: {turn_total}')
    return turn_total

def computer_turn(computer_score):
    turn_total = 0
    while turn_total < 20 and turn_total + computer_score < 100:
        roll = roll_die()
        print(f'Roll: {roll}')
        if roll == 1:
            print("Pig !!!")
            return 0
        turn_total += roll

    print(f'Turn Total: {turn_total}')
    return turn_total

def simulate_hold_at_20_or_goal_turn(score):
    turn_total = 0
    while turn_total < 20 and turn_total + score < 100:
        roll = roll_die()
        print(f'Roll: {roll}')
        if roll == 1:
            print("Pig !!!")
            return 0
        turn_total += roll

    print(f'Turn Total: {turn_total}')
    return turn_total

def simulate_hold_at_x_turns(num_simulations, hold_value):
    outcomes = {}
    
    for _ in range(num_simulations):
        turn_total = 0
        while turn_total < hold_value:
            roll = randint(1, 6)
            if roll == 1:
                turn_total = 0
                break
            turn_total += roll

        score = turn_total
        if score not in outcomes:
            outcomes[score] = 0
        outcomes[score] += 1

    print("Hold-at-X turn simulations?")
    print("Score\tEstimated Probability")
    
    total_simulations = sum(outcomes.values())
    sorted_scores = sorted(outcomes.keys())
    
    for score in sorted_scores:
        probability = outcomes[score] / total_simulations
        print(f"{score}\t{probability:.6f}")

# Example usage:
# simulate_hold_at_x_turns(1000000, 20)

def two_player_pig_game():
    player_score = 0
    computer_score = 0
    player_id = randint(1, 2)
    computer_id = 3 - player_id  # Ensure the computer is the other player

    print(f'You will be Player {player_id}')
    print("Enter nothing to roll\nEnter anything to hold")

    while not win_condition(player_score, computer_score):
        print(f'Player 1 score: {player_score}')
        print(f'Player 2 score: {computer_score}')
        print(f'It is Player {player_id}\'s turn')

        if player_id == 1:
            turn_score = player_turn(player_score)
            player_score += turn_score
            print(f'New Score: {player_score}')
            player_id = 2
        else:
            turn_score = computer_turn(computer_score)
            computer_score += turn_score
            print(f'New Score: {computer_score}')
            player_id = 1

    if player_score >= 100:
        print(f'Player 1 has won the game')
    else:
        print(f'Player 2 has won the game')

def pig_game():
    player_id = randint(1, 2)
    if player_id == 1:
        computer_id = 2
    else:
        computer_id = 1

    print(f'You will be Player {player_id}')
    print("Enter nothing to roll\nEnter anything to hold")

    player_score = 0
    computer_score = 0
    turn = 1

    while not win_condition(player_score, computer_score):
        print(f'Player {player_id} score: {player_score}')
        print(f'Player {computer_id} score: {computer_score}')
        print(f'It is Player {turn}\'s turn')

        if turn == player_id:
            turn_score = player_turn(player_score)
            player_score += turn_score
            print(f'New Score: {player_score}')
            turn = computer_id
        else:
            turn_score = computer_turn(computer_score)
            computer_score += turn_score
            print(f'New Score: {computer_score}')
            turn = player_id

    if player_score >= 100:
        print(f'Player {player_id} has won the game')
    else:
        print(f'Player {computer_id} has won the game')

def simulate_hold_at_20_or_goal_game():
    player_score = 0
    turn_total = 0

    while True:
        roll = randint(1, 6)
        print(f'Roll: {roll}')

        if roll == 1:
            print("Pig !!!")
            turn_total = 0
            break

        turn_total += roll
        print(f'Turn total: {turn_total}')

        if turn_total >= 20 or player_score + turn_total >= 100:
            print(f'New score: {player_score + turn_total}')
            break

        decision = input('Roll/Hold? ')
        if decision.lower() == 'h':
            player_score += turn_total
            print(f'New score: {player_score}')
            break

def simulate_average_pig_turns(num_games):
    total_turns = 0

    for _ in range(num_games):
        player_score = 0

        while True:
            turn_total = 0

            while turn_total < 20 and player_score + turn_total < 100:
                roll = randint(1, 6)

                if roll == 1:
                    turn_total = 0
                    break

                turn_total += roll

            player_score += turn_total
            total_turns += 1

            if player_score >= 100:
                break

    average_turns = total_turns / num_games
    print(f"Average turns: {average_turns:.6f}")

# Example usage:
# simulate_average_pig_turns(1000000)


def main():
    print("Choose which part of the game you want to play:")
    print("1. One Automated Turn of Pig")
    print("2. Hold-at-20 Outcomes")
    print("3. Hold-at-X Outcomes")
    print("4. Hold-at-20-or-Goal Turn")
    print("5. Hold-at-20-or-Goal Game")
    print("6. Average Pig Turns")
    print("7. Two-Player Pig")
    print("8. Pig Game")

    choice = input()

    if choice == "1":
        # One Automated Turn of Pig
        turn_total = simulate_hold_at_20_or_goal_turn(0)
        print(f'Turn Total: {turn_total}')
    elif choice == "2":
        # Hold-at-20 Outcomes
        try:
            num_simulations = int(input("Enter the number of turns to simulate: "))
            simulate_hold_at_x_turns(num_simulations, 20)
        except ValueError:
            print("Invalid input. Please enter a valid integer.")
    elif choice == "3":
        # Hold-at-X Outcomes
        try:
            hold_value = int(input("Enter the hold value: "))
            num_simulations = int(input("Enter the number of turns to simulate: "))
            simulate_hold_at_x_turns(num_simulations, hold_value)
        except ValueError:
            print("Invalid input. Please enter valid integers.")
    elif choice == "4":
        # Hold-at-20-or-Goal Turn
        try:
            player_score = int(input("Enter the player's score: "))
            simulate_hold_at_20_or_goal_turn(player_score)
        except ValueError:
            print("Invalid input. Please enter a valid integer.")
    elif choice == "5":
        # Hold-at-20-or-Goal Game
        simulate_hold_at_20_or_goal_game()
    elif choice == "6":
        # Average Pig Turns
        try:
            num_games = int(input("Enter the number of games to simulate: "))
            simulate_average_pig_turns(num_games)
        except ValueError:
            print("Invalid input. Please enter a valid integer.")
    elif choice == "7":
        # Two-Player Pig
        two_player_pig_game()
    elif choice == "8":
        # Pig Game
        pig_game()
    else:
        print("Invalid choice. Please enter either '1', '2', '3', '4', '5', '6', '7', or '8'.")

if __name__ == "__main__":
    main()
