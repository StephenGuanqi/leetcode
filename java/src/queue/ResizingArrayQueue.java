package queue;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class ResizingArrayQueue<Item> implements Iterable<Item> {
    private Item[] q;
    int n;
    private int first = 0;
    private int last = 0;

    public ResizingArrayQueue() {
        q = (Item[]) new Object[2];
        first = 0;
        last = 0;
        n = 0;
    }

    private void resize(int capacity) {
        assert capacity >= n : "Error use of resize capacity: the new capacity must be larger than the current size";
        Item[] temp = (Item[]) new Object[capacity];
        for (int i = 0; i < n; i++) {
            // two situations: first is after last and first is before last
            temp[i] = q[(first + i) % q.length];
        }
        q = temp;
        first = 0;
        last = n;
    }

    public boolean isEmpty() {
        return n == 0;
    };

    /**
     * Adds the item to this queue
     * @param item the item to add
     */
    public void enqueue(Item item) {
        // last catch up and equals to first and mean while the n equals to array size
        if (n == q.length)
            resize(2 * q.length);
        q[last++] = item;
        if (last == q.length)
            last = 0; // wrap around
        n++;
    }

    /**
     * Removes and return the item on this queue that was lease recently added
     * @return the item on the queue that was least recently added
     * @throws NoSuchElementException if this queue is empty
     */
    public Item dequeue() {
        if (isEmpty())
            throw new NoSuchElementException();
        Item item = q[first];
        q[first] = null;
        first++;
        n--;
        if (first == q.length)
            first = 0; // wrap around
        if (n > 0 && n == q.length / 4)
            resize(q.length / 2);
        return item;
    }

    public Item peek() {
        if (isEmpty())
            throw new NoSuchElementException();
        return q[first];
    }

    @Override
    public Iterator<Item> iterator() {
        return new ArrayIterator();
    }

    private class ArrayIterator implements Iterator<Item> {
        private int i = 0;

        @Override
        public Item next() {
            if (isEmpty())
                throw new NoSuchElementException();
            Item item = q[(first + i) % q.length];
            i++;
            return item;
        }

        @Override
        public boolean hasNext() {
            return i < n;
        }
    }
}