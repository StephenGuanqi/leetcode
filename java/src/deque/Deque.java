package deque;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class Deque<Item> implements Iterable<Item> {

    private Node first;
    private Node last;
    private int N;

    private class Node {
        Item item;
        Node next;
        Node previous;
        public Node(Item item) {
            this.item = item;
        }
    }

    public Deque() {
        first = last = null;
    }

    public boolean isEmpty() { return N == 0 ;}

    public int size() { return N; }

    public void pushLeft(Item item) {
        Node oldFirst = first;
        first = new Node(item);
        first.next = oldFirst;
        if (oldFirst != null) { // the deque is not empty when item added
            oldFirst.previous = first;
        } else { // previous last and first are both null;
            last = first;
        }
        N++; 
    }

    public void pushRight(Item item) {
        Node oldLast = last;
        last = new Node(item);
        if (oldLast != null) {
            oldLast.next = last;
            last.previous = oldLast;
        } else {
            first = last;
        }
        N++;
    }

    public Item popLeft() {
        if (isEmpty()) throw new NoSuchElementException();
        Item item = first.item;
        first = first.next;
        N--; // notice the N minus order.
        if (first != null ) { 
            first.previous = null; // avoid loitering
        } else { // the deque is empty
            last = first; // set last and first to null; also avoid loitering
        }
        return item;
    }

    public Item popRight() {
        if (isEmpty()) throw new NoSuchElementException();
        Item item = last.item;
        last = last.previous;
        N--;
        if (last != null) {
            last.next = null;
        } else {
            first = last;
        }
        return item;
    }

    @Override
    public Iterator<Item> iterator() {
        return new ListIterator();
    }

    private class ListIterator implements Iterator<Item> {
        private Node current = first;
        @Override
        public boolean hasNext() {
            return current != null;
        }
        @Override
        public Item next() {
            if (!hasNext()) throw new NoSuchElementException();
            Item item = current.item;
            current = current.next;
            return item;
        }
    }

}