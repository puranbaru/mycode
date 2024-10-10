import random
import os


#####################################################
# #Parts 1
#####################################################
from random import randint

def win_condition(player_score, computer_score):
        if player_score >= 100 or computer_score >= 100:
                return True
        return False

# Computer player logic
def computer_play(computer_score):
        turn_total = 0
        while turn_total < 20 and turn_total + computer_score < 100:
                roll = randint(1, 6)
                print(f'Roll: {roll}')
                if roll == 1:
                        print("Pig !!!")
                        return 0
                turn_total += roll
        return turn_total

# Human player logic
def human_play(player_score):
        turn_total = 0
        while turn_total + player_score < 100:
                print(f'Turn total: {turn_total}       \nRoll/Hold?')
                round_input = input()
                # Enter pressing will mean empty string
                if round_input == "":
                        roll = randint(1, 6)
                        print(f'Roll: {roll}')
                        if roll == 1:
                                print("Pig !!!")
                                return 0
                        turn_total += roll
                else:
                        break
        print(f'Turn Total: {turn_total}')
        return turn_total

def roll_to_20():
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
                  turn_score = human_play(player_score)
                  player_score += turn_score
                  print(f'New Score: {player_score}')
                  turn = computer_id
          else:
                  turn_score = computer_play(computer_score)
                  computer_score += turn_score
                  print(f'New Score: {computer_score}')
                  turn = player_id
  if player_score >= 100:
          print(f'Player {player_id} has won the game')
  else:
          print(f'Player {computer_id} has won the game')


#####################################################
# #Parts 2-3
# #For Part 2, input 20 when prompted
#####################################################
def roll():
   return random.randint(1,6)
  
def autoPig_123(holdAt):
  total = 0
  done = False
  while total < holdAt and not done:
    result = roll()
    if result == 1:
      total = 0
      done = True
    else:
      total += result  
    #print("Turn Total:", total)
  return total

def holdAtNumber_123(trials, holdAt):
  outcomes = {}
  
  for _ in range(trials):
    turnTotal = autoPig_123(holdAt)
    if turnTotal in outcomes:
      outcomes[turnTotal] +=1
    else:
      outcomes[turnTotal] = 1
    #print("outcomes", outcomes)

  print("Score\tEstimated Probability")
  for turnTotal in sorted(outcomes):
    print(turnTotal, "\t\t",  outcomes[turnTotal]/trials)


def simulate_hold_at_x_turns():
  holdAt = int(input("At which number do you want to hold?\n"))

  trials = int(input("\nHow many Hold-At-" + str(holdAt) + " Simulations?\n"))
  holdAtNumber_123(trials, holdAt)


#####################################################
## Part 4
#####################################################


def Hold20orGoal(score):
  total = 0
  done = False
  while total < 20 and not done:
    result = roll()
    print("Roll: ",result)
    if result == 1:
      total = 0
      done = True
    else:
      total += result  
  print("Turn Total:", total)
  return total
  
def simulate_hold_at_20_or_goal_turn(score):
  totalscore = 0
  # score = int(input("Score? "))
  total = Hold20orGoal(score)
  totalscore = total + score
  print("New Score: ",totalscore)
  
#####################################################
## Problem 5
## Cumulative Score + TurnTotal >=100 
#####################################################


  
def Hold20orGoal_game(score):
  total = 0
  done = False
  while total < 20 and not done:
    result = roll()
    print("Roll: ",result)
    if result == 1:
      total = 0
      done = True
    else:
      total += result  
  print("Turn Total:", total)
  return total
  
def simulate_hold_at_20_or_goal_game():
  totalscore = 0
  score=0
  #score = int(input("Score? "))
  while totalscore <= 100:
    total = Hold20orGoal_game(score)
    totalscore += total
    print("New Score: ",totalscore)
  
#####################################################
## Problem 6
## Cumulative Score + TurnTotal >=100 
## Probability of number of turns
#####################################################

def Hold20orGoal_avg(score):
  total = 0
  NumberOfRolls = 0
  #totalScore = 0
  done = False
  while total < 20 and not done:
    result = roll()
    NumberOfRolls +=1
    #print("Roll: ",result)
    if result == 1:
      total = 0
      done = True
    else:
      total += result
      #totalScore += total
  #print("Number of Rolls:", NumberOfRolls)
  return total, NumberOfRolls

