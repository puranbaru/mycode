package index;

import java.util.List;
import java.util.ArrayList;
import java.util.List;

public class IndexNode  {

	String word;
	int occurences;
	List<Integer> list;
	
	IndexNode left;
	IndexNode right;
	
	
	// Constructors
	// Constructor should take in a word and a line number
	// it should initialize the list and set occurrences to 1
	
	public IndexNode(String word, int lineNumber) {
        this.word = word;
        this.occurences = 1;
        this.list = new ArrayList<>();
        this.list.add(lineNumber);
        this.left = null;
        this.right = null;
    }

    public void addLine(int lineNumber) {
        this.occurences++;
        this.list.add(lineNumber);
    }

    // Implement a method to add a line number to the list
    public void addLineNumber(int lineNumber) {
        this.list.add(lineNumber);
        this.occurences++;
    }

    // Return the word, the number of occurrences, and the lines it appears on as a string
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Word: ").append(word).append("\n");
        sb.append("Occurrences: ").append(occurences).append("\n");
        sb.append("Lines: ");
        for (int lineNumber : list) {
            sb.append(lineNumber).append(" ");
        }
        sb.append("\n");
        return sb.toString();
    }

    public String getWord() {
        return word;
    }
    
    public IndexNode getLeft() {
        return left;
    }
    
    public IndexNode getRight() {
        return right;
    }
    
    public void setRight(IndexNode node) {
        right = node;
    }

    public void setLeft(IndexNode node) {
        left = node;
    }

    public int getOccurrences() {
        return this.occurences;
    }

    public void removeLine() {
        if (this.occurences > 0) {
            this.occurences--;
            if (!list.isEmpty()) {
                list.remove(list.size() - 1);
            }
        }
    }
    
    public void setWord(String word) {
        this.word = word;
    }

    public List<Integer> getLines() {
        return list;
    }
    
	
}
