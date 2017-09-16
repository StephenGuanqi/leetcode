package divideconquer;

import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdOut;

public class CountRangeSum {



    public int countRangeSum(int[] nums, int lower, int upper) {
        int n = nums.length;
        long[] sum = new long[n + 1];
        for (int i = 1; i < n+1; i++){
            sum[i] = sum[i-1] + nums[i-1];
        }
        long[] cache = new long[n + 1];
        int count = mergeSort(sum, cache, 0, n, lower, upper);
        return count;
    }

    private int mergeSort(long[] sum, long[] cache, int start, int end, int lower, int upper) {
        if (start >= end) return 0;
        int mid = start + (end - start) / 2;
        int leftCount = mergeSort(sum, cache, start, mid, lower, upper);
        int rightCount = mergeSort(sum, cache, mid + 1, end, lower, upper);
        int splitCount = 0;
        int p = mid + 1, q = mid + 1;
        for (int i = start; i <= mid; i++) {
            while (p <= end && (sum[p] - sum[i]) < lower) p++;
            while (q <= end && (sum[q] - sum[i]) <= upper) q++;
            splitCount += q-p;
        }
        merge(sum, cache, start, mid, end);
        return leftCount + rightCount + splitCount;
    }

    private void merge(long[] sum, long[] cache, int start, int mid, int end) {
        for(int k = start; k <= end; k++) {
            cache[k] = sum[k];
        }
        int i = start, j = mid + 1;
        for (int k = start; k <= end; k++) {
            if ( j > end || i <= mid && cache[i] <= cache[j]) {
                sum[k] = cache[i++];
            } else {
                sum[k] = cache[j++];
            }
        }
    }

    public static void main(String[] args){
        int[] nums = new In(args[0]).readAllInts();
        int lower = Integer.parseInt(args[args.length - 2]);
        int upper = Integer.parseInt(args[args.length - 1]);
        StdOut.println(new CountRangeSum().countRangeSum(nums, lower, upper));
    }

}
