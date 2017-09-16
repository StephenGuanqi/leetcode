package divideconquer;

import com.sun.org.apache.xalan.internal.xsltc.compiler.util.CompareGenerator;
import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdOut;

public class MergeSort {

    // space complexity is O(n)
    private static void mergetogether(Comparable[] a, int left, int mid, int right) {
        int leftsize = mid - left + 1;
        int rightsize = right - mid;
        Comparable[] leftHalf = new Comparable[leftsize]; // sorted left half Comparable array, index left to mid of original array
        Comparable[] rightHalf = new Comparable[rightsize]; // sorted right half Comparable array, index mid+1 to right of original array
        for (int i = 0; i < leftsize; i++ ) {
            leftHalf[i] = a[left + i];
        }
        for (int j = 0; j < rightsize; j++) {
            rightHalf[j] = a[mid + 1 + j];
        }
        int i = 0 ;
        int j = 0;
        int k = left;
        while ( i < leftsize && j < rightsize) {
            if (leftHalf[i].compareTo(rightHalf[j]) < 0) {
                a[k++] = leftHalf[i];
                i++;
            } else {
                a[k++] = rightHalf[j];
                j++;
            }
        }
        // the left of the items
        while ( i < leftsize) { a[k++] = leftHalf[i++]; }
        while ( j < rightsize) { a[k++] = rightHalf[j++]; }
    }

    private static void merge(Comparable[] a, Comparable[] tmp, int left, int mid, int right) {
        // debug precondition
        assert isSorted(a, left, mid);
        assert isSorted(a, mid+1, right);

        for (int k = left; k <= right; k++) {
            tmp[k] = a[k];
        }

        int i = left;
        int j = mid + 1;
        for (int k = left; k <= right; k++) {
            if (i > mid) a[k] = tmp[j++];
            else if ( j > right ) a[k] = tmp[i++];
            else if ( tmp[i].compareTo(tmp[j]) < 0 ) a[k] = tmp[i++];
            else a[k] = tmp[j++];
        }

        // debug postcondition
        assert isSorted(a, left, right);
    }

    /**
     * sort left half and right half the array and merge them together
     * @param a the sorted two halves of array and merged destination
     * @param tmp tmp array to hold the two halves of the sorted array
     * @param left
     * @param right
     */
    private static void mergeSort(Comparable[] a, Comparable[] tmp, int left, int right) {
        if (right <= left) return;
        int mid = left + (right - left) / 2;
        mergeSort(a, tmp, left, mid);
        mergeSort(a, tmp, mid+1, right);
        merge(a, tmp, left, mid, right);
    }


    public static void mergeSort(Comparable[] a) {
        int n = a.length;
        Comparable[] tmp = new Comparable[n];
        mergeSort(a, tmp, 0, n-1);
        assert isSorted(a);
    }

    private static boolean isSorted(Comparable[] a) {
        return isSorted(a, 0, a.length-1);
    }

    private static boolean isSorted(Comparable[] a, int low, int high) {
        for (int i = low+1; i <= high; i++) {
            if (a[i].compareTo(a[i-1]) < 0) return false;
        }
        return true;
    }

    public static void main(String[] args){
        int[] nums = In.readInts(args[0]);
        Integer[] a = new Integer[nums.length];
        for (int i = 0; i < nums.length; i++) {
            a[i] = nums[i];
        }
        mergeSort(a);
        StdOut.println(a[0]);
        StdOut.println(a.length);

    }

}
