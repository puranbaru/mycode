package CheatingComputers;
import java.util.*;
import java.io.*;
import java.nio.file.*;
import java.util.stream.Collectors;

public class CheatersHangman {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        List<String> dictionary = loadDictionary("/Users/puranbaru/Documents/Programming/Java/CheatingComputers/dictionary.txt");
        boolean playAgain = true;

        ////////////////////////////////////////////

        while (playAgain) {
            int wordLength = askForWordLength(scanner, dictionary);
            int maxWrongGuesses = askForMaxWrongGuesses(scanner);

            List<String> hiddenWords = getWordsWithLength(dictionary, wordLength);

            playHangman(scanner, hiddenWords, maxWrongGuesses);

            System.out.print("Do you want to play again? (yes= y / no= n): ");
            String playChoice = scanner.next().toLowerCase();
            playAgain = playChoice.equals("yes") || playChoice.equals("y");
        }

        // while (playAgain) {
        //     int wordLength = askForWordLength(scanner, dictionary);
        //     int maxWrongGuesses = askForMaxWrongGuesses(scanner);
        
        //     List<String> hiddenWords = getWordsWithLength(dictionary, wordLength);
        
        //     playHangman(scanner, hiddenWords, maxWrongGuesses, wordLength);
        
        //     System.out.print("Do you want to play again? (yes= y / no= n): ");
        //     String playChoice = scanner.next().toLowerCase();
        //     playAgain = playChoice.equals("yes") || playChoice.equals("y");
        // }

        ////////////////////////////////////////////
        System.out.println("Thanks for playing!");
        scanner.close();
    }

    private static List<String> loadDictionary(String fileName) {
        List<String> words = new ArrayList<>();
        try {
            words = Files.readAllLines(Paths.get(fileName));
        } catch (IOException e) {
            System.err.println("Error occurred when attempting to read dictionary file.");
        }
        return words.stream()
                .map(String::toLowerCase)
                .collect(Collectors.toList());
    }

    private static int askForWordLength(Scanner scanner, List<String> dictionary) {
        int wordLength;
        do {
            System.out.print("Enter the length of the word you want to guess: ");
            wordLength = scanner.nextInt();
            List<String> wordsWithLength = getWordsWithLength(dictionary, wordLength);
            if (wordsWithLength.isEmpty()) {
                System.out.println("Sorry, no words of that length are available in the dictionary. Please try another word length.");
            } else {
                return wordLength;
            }
        } while (true);
    }
    
    private static int askForMaxWrongGuesses(Scanner scanner) {
        System.out.print("Enter the maximum wrong guesses allowed: ");
        return scanner.nextInt();
    }

    private static List<String> getWordsWithLength(List<String> dictionary, int length) {
        return dictionary.stream()
                .filter(word -> word.length() == length)
                .map(String::toUpperCase)
                .collect(Collectors.toList());
    }


///////////////////////////////////////

private static void playHangman(Scanner scanner, List<String> hiddenWords, int maxWrongGuesses) {
    Set<Character> guessedLetters = new HashSet<>();
    int wrongGuesses = 0;
    String hiddenWord = hiddenWords.get(0);

    while (wrongGuesses < maxWrongGuesses) {
        String revealedWord = revealWord(hiddenWord, guessedLetters);
        System.out.println("\n");
        System.out.println("Word: " + revealedWord);
        System.out.println("Guessed Letters: " + guessedLetters);
        System.out.println("Remaining Wrong Guesses: " + (maxWrongGuesses - wrongGuesses));

        if (revealedWord.equals(hiddenWord)) {
            System.out.println("Congrats! You guessed the hidden word: " + hiddenWord);
            return;
        }

        System.out.print("Enter a letter to guess: ");
        char guess = scanner.next().toUpperCase().charAt(0);

        if (guessedLetters.contains(guess)) {
            System.out.println("You already guessed that letter. Your number of guesses won't decrease, so please enter another letter: ");
            continue;
        }

        guessedLetters.add(guess);

        List<String> wordFamilies = createWordFamilies(hiddenWords, guess, guessedLetters);
        hiddenWord = chooseWordFamily(wordFamilies);

        if (!hiddenWord.contains(String.valueOf(guess))) {
            wrongGuesses++;
        }
    }
    System.out.println("You're out of guesses. Better luck next time! The hidden word was: " + hiddenWord);
}

