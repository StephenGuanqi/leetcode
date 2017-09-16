package divideconquer;

import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdOut;

import java.util.ArrayList;
import java.util.List;

/**
 * You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

 Example:

 Given nums = [5, 2, 6, 1]

 To the right of 5 there are 2 smaller elements (2 and 1).
 To the right of 2 there is only 1 smaller element (1).
 To the right of 6 there is 1 smaller element (1).
 To the right of 1 there is 0 smaller element.
 Return the array [2, 1, 1, 0].

 */
public class CountSmallerNumberAfterSelf {

    private int[] count; // count[i] related to the required result
    private int[] indexes; // indexes[i] store the indexes of sorted nums[i] in the original nums

    public List<Integer> countSmaller(int[] nums) {
        List<Integer> res = new ArrayList<>();
        count = new int[nums.length];
        indexes = new int[nums.length];
        for (int i = 0; i < indexes.length; i++) {
            indexes[i] = i;
        }
        int[] tmpIndexes = new int[indexes.length];
        int[] tmpNums = new int[nums.length];
        mergeSort(nums, tmpNums, tmpIndexes, 0, nums.length-1);

        for (int i = 0; i < count.length; i++) {
            res.add(count[i]);
        }
        return res;
    }

    // update the count[] for two halves of the subroutine
    private void mergeSort(int[] nums, int[] tmpNums, int[] tmpIndexes, int start, int end) {
        if (end <= start) return;
        int mid = start + (end - start) / 2;
        mergeSort(nums, tmpNums, tmpIndexes, start, mid);
        mergeSort(nums, tmpNums, tmpIndexes, mid+1, end);
        // update the indexes[] after subroutine
        // update the nums[] after subroutine
        // update the count[] for the split elems
        merge(nums, tmpNums, tmpIndexes, start, mid, end);
    }

    private void merge(int[] nums, int[] tmpNums, int[] tmpIndexes, int start, int mid, int end) {
        for (int k = start; k<= end; k++) {
            tmpNums[k] = nums[k];
            tmpIndexes[k] = indexes[k];
        }
        int rightCount = 0; // number of elems in the right come into the nums array before the left half
        int i = start, j = mid + 1;
        for (int k = start; k <= end; k++) {
            if (j > end || i <= mid && tmpNums[i] <= tmpNums[j]) {
                nums[k] = tmpNums[i];
                indexes[k] = tmpIndexes[i];
                count[tmpIndexes[i]] += rightCount;
                i++;
            } else {
                rightCount++;
                nums[k] = tmpNums[j];
                indexes[k] = tmpIndexes[j];
                j++;
            }
        }
    }

    public static void main(String[] args){
        int[] nums = new In(args[0]).readAllInts();
        List<Integer> res = new CountSmallerNumberAfterSelf().countSmaller(nums);
        for (Integer integer : res) {
            StdOut.println(integer);
        }
    }

}
