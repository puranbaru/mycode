
    #these consonants sound the same
consonants = {
        "p":"p",
        "k":"k",
        "l":"l",
        "m":"m",
        "n":"n"
    }
    #these vowels sound as such 
vowels = {
        "a":"ah",
        "e":"eh",
        "i":"ee",
        "o":"oh",
        "u":"oo",
        }
doubleVowel = {
        "ai" : "eye",
        "ae":"eye",
        "ao":"ow",
        "au":"ow"

    }
'''
    pronunciations = ""

    current_sound = ""
    apostraphe_detected = False
'''
def validate(word):
    wordUpdate = word.lower()
    index = 0 
    while index < len(wordUpdate):
        if wordUpdate[index] in vowels or wordUpdate[index] in consonants or wordUpdate[index+1] in doubleVowel:
            pass
        else:
            print(wordUpdate[index], "is not a valid hawaiian character")
            return False
        index+=1
        return True

def pronounce(word):
  """
  Given a valid hawaiian word, 
  returns a string that gives the correct pronunciation
  """
  output = " "
  index = 0
  wordUpdate = word.lower()
  while index < len(word):
    #if letter at index and next letter is a double vowel, handle
    if index < len(word)-1 and wordUpdate[index] + wordUpdate[index+1] in doubleVowel:
      #print(doubleVowel[wordUpdate[index] + wordUpdate[index+1]] + "-",end="")
      output += doubleVowel[wordUpdate[index] + wordUpdate[index+1]] 
      if index <len(word)-2: 
        output += "-"
      index +=2
      
    #if letter at index is a vowel, handle
    elif  wordUpdate[index] in vowels:
      #print(vowels[wordUpdate[index]] + "-",end="")
      output += vowels[wordUpdate[index]]
      if index <len(word)-1: 
        output += "-"
      index += 1
      
    #if letter is consonant, handle that
    elif wordUpdate[index] in consonants:
      #print(wordUpdate[index],end="")
      if wordUpdate[index] == "w" and index > 0:
        if wordUpdate[index-1] == "e" or wordUpdate[index-1] == "i":
          output += "v"
        else:
          output += "w"
      else:
        output += wordUpdate[index]
      index += 1

    #if apostrophe or space, handle that
    # elif wordUpdate[index] == "'" or wordUpdate[index] == " ":
    #   output += wordUpdate[index]
    #   index += 1

  return output


response = "Y"
valWord = True
while (response.lower() == "y" or response.lower() == "yes") and valWord:
  word = input("Enter a Hawaiian word to pronounce ==> ")
  valWord = validate(word)
  while valWord == False:
    word = input("\nEnter a Hawaiian word to pronounce ==> ")
    valWord = validate(word)
  
  output = pronounce(word)
  
  print("\n"+word.upper() + " is pronounced " + output.capitalize())

  #uppercase
  print("\n"+word.upper() + " is pronounced " + str.title(output))
  response = input("\nDo you want to enter another word Y/YES/N/NO ==> ")
  



