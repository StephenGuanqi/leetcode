package divideconquer;

import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdOut;

public class QuickSort {

    private static int compCount;

    private static void swapElem(int[] array, int i, int j) {
        if (i == j) return;
        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }

    private static int partitionWithFirst(int[] array, int start, int end) {
        int pivotPos = start;
        int pivotElem = array[pivotPos];
        int i = pivotPos + 1;
        for (int j = pivotPos + 1; j <= end; j++) {
            if (array[j] < pivotElem) {
                if (i == j) {
                    i++;
                    continue;// redundant swap
                } else {
                    swapElem(array, i, j);
                    i++;
                }

            }
        }
        swapElem(array, pivotPos, i-1);
        pivotPos = i - 1;
        return pivotPos;
    }

    private static int partitionWithFinal(int[] array, int start, int end) {
        swapElem(array, start, end);
        int pivotElem = array[start];
        int i = start + 1;
        for (int j = start + 1; j <= end; j++) {
            if (array[j] < pivotElem) {
                if (i == j) {
                    i++;
                    continue;// redundant swap
                } else {
                    swapElem(array, i, j);
                    i++;
                }
            }
        }
        swapElem(array, start, i-1);
        return i - 1;
    }

    private static int partitionWithMedianOfThree(int[] array, int start, int end) {
        int mid = (end - start) / 2 + start;
        int pivotPos = 0;
        if (array[start] < array[mid]) {
            if (array[start] > array[end]) {
                pivotPos = start;
            } else {
                pivotPos = array[mid] > array[end] ? end : mid;
            }
        } else {
            if (array[mid] > array[end]) {
                pivotPos = mid;
            } else {
                pivotPos = array[start] > array[end] ? end : start;
             }
        }
        swapElem(array, start, pivotPos);
        int pivotElem = array[start];
        int i = start + 1;
        for (int j = start + 1; j <= end; j++) {
            if (array[j] < pivotElem) {
                if (i == j) {
                    i++;
                    continue;// redundant swap
                } else {
                    swapElem(array, i, j);
                    i++;
                }
            }
        }
        swapElem(array, start, i-1);
        return i - 1;
    }

    public static void quickSort(int[] array, int start, int end) {
        if (end <= start) return;
//        int pos = partitionWithFirst(array, start, end);
//        int pos = partitionWithFinal(array, start, end);
        int pos = partitionWithMedianOfThree(array, start, end);
        compCount += end - start;
        quickSort(array, start, pos - 1);
        quickSort(array, pos + 1, end);
    }

    public static void main(String[] args) {
        int[] nums = In.readInts(args[0]);
        Integer[] a = new Integer[nums.length];
        for (int i = 0; i < nums.length; i++) {
            a[i] = nums[i];
        }
        quickSort(nums, 0, nums.length - 1);
        StdOut.println(nums[0]);
        StdOut.println(nums.length);
        StdOut.println("compare amount:" + compCount);
    }
}
