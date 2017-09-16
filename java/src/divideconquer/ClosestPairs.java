package divideconquer;

import edu.princeton.cs.algs4.Point2D;

import java.util.Arrays;

public class ClosestPairs {

    public double closestDist(Point2D[] points) {
        if (points.length < 2) throw new IllegalArgumentException("Input array length must be greater than 2");
        int n = points.length;

        // sort by x-coordinate and check for coincident pairs
        Point2D[] pointsByX = new Point2D[n];
        for(int i = 0; i < n-1; i++) {
            pointsByX[i] = points[i];
            if (points[i].equals(points[i+1])) {
                return 0;
            }
        }
        pointsByX[n-1] = points[n-1];
        Arrays.sort(pointsByX, Point2D.X_ORDER);

        // sort by y-coordinate
        Point2D[] pointsByY = new Point2D[n];
        for (int i = 0; i < n; i++) {
            pointsByY[i] = points[i];
        }
        Arrays.sort(pointsByY, Point2D.Y_ORDER);

        // auxiliary array
        Point2D[] aux = new Point2D[n];

        return cloestDist(pointsByX, pointsByY, aux, 0, n-1);
    }

    private double cloestDist(Point2D[] pointsByX, Point2D[] pointsByY, Point2D[] aux, int low, int high) {
        int n = (high - low) + 1;
        if (n == 1) return Double.POSITIVE_INFINITY;
        if (n == 2) return pointsByX[low].distanceTo(pointsByY[high]);

        int mid = low + (high - low) / 2;
        Point2D median = pointsByX[mid];

        // compute closest pairs with both endpoints in left half and right half
        double leftMin = cloestDist(pointsByX, pointsByY, aux, low, mid);
        double rightMin = cloestDist(pointsByX, pointsByY, aux, mid + 1, high);
        double delta = Math.min(leftMin, rightMin);

        // aux[0..m-1] is the sequence of points within delta of the x-coordinate median point, sorted by y-coordinate
        int m = 0;
        for (int i = low; i <= high; i++) {
            if (Math.abs(pointsByY[i].x() - median.x()) < delta) {
                aux[m++] = pointsByY[i];
            }
        }

        // compare each points to its neighbourhood within delta in y-coordinate
        for (int i = 0; i < m; i++) {
            // a geometric packing argument shows that this loop iterates at most 7 times
            for (int j = i + 1; (j < m) && Math.abs(aux[j].y() - aux[i].y()) < delta; j++) {
                double distance = aux[j].distanceTo(aux[i]);
                if (distance < delta) {
                    delta = distance; // upgrade the current minimal distane
                }
            }
        }

        return delta;
    }

}
