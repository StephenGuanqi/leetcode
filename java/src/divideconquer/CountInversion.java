package divideconquer;

import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

import java.nio.file.Path;

public class CountInversion {

    private static long mergeAndCount(int[] a, int[] tmp, int low, int mid, int high) {
        // debug precondition
        assert isSorted(a, low, mid);
        assert isSorted(a, mid+1, high);

        for (int k = low; k <= high; k++) {
            tmp[k] = a[k];
        }
        int i = low, j = mid + 1;
        long inversionCount = 0;
        for (int k = low; k <= high; k++) {
            if (i > mid) a[k] = tmp[j++];
            else if ( j > high) a[k] = tmp[i++];
            else if (tmp[i] <= tmp[j]) a[k] = tmp[i++]; // equals 0 condition for ties in the array
            else {
                assert inversionCount >= 0;
                inversionCount += mid - i + 1;
                a[k] = tmp[j++];
            }
        }

        assert  isSorted(a, low, high);

        return inversionCount;
    }

    private static long countInversions(int[] a, int[] tmp, int low, int high) {
        if ( high <= low) return 0;
        int mid = low + (high - low) / 2;
        long leftInversionCount = countInversions(a, tmp, low, mid);
        long rightInversionCount = countInversions(a, tmp, mid + 1, high);
        long splitInversionCount = mergeAndCount(a, tmp, low, mid, high);
        return leftInversionCount + rightInversionCount + splitInversionCount;
    }

    public static long countInversions(int[] nums) {
        int[] tmp = new int[nums.length];
        long inversions = countInversions(nums, tmp, 0, nums.length-1);
        assert isSorted(nums);
        return inversions;
    }

    public static void main(String[] args){
        int[] nums = In.readInts(args[0]); // 100,000 input, size just exceed the integer and overflow
        StdOut.println(countInversions(nums));
        StdOut.println(nums[0]);
        StdOut.println(nums.length);
    }

    private static boolean isSorted(int[] a) {
        return isSorted(a, 0, a.length-1);
    }

    private static boolean isSorted(int[] a, int low, int high) {
        for (int i = low + 1; i <= high; i++) {
            if (a[i] < a[i-1]) return false;
        }
        return true;
    }

}
