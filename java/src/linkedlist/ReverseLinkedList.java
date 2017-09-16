package linkedlist;
public class ReverseLinkedList {
    private static class Node<Item> {
        Item item;
        Node<Item> next;
    }

    /**
     * Reverse a linkedlist with destroy
     * @return the head node of the new reversed linkedlist
     */
    public static <Item> Node<Item> reverse(Node<Item> node) {
        Node<Item> reverse = null; // the head node of the new linked list
        Node<Item> first = node; // first node of the rest of the original
        Node<Item> second = null;
        while (first != null) {
            second = first.next;
            first.next = reverse;
            reverse = first;
            first = second;
        }
        return reverse;
    }

    public static <Item> Node<Item> reverseRecursive(Node<Item> first) {
        if (first == null) return null;
        if (first.next == null) return first;
        Node<Item> second = first.next;
        Node<Item> headNode = reverseRecursive(second);
        second.next = first; // oppose the direction of the two nodes
        first.next = null; //  remove the original direction of the two nodes.
        return headNode;
    }

}