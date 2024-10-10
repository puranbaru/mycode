import java.util.Iterator;
import java.util.LinkedList;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class CircularLinkedList<E> implements Iterable<E> {
	Node<E> head = null;
	Node<E> tail = null;
	int size;
	Node<E> current;

	// Implement a constructor
	public CircularLinkedList() {
//		LinkedList<E> list = new LinkedList<>();
		current = null;
		size = 0;

	}

	// Return Node<E> found at the specified index
	// Be sure to check for out of bounds cases
	private Node<E> getNode(int index) {
		if (index < 0 || index >= size) {
			return null;
		}
		Node<E> node = head;
		for (int i = 0; i < index && node != null; i++) {
			node = node.next;
		}
		return node;
	}

	// Add a node to the end of the list
	// HINT: Use the overloaded add method as a helper method
	public boolean add(E item) {
		Node <E> newNode = new Node(item);
		size += 1;

		if (size == 1) {
			// initializes empty list
			head = newNode;
			tail = newNode;
			head.next = tail;
			tail.next = head;
		}
		else{
			Node<E> prevTail = tail;
			tail = newNode;
			tail.next = head;
			prevTail.next = tail;
		}


		return true;
	}

	
	// Cases to handle:
	//      Out of bounds
	//      Adding an element to an empty list
	//      Adding an element to the front
	//      Adding an element to the end
	//      Adding an element in the middle
	// HINT: Remember to keep track of the list's size
	public void add(int index, E item) {
		Node<E> newNode = new Node<>(item);
		if (add(item)){
			if (size == 0){
				newNode.next = newNode;
				current = newNode;
			}
			else{
				newNode.next = current.next;
				current.next = newNode;
			}
			size++;

		}




	}

	// Cases to handle:
	//      Out of bounds
	//      Removing the last element in the list
	//      Removing the first element in the list
	//      Removing the last element
	//      Removing an element from the middle
	// HINT: Remember to keep track of the list's size
	public E remove(int index) {
		if (size == 0) {
			return null;
		}
	
		if (index < 0 || index >= size) {
			throw new IndexOutOfBoundsException("Index is out of bounds");
		}
	
		int removedItem;
	
		if (size == 1) {
			removedItem = head.item;
			head = null;
			tail = null;
			current = null;
		} else {
			Node<E> prevNode = getNode(index - 1);
			removedItem = prevNode.next.item;
	
			if (prevNode.next == head) {
				head = head.next;
			}
	
			prevNode.next = prevNode.next.next;
	
			if (index == size - 1) {
				// If removing the last element, update tail
				tail = prevNode;
			}
		}
	
		size--;
	
		return removedItem;
	}
	
	
	// Stringify your list
	// Cases to handle:
	//      Empty list
	//      Single element list
	//      Multi-element list
	// Use "==>" to delimit each node
	public String toString() {
		StringBuilder result = new StringBuilder();

		return result.toString();
	}

	public Iterator<E> iterator() {
		return new ListIterator<E>();
	}
	
	// This class is not static because it needs to reference its parent class
	private class ListIterator<E> implements Iterator<E> {
		Node<E> nextItem;
		Node<E> prev;
		int index;
		
		@SuppressWarnings("unchecked")
		// Creates a new iterator that starts at the head of the list
		public ListIterator() {
			nextItem = (Node<E>) head;
			index = 0;
		}

		// Returns true if there is a next node
		public boolean hasNext() {
			return nextItem != null;
		}
		
		// Advances the iterator to the next item
		// Should wrap back around to the head
		public E next() {
			if (!hasNext()){
				throw new NoSuchElementException();
			}
			prev = nextItem;
			nextItem = nextItem.next;
			index++;
			return prev.item;

		}
		
		// Remove the last node visted by the .next() call
		// For example, if we had just created an iterator,
		// the following calls would remove the item at index 1 (the second person in the ring)
		// next() next() remove()
		// Use CircularLinkedList.this to reference the CircularLinkedList parent class
		public void remove() {
			
		}
		
	}
	
	// The Node class
	private static class Node<E>{
		E item;
		// link to next node
		Node<E> next = null;
		// link to previous node
		Node<E> prev = null;
		public Node(E item) {
			this.item = item;
		}
		
	}
	
	public static void main(String[] args){
		Scanner sc = new Scanner (System.in);
		CircularLinkedList list = new CircularLinkedList();
		CircularLinkedList display = new CircularLinkedList();
//		CircularLinkedList<E> list = new CircularLinkedList<>();


		System.out.println("How many soldiers?");
		int n = sc.nextInt();

		System.out.println("How many to count?");
		int k = sc.nextInt();

		for (int i = 1; i <= n; i++){
			list.add(i);
		}



		while (list.size > 2) {
			for (int i = 0; i < k - 1; i++) {
				list.current = list.current.next;
			}
			int removedSoldier = list.remove(0); // Remove the soldier at index 0
			System.out.println("Soldier " + removedSoldier + " was killed.");
		}
		
		//System.out.println("")
		display.display();
		
	}
	public void display(){
		Node current = head;
		if (head == null){
			System.out.println("List is empty");
		}
		else{
			System.out.println("Remaining knights");
			do {
				System.out.println(current.item + " ==> ");
				current = current.next;
			}while(current != head);
			System.out.println();
		}
	}



	
	
}
