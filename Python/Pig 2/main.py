import random
import os

#####################################################
# #Parts 1-3
# #For Part 2, input 20 when prompted
#####################################################
def roll():
   return random.randint(1,6)
  
def autoPig(holdAt):
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

def holdAtNumber(trials, holdAt):
  outcomes = {}
  
  for _ in range(trials):
    turnTotal = autoPig(holdAt)
    if turnTotal in outcomes:
      outcomes[turnTotal] +=1
    else:
      outcomes[turnTotal] = 1
    #print("outcomes", outcomes)

  print("Score\tEstimated Probability")
  for turnTotal in sorted(outcomes):
    print(turnTotal, "\t\t",  outcomes[turnTotal]/trials)

holdAt = int(input("At which number do you want to hold?\n"))

trials = int(input("\nHow many Hold-At-" + str(holdAt) + " Simulations?\n"))
holdAtNumber(trials, holdAt)

#####################################################
## Part 4
# #####################################################
# totalscore = 0
# score = int(input("Score? "))

# def roll():
#  return random.randint(1,6)

# def Hold20orGoal(score):
#   total = 0
#   done = False
#   while total < 20 and not done:
#     result = roll()
#     print("Roll: ",result)
#     if result == 1:
#       total = 0
#       done = True
#     else:
#       total += result  
#   print("Turn Total:", total)
#   return total
  

# total = Hold20orGoal(score)
# totalscore = total + score
# print("New Score: ",totalscore)
  
#####################################################
## Problem 5
## Cumulative Score + TurnTotal >=100 
#####################################################

totalscore = 0
score=0
#score = int(input("Score? "))

# def roll():
#    return random.randint(1,6)
  
# def Hold20orGoal(score):
#   total = 0
#   done = False
#   while total < 20 and not done:
#     result = roll()
#     print("Roll: ",result)
#     if result == 1:
#       total = 0
#       done = True
#     else:
#       total += result  
#   print("Turn Total:", total)
#   return total
  
# while totalscore <= 100:
#   total = Hold20orGoal(score)
#   totalscore += total
#   print("New Score: ",totalscore)
  
#####################################################
## Problem 6
## Cumulative Score + TurnTotal >=100 
## Probability of number of turns
# #####################################################

# totalscore = 0
# score=0
# score = int(input("Score? "))

# def roll():
#    return random.randint(1,6)
  
# def Hold20orGoal(score):
#   total = 0
#   NumberOfRolls = 0
#   #totalScore = 0
#   done = False
#   while total < 20 and not done:
#     result = roll()
#     NumberOfRolls +=1
#     #print("Roll: ",result)
#     if result == 1:
#       total = 0
#       done = True
#     else:
#       total += result
#       #totalScore += total
#   #print("Number of Rolls:", NumberOfRolls)
#   return total, NumberOfRolls

# games = int(input("Games? "))

# def newScore(trials):
#   NumberOfRolls = 0
#   totalscore = 0
#   while totalscore <= 100:
#     total, NumberOfRolls = Hold20orGoal(trials)
#     NumberOfRolls += 1
#     #print("Number of rolls: ",NumberOfRolls)
#     totalscore += total
#   return NumberOfRolls

# def holdAtNumber(trials, holdAt):
#   numberRolls = 0
#   for i in range(trials):
#     numberRolls += newScore(trials)
#   print( "Average Turns: ", numberRolls/trials)

# holdAtNumber(games, 20)


#####################################################
## Problem 7
# #####################################################
# def roll():
#    return random.randint(1,6)
  
# def turnScore():
#   done = False
#   total = 0
#   while total < 20 and not done:
#     result = roll()
#     print("Roll: ",result)
#     if result == 1:
#       total = 0
#       done = True
#     else:
#       total += result
#   return total

# def Playersturns():
#   player1score = 0
#   player2score = 0
#   while player1score < 100 and player2score <100:
#     print("It's player 1's turn.")
#     turnTotal = turnScore()
#     player1score += turnTotal
#     print("Turn score:", turnTotal)
#     print("New Score:", player1score)

#     print("It's player 2's turn.")
#     turnTotal = turnScore()
#     player2score += turnTotal
#     print("Turn score:", turnTotal)
#     print("New Score:", player2score)

#   return player1score, player2score

# os.system('clear')
# print("Player 1 score: 0")
# print("Player 2 score: 0")
# player1, player2 = Playersturns()

# print("Player 1 score: ", player1)
# print("Player 2 score: ", player2)

#####################################################
## Problem 8
#####################################################
# def roll():
#    return random.randint(1,6)
  
# def turnScore(playerName):
#   done = False
#   total = 0
#   myList = ["","h"]
  
#   while total < 20 and not done:
#     result = 0
#     if playerName == "me" :
#       rh = input("Roll/Hold?")
#     else:
#       rh = random.choice(myList)
#     if rh == "":
#       result = roll()
#       print("Roll: ",result)
#     else:
#       done = True
#     if result == 1:
#       total = 0
#       done = True
#     else:
#       total += result
#   return total

# os.system('clear')
# player1score = 0
# player2score = 0
# turnTotal = 0
# playernum = random.randint(1,2)
# print("You will be player ", playernum)
# print("Enter nothing to roll; enter anything to hold.")
# print("Player 1 score: 0")
# print("Player 2 score: 0")
# if playernum == 1:
#   player1 = "me"
#   player2 = "computer"
# elif playernum == 2:
#   player1 = "computer"
#   player2 = "me"

# while player1score < 100 and player2score <100:
#   #Player 1
#   print("\nIt's player 1's turn")

#   turnTotal = turnScore(player1)
#   player1score += turnTotal
  
#   print("Turn score:", turnTotal)
#   print("New Score:", player1score)

#   #Player 2
#   print("\nIt's player 2's turn")
#   turnTotal = turnScore(player2)
#   player2score += turnTotal

#   print("Turn score:", turnTotal)
#   print("New Score:", player2score)

# #player1, player2 = Playersturns()
# print("Player 1 score: ", player1score)
# print("Player 2 score: ", player2score)

# TRIALS = 1000