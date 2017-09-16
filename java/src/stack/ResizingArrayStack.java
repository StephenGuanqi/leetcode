package stack;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class ResizingArrayStack<Item> implements Iterable<Item> {

    int N;
    Item[] a = (Item[]) new Object[1];

    public boolean isEmpty() {
        return N == 0;
    }

    public int size() {
        return N;
    }

    private void resize(int length) {
        Item[] temp = (Item[]) new Object[length];
        for (int i = 0; i < N; i++) {
            temp[i] = a[i];
        }
        a = temp;
    }

    public void push(Item item) {
        if (a.length == N) {
            resize(2 * a.length);
        }
        a[N++] = item;
    }

    public Item pop() {
        if (N == 0) {
            throw new NoSuchElementException();
        }
        Item item = a[--N];
        a[N] = null;// force garbage collection
        if (N > 0 && N == a.length / 4)
            resize(a.length / 2);
        return item;
    }

    @Override
    public Iterator<Item> iterator() {
        return new ReverseArrayIterator();
    }

    private class ReverseArrayIterator implements Iterator<Item> {
        private int i = N;

        @Override
        public Item next() {
            if (i == 0) {
                throw new NoSuchElementException();
            }
            return a[--i];
        }

        @Override
        public boolean hasNext() {
            return i > 0;
        }
    }

}