def hawaiian_pronunciation(word):
    # Define the translation rules for consonants
    consonants = {
        'p': 'p',
        'k': 'k',
        'h': 'h',
        'l': 'l',
        'm': 'm',
        'n': 'n',
#        'w': 'w',
    }

    # Define the translation rules for vowels
    vowels = {
        'a': 'ah',
        'e': 'eh',
        'i': 'ee',
        'o': 'oh',
        'u': 'oo',
    }

    # Define special combinations
    special_combinations = {
        'ai': 'eye',
        'ae': 'eye',
        'ao': 'ow',
        'au': 'ow',
        'ei': 'ay',
        'eu': 'eh-oo',
        'iu': 'ew',
        'oi': 'oyo',
        'ou': 'ow',
        'ui': 'ooey',
    }

    pronunciation = ""
    current_sound = ""
    apostrophe_detected = False

    i = 0
    while i < len(word):
        char = word[i]

        if char == "'":
            apostrophe_detected = True
            i += 1
            continue
        
        # If the first letter is w then current sound is w.
        if word[i] == 'w' and i == 0:
            current_sound = 'w'
        elif i > 0 and word[i] == 'w':
            # This is special case for w
            

        if char in consonants:
            current_sound = consonants[char]
        elif char in vowels:
            # Check if there is special combination, else use the vowel pronounciation

            current_sound = vowels[char]
        elif char == " ":
            if apostrophe_detected:
                pronunciation += current_sound
                apostrophe_detected = False
            pronunciation += " "
            current_sound = ""
        else:
            # Try to find special combinations
            for length in range(2, 4):
                if i + length <= len(word):
                    combination = word[i:i + length]
                    if combination in special_combinations:
                        pronunciation += special_combinations[combination]
                        i += length
                        break
            else:
                # Handle 'w' based on its position in the word
                if char == 'w':
                    if i == 0 or word[i - 1] == ' ':
                        # 'w' at the start of the word or after a space
                        current_sound = 'w'
                    elif i + 1 < len(word) and (word[i + 1] == 'a' or word[i + 1] == 'i' or word[i + 1] == 'e'):
                        # 'w' after 'a', 'i', or 'e'
                        current_sound = 'w'
                    elif i + 1 < len(word) and (word[i + 1] == 'u' or word[i + 1] == 'o'):
                        # 'w' after 'u' or 'o'
                        current_sound = 'w'
                    else:
                        # Default to 'v' sound after 'i' or 'e
                        current_sound = 'v'
                else:
                    # If no special combination found, use current_sound
                    if current_sound:
                        pronunciation += current_sound
                    else:
                        # Invalid character, warn the user
                        print(f"'{char}' is not a valid Hawaiian character")
                        return ""

        i += 1

    if apostrophe_detected:
        pronunciation += current_sound
    elif current_sound:
        pronunciation += current_sound

    return pronunciation

while True:
    user_input = input("Enter a Hawaiian word to pronounce ==> ")
    pronunciation = hawaiian_pronunciation(user_input.lower())
    if pronunciation:
        print(f'{user_input.upper()} is pronounced {pronunciation.capitalize()}')
    another_word = input("Do you want to enter another word? Y/YES/N/NO ==> ")
    if another_word.lower() not in ('y', 'yes'):
        break
