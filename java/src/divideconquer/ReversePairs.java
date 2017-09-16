package divideconquer;

import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class ReversePairs {

    private void merge(int[] a, int[] tmp, int low, int mid, int high) {
        for (int k = low; k <= high; k++) {
            tmp[k] = a[k];
        }
        int i = low, j = mid + 1;
        for (int k = low; k <= high; k++) {
            if (i > mid) a[k] = tmp[j++];
            else if ( j > high) a[k] = tmp[i++];
            else if (tmp[i] <= tmp[j]) a[k] = tmp[i++];
            else a[k] = tmp[j++];
        }
    }

    private int reversePairs(int[] a, int[] tmp, int low, int high) {
        if ( high <= low) return 0;
        int mid = low + (high - low) / 2;
        int leftInversionCount = reversePairs(a, tmp, low, mid);
        int rightInversionCount = reversePairs(a, tmp, mid + 1, high);
        int splitInversionCount = 0;
        int j = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (j <= high && a[i] > a[j] * 2L) {
                splitInversionCount += mid - i + 1;
                j++;
            }
        }
        merge(a, tmp, low, mid, high);
        return leftInversionCount + rightInversionCount + splitInversionCount;
    }

    public int reversePairs(int[] nums) {
        int[] tmp = new int[nums.length];
        int inversions = reversePairs(nums, tmp, 0, nums.length-1);
        return inversions;
    }

    public static void main(String[] args){
        int[] nums = new In(args[0]).readAllInts();
        StdOut.println(new ReversePairs().reversePairs(nums));
    }

}
