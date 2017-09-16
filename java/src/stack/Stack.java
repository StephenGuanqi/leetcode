package stack;

import java.util.Iterator;

public class Stack<Item> implements Iterable<Item> {
    private class Node {
        Item item;
        Node next;
        Node(){

        }
        Node(Node node) {
            item = node.item;
            if (node.next != null) 
                next = new Node(node.next);
        }
    }

    public Stack(Stack<Item> s) {
        if (s.head != null) {
             head = new Node(s.head);
            N = s.N;
        } else {
            head = null;
        }
    }

    private int N;
    private Node head;

    public boolean isEmpty() {
        return head == null;
    }

    public int size() {
        return N;
    }

    public void push(Item item) {
        Node oldFirst = head;
        head = new Node();
        head.item = item;
        head.next = oldFirst;
        N++;
    }

    public Item pop() { // check stack empty in the caller
        Item item = head.item;
        head = head.next;
        N--;
        return item;
    }

    @Override
    public Iterator<Item> iterator() {
        return new ListIterator();
    }

    private class ListIterator implements Iterator<Item> {
        Node current = head;

        @Override
        public Item next() {
            Item item = current.item;
            current = current.next;
            return item;
        }

        @Override
        public boolean hasNext() {
            return current != null;
        }
    }
}