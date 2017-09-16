package search;

public class LocalMin {

    /**
     * find the local minimum value of the distinct array and return the index
     * @param a
     * @param low
     * @param high
     * @param n the number of elements in the array, must be greater than 1
     */
    public int localMinOfArray(int[] a, int low, int high, int n) {
        int mid = low + (high - low) / 2;
        if ( (mid == 0 || a[mid - 1] > a[mid])  && (mid == n-1 || a[mid] < a[mid + 1])) {
            return mid;
        } else if (mid > 0 && a[mid - 1] < a[mid]) 
            return localMinOfArray(a, low, mid-1, n);
        else return localMinOfArray(a, mid + 1, high, n);
    }

    // public int[] localMinOfMatrix(int[][] a, int rows, int cols) {
    //     int[] result = new int[2];
        
    // }
}