private static String chooseWordFamily(List<String> wordFamilies) {
    return null;
}

private static List<String> createWordFamilies(List<String> words, char guess, Set<Character> guessedLetters) {
    Map<String, List<String>> wordFamilies = new HashMap<>();

    for (String word : words) {
        StringBuilder family = new StringBuilder();
        for (char c : word.toCharArray()) {
            if (guessedLetters.contains(c) || c == guess) {
                family.append(c);
            } else {
                family.append("_");
            }
        }
        String famStr = family.toString();
        wordFamilies.computeIfAbsent(famStr, k -> new ArrayList<>()).add(word);
    }

    // Now, choose one of the word families strategically, e.g., randomly.
    List<String> remainingWordFamilies = new ArrayList<>(wordFamilies.keySet());
    if (!remainingWordFamilies.isEmpty()) {
        Random random = new Random();
        String chosenFamily = remainingWordFamilies.get(random.nextInt(remainingWordFamilies.size()));
        return wordFamilies.get(chosenFamily);
    } else {
        return new ArrayList<>();
    }
}

// private static void playHangman(Scanner scanner, List<String> hiddenWords, int maxWrongGuesses) {
//     Set<Character> guessedLetters = new HashSet<>();
//     int wrongGuesses = 0;
//     String hiddenWord = hiddenWords.get(0);

//     while (wrongGuesses < maxWrongGuesses) {
//         String revealedWord = revealWord(hiddenWord, guessedLetters);
//         System.out.println("\n");
//         System.out.println("Word: " + revealedWord);
//         System.out.println("Guessed Letters: " + guessedLetters);
//         System.out.println("Remaining Wrong Guesses: " + (maxWrongGuesses - wrongGuesses));

//         if (revealedWord.equals(hiddenWord)) {
//             System.out.println("Congrats! You guessed the hidden word: " + hiddenWord);
//             return;
//         }

//         System.out.print("Enter a letter to guess: ");
//         char guess = scanner.next().toUpperCase().charAt(0);

//         if (guessedLetters.contains(guess)) {
//             System.out.println("You already guessed that letter. Your number of guesses won't decrease, so please enter another letter: ");
//             continue;
//         }

//         guessedLetters.add(guess);

//         List<String> matchingWords = filterWordsByCorrectSpot(hiddenWords, guess, guessedLetters, revealedWord);
        
//         if (matchingWords.isEmpty()) {
//             System.out.println("No word family available. You're out of guesses.");
//             return;
//         }

//         hiddenWord = chooseWordFamily(matchingWords);

//         if (!hiddenWord.contains(String.valueOf(guess))) {
//             wrongGuesses++;
//         }
//     }
//     System.out.println("You're out of guesses. Better luck next time! The hidden word was: " + hiddenWord);
// }

// private static List<String> filterWordsByCorrectSpot(List<String> words, char guess, Set<Character> guessedLetters, String revealedWord) {
//     return words.stream()
//             .filter(word -> wordMatchesGuess(word, guess, guessedLetters, revealedWord))
//             .collect(Collectors.toList());
// }

// private static boolean wordMatchesGuess(String word, char guess, Set<Character> guessedLetters, String revealedWord) {
//     if (word.length() != revealedWord.length()) {
//         return false;
//     }

//     for (int i = 0; i < word.length(); i++) {
//         char letter = word.charAt(i);
//         char revealedLetter = revealedWord.charAt(i);

//         if (revealedLetter != '_' && revealedLetter != letter) {
//             return false;
//         }

//         if (revealedLetter == '_' && guessedLetters.contains(letter)) {
//             return false;
//         }

//         if (revealedLetter == guess && letter != guess) {
//             return false;
//         }
//     }

//     return true;
// }


// private static List<String> createWordFamilies(List<String> words, char guess, Set<Character> guessedLetters) {
//     Map<String, List<String>> wordFamilies = new HashMap<>();

