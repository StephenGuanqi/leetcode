package linkedlist;
public class MaxLinkedList {
    private static class Node {
        Integer item;
        Node next;
    }

    public Integer getMaxNodeValue(Node head) {
        Integer max = Integer.valueOf(0);
        for (Node node = head; node != null; node = node.next){
            if (node.item > max) {
                max = node.item;
            }
        }
        return max;
    }

    public Integer getMaxValueRecursive(Node head) {
        if (head == null) return 0;
        Integer max = getMaxNodeValue(head.next);
        return max > head.item ? max : head.item;
    }

}