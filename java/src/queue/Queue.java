package queue;

import java.util.Iterator;
import java.util.NoSuchElementException;

class Queue<Item> implements Iterable<Item> {
    private Node first;
    private Node last;
    int N;

    private class Node {
        Item item;
        Node next;
    }

    public Queue() {
        first = last = null;
        N = 0;
    }

    public Item peek() {
        if (isEmpty()) {
            throw new NoSuchElementException("Queue underflow");
        }
        return first.item;
    }

    public Item dequeue() {
        if (isEmpty()) {
            throw new NoSuchElementException("Queue underflow");
        }
        Item item = first.item;
        first = first.next;
        N--;
        if (isEmpty()) {
            last = first;
        }
        return item;
    }

    public void enqueue(Item item) {
        Node oldLast = last;
        last = new Node();
        last.item = item;
        if (oldLast == null) {
            first = last;
        } else {
            oldLast.next = last;
        }
        N++;
    }

    public boolean isEmpty() {
        return first == null;
    }

    @Override
    public Iterator<Item> iterator() {
        return new ListIterator();
    }

    private class ListIterator implements Iterator<Item> {
        Node current = first;

        @Override
        public Item next() {
            if (!hasNext())
                throw new NoSuchElementException();
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