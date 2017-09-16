package deque;

import java.security.NoSuchAlgorithmException;
import java.util.Iterator;
import java.util.NoSuchElementException;

public class ResizingArrayDeque<Item> implements Iterable<Item> {

    private Item[] a;
    private int first;
    private int last;
    private int n;

    public ResizingArrayDeque() {
        a = (Item[]) new Object[2];
        first = 0;
        last = 0;
        n = 0;
    }

    public boolean isEmpty() {
        return n == 0;
    }

    public int size() {
        return n;
    }

    private void resize(int length) {

    }

    public void pushLeft(Item item) {
        if (n == a.length)
            resize(a.length * 2);
        a[first--] = item;
        n++;
        if (last == -1) {
            last = a.length-1;
        }
    }

    public void pushRight(Item item) {
        if (n == a.length)
            resize(a.length * 2);
        a[last++] = item;
        n++;
        if (last == a.length) {
            last = 0;
        }
    }

    public Item popLeft() {
        if (isEmpty())
            throw new NoSuchElementException();
        Item item = a[first];
        a[first] = null;
        first++;
        n--;
        if (first == a.length) {
            first = 0;
        }
        if (n == a.length / 4)
            resize(a.length / 2);
        return item;
    }

    public Item popRight() {
        if (isEmpty())
            throw new NoSuchElementException();
        Item item = a[last];
        a[last] = null;
        last--;
        n--;
        if (last == -1) {
            last = a.length - 1;
        }
        if (n == a.length / 4)
            resize(a.length / 2);
        return item;
    }

    @Override
    public Iterator<Item> iterator() {
        return null;
    }

    private class ArrayIterator implements Iterator<Item> {

        private int i = 0;

        @Override
        public boolean hasNext() {
            return i < n;
        }
        @Override
        public Item next() {
            if (!hasNext()) throw new NoSuchElementException();
            Item item = a[(first + i) % a.length];
            i++;
            return item;
        }
    }
}