def newScore_avg(trials):
  NumberOfRolls = 0
  totalscore = 0
  while totalscore <= 100:
    total, NumberOfRolls = Hold20orGoal_avg(trials)
    NumberOfRolls += 1
    #print("Number of rolls: ",NumberOfRolls)
    totalscore += total
  return NumberOfRolls

def holdAtNumber_avg_pig_turns(trials, holdAt):
  numberRolls = 0
  for i in range(trials):
    numberRolls += newScore_avg(trials)
  print( "Average Turns: ", numberRolls/trials)

def average_pig_turns(games):
  totalscore = 0
  score=0
  # score = int(input("Score? "))
  # games = int(input("Games? "))
  holdAtNumber_avg_pig_turns(games, 20)


#####################################################
## Problem 7
#####################################################

  
def turnScore():
  done = False
  total = 0
  while total < 20 and not done:
    result = roll()
    print("Roll: ",result)
    if result == 1:
      total = 0
      done = True
    else:
      total += result
  return total

def Playersturns():
  player1score = 0
  player2score = 0
  while player1score < 100 and player2score <100:
    print("It's player 1's turn.")
    turnTotal = turnScore()
    player1score += turnTotal
    print("Turn score:", turnTotal)
    print("New Score:", player1score)

    print("It's player 2's turn.")
    turnTotal = turnScore()
    player2score += turnTotal
    print("Turn score:", turnTotal)
    print("New Score:", player2score)

  return player1score, player2score

def two_player_pig():
  os.system('clear')
  print("Player 1 score: 0")
  print("Player 2 score: 0")
  player1, player2 = Playersturns()

  print("Player 1 score: ", player1)
  print("Player 2 score: ", player2)

#####################################################
## Problem 8
#####################################################

  
def turnScore_8(playerName):
  done = False
  total = 0
  myList = ["","h"]
  
  while total < 20 and not done:
    result = 0
    if playerName == "me" :
      rh = input("Roll/Hold?")
    else:
      rh = random.choice(myList)
    if rh == "":
      result = roll()
      print("Roll: ",result)
    else:
      done = True
    if result == 1:
      total = 0
      done = True
    else:
      total += result
  return total

def pig_game():
  os.system('clear')
  player1score = 0
  player2score = 0
  turnTotal = 0
  playernum = random.randint(1,2)
  print("You will be player ", playernum)
  print("Enter nothing to roll; enter anything to hold.")
  print("Player 1 score: 0")
  print("Player 2 score: 0")
  if playernum == 1:
    player1 = "me"
    player2 = "computer"
  elif playernum == 2:
    player1 = "computer"
    player2 = "me"

  while player1score < 100 and player2score <100:
    #Player 1
    print("\nIt's player 1's turn")

    turnTotal = turnScore_8(player1)
    player1score += turnTotal
    
    print("Turn score:", turnTotal)
    print("New Score:", player1score)

    #Player 2
    print("\nIt's player 2's turn")
    turnTotal = turnScore_8(player2)
    player2score += turnTotal

    print("Turn score:", turnTotal)
    print("New Score:", player2score)

  #player1, player2 = Playersturns()
  print("Player 1 score: ", player1score)
  print("Player 2 score: ", player2score)

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
        turn_total = roll_to_20()
        print(f'Turn Total: {turn_total}')
    elif choice == "2" or choice == "3":
        # Hold-at-20 Outcomes
        try:
            num_simulations = int(input("Enter the number of turns to simulate: "))
            simulate_hold_at_x_turns()
        except ValueError:
            print("Invalid input. Please enter a valid integer.")
    # elif choice == "3":
    #     # Hold-at-X Outcomes
    #     try:
    #         hold_value = int(input("Enter the hold value: "))
    #         num_simulations = int(input("Enter the number of turns to simulate: "))
    #         simulate_hold_at_x_turns(num_simulations, hold_value)
    #     except ValueError:
    #         print("Invalid input. Please enter valid integers.")
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
            average_pig_turns(num_games)
        except ValueError:
            print("Invalid input. Please enter a valid integer.")
    elif choice == "7":
        # Two-Player Pig
        two_player_pig()
    elif choice == "8":
        # Pig Game
        pig_game()
    else:
        print("Invalid choice. Please enter either '1', '2', '3', '4', '5', '6', '7', or '8'.")

if __name__ == "__main__":
    main()
