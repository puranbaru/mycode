package index;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class IndexTree {
    private IndexNode root;

    public IndexTree() {
        this.root = null;
    }

    // Add a word and line number to the index
    public void add(String word, int lineNumber) {
        this.root = add(root, word, lineNumber);
    }

    private IndexNode add(IndexNode root, String word, int lineNumber) {
        if (root == null) {
            return new IndexNode(word, lineNumber);
        }
        int comparison = word.compareTo(root.getWord());
        if (comparison == 0) {
            root.addLineNumber(lineNumber);
        } else if (comparison < 0) {
            root.setLeft(add(root.getLeft(), word, lineNumber));
        } else {
            root.setRight(add(root.getRight(), word, lineNumber));
        }
        return root;
    }

    // Check if a word is in the index
    public boolean contains(String word) {
        return contains(root, word);
    }

    private boolean contains(IndexNode root, String word) {
        if (root == null) {
            return false;
        }
        int comparison = word.compareTo(root.getWord());
        if (comparison == 0) {
            return true;
        } else if (comparison < 0) {
            return contains(root.getLeft(), word);
        } else {
            return contains(root.getRight(), word);
        }
    }

    // Remove a word from the index
    public void delete(String word) {
        this.root = delete(root, word);
    }

    private IndexNode delete(IndexNode root, String word) {
        if (root == null) {
            return root;
        }
        int comparison = word.compareTo(root.getWord());
        if (comparison < 0) {
            root.setLeft(delete(root.getLeft(), word));
        } else if (comparison > 0) {
            root.setRight(delete(root.getRight(), word));
        } else {
            if (root.getOccurrences() > 1) {
                root.removeLine(); // Decrease occurrences
            } else {
                if (root.getLeft() == null) {
                    return root.getRight();
                } else if (root.getRight() == null) {
                    return root.getLeft();
                }
                IndexNode minNode = findMin(root.getRight());
                root.setWord(minNode.getWord());
                root.setRight(delete(root.getRight(), minNode.getWord()));
            }
        }
        return root;
    }

    public List<Integer> getLinesForWord(String word) {
    return getLinesForWord(root, word);
    }

    private List<Integer> getLinesForWord(IndexNode root, String word) {
        List<Integer> lines = new ArrayList<>();

        if (root == null) {
            return lines; // Word not found, return an empty list
        }

        int comparison = word.compareTo(root.getWord());
        if (comparison == 0) {
            return root.getLines();
        } else if (comparison < 0) {
            return getLinesForWord(root.getLeft(), word);
        } else {
            return getLinesForWord(root.getRight(), word);
        }
    }


    private IndexNode findMin(IndexNode node) {
        while (node.getLeft() != null) {
            node = node.getLeft();
        }
        return node;
    }

    // Print the index in inorder order
    public void printIndex() {
        printIndex(root);
    }

    private void printIndex(IndexNode root) {
        if (root != null) {
            printIndex(root.getLeft());
            System.out.println(root);
            printIndex(root.getRight());
        }
    }

    public static void main(String[] args) {
    IndexTree index = new IndexTree();

    try (BufferedReader reader = new BufferedReader(new FileReader("/Users/puranbaru/Documents/Programming/Java/Indexing/Indexing Text/shakespeare.txt"))) {
        String line;
        int lineNumber = 1;
        while ((line = reader.readLine()) != null) {
            String[] words = line.split("\\s+"); // Split by space

            for (String word : words) {
                word = word.toLowerCase().replaceAll("[^a-z]", ""); // Remove non-alphabetic characters
                if (!word.isEmpty()) {
                    index.add(word, lineNumber);
                }
            }

            lineNumber++;
        }
    } catch (IOException e) {
        e.printStackTrace();
    }

    // Print the index
    index.printIndex();

    // Search for a word in the index
    Scanner scanner = new Scanner(System.in);
    String wordToSearch;

    while (true) {
        System.out.print("Enter a word to search for (or 'q' to quit): ");
        wordToSearch = scanner.nextLine().toLowerCase();

        if (wordToSearch.equals("q")) {
            break; // Exit the loop if 'q' is entered
        }

        if (index.contains(wordToSearch)) {
            List<Integer> linesAndOccurrences = index.getLinesForWord(wordToSearch);
            List<Integer> lines = linesAndOccurrences.subList(0, linesAndOccurrences.size() - 1);
            int occurrences = linesAndOccurrences.get(linesAndOccurrences.size() - 1);

            System.out.println("The word '" + wordToSearch + "' was found in the index.");
            System.out.println("Occurrences: " + occurrences);
            System.out.println("It appears on the following lines: " + lines);

        } else {
            System.out.println("The word '" + wordToSearch + "' was not found in the index.");
        }
    }
    // Close the scanner
    scanner.close();
}

}