//     for (String word : words) {
//         char[] familyChars = new char[word.length()];
//         for (int i = 0; i < word.length(); i++) {
//             char c = word.charAt(i);
//             if (guessedLetters.contains(c) || c == guess) {
//                 familyChars[i] = c;
//             } else {
//                 familyChars[i] = '_';
//             }
//         }
//         String famStr = new String(familyChars);
//         wordFamilies.computeIfAbsent(famStr, k -> new ArrayList<>()).add(word);
//     }

//     // Now, choose one of the word families strategically, e.g., randomly.
//     List<String> remainingWordFamilies = new ArrayList<>(wordFamilies.keySet());
//     if (!remainingWordFamilies.isEmpty()) {
//         Random random = new Random();
//         String chosenFamily = remainingWordFamilies.get(random.nextInt(remainingWordFamilies.size()));
//         return wordFamilies.get(chosenFamily);
//     } else {
//         return new ArrayList<>();
//     }
// }


// private static String chooseWordFamily(List<String> wordFamilies) {
//     return wordFamilies.get(0);
// }

    
    
    
    // private static void playHangman(Scanner scanner, List<String> hiddenWords, int maxWrongGuesses) {
    //     Set<Character> guessedLetters = new HashSet<>();
    //     int wrongGuesses = 0;
    //     String hiddenWord = hiddenWords.get(0);
        

    //     while (wrongGuesses < maxWrongGuesses) {
    //         String revealedWord = revealWord(hiddenWord, guessedLetters);
    //         System.out.println("\n");
    //         // System.out.println("Word: " + revealedWord);
    //         System.out.println("Guessed Letters: " + guessedLetters);
    //         System.out.println("Remaining Wrong Guesses: " + (maxWrongGuesses - wrongGuesses));

    //         if (revealedWord.equals(hiddenWord)) {
    //             System.out.println("Congrats! You guessed the hidden word: " + hiddenWord);
    //             return;
    //         }

    //         System.out.print("Enter a letter to guess: ");
    //         char guess = scanner.next().toUpperCase().charAt(0);

    //         if (guessedLetters.contains(guess)) {
    //             System.out.println("You already guessed that letter. Your number of guesses won't decrease, so please enter another letter: ");
    //             continue;
    //         }

    //         guessedLetters.add(guess);

    //         List<String> wordFamilies = createWordFamilies(hiddenWords, guess, guessedLetters);
    //         hiddenWord = chooseWordFamily(wordFamilies);

    //         if (!hiddenWord.contains(String.valueOf(guess))) {
    //             wrongGuesses++;
    //         }
    //     }
    //     System.out.println("You're out of guesses. Better luck next time! The hidden word was: " + hiddenWord);
    // }

    /////////////////////////////////////////////

    private static String revealWord(String word, Set<Character> guessedLetters) {
        StringBuilder revealed = new StringBuilder();
        for (char c : word.toCharArray()) {
            if (guessedLetters.contains(c)) {
                revealed.append(c);
            } else {
                revealed.append("_");
            }
        }
        return revealed.toString();
    }

    // private static List<String> createWordFamilies(List<String> words, char guess, Set<Character> guessedLetters) {
    //     List<String> matchingWords = new ArrayList<>();
    
    //     for (String word : words) {
    //         if (wordContainsLetter(word, guess, guessedLetters)) {
    //             matchingWords.add(word);
    //         }
    //     }
    
    //     return matchingWords;
    // }
    
    private static boolean wordContainsLetter(String word, char letter, Set<Character> guessedLetters) {
        for (char c : word.toCharArray()) {
            if (c == letter || guessedLetters.contains(c)) {
                return true;
            }
        }
        return false;
    }
    
    // private static String chooseWordFamily(List<String> wordFamilies) {
    //     if (!wordFamilies.isEmpty()) {
    //         Random random = new Random();
    //         int randomIndex = random.nextInt(wordFamilies.size());
    //         return wordFamilies.get(randomIndex);
    //     } else {
    //         // If there are no word families, there's nothing to choose from, so return an empty string.
    //         return "";
    //     }
    // }
    

}
