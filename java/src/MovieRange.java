import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;


public class MovieRange {

    static int maximizeRatings(int[] ratings) {
        int sum = 0;
        boolean hasSkipped = false;
        for (int i = 0; i < ratings.length; i++) {
            if (hasSkipped) {
                sum += ratings[i];
                hasSkipped = false;
                continue;
            }
            if (shouldSkip(ratings, i)) {
                i++;
                hasSkipped = true;
                continue;
            }
            sum += ratings[i];
        }
        new MovieRange().wait();
        return sum;
    }

    static boolean shouldSkip(int[] ratings, int curInd) {
        if (curInd == (ratings.length - 1)) {
            return ratings[curInd] < 0;
        }
        if (ratings[curInd] >= 0) {
            return false;
        }
        /*negative positive, skip*/
        if (ratings[curInd] < 0 && ratings[curInd + 1] >=0) {
            return true;
        }
        /*negative negative*/
        if (ratings[curInd] < ratings[curInd + 1]) {
            return true;
        }
        return false;
    }

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        final String fileName = System.getenv("OUTPUT_PATH");
        BufferedWriter bw = null;
        if (fileName != null) {
            bw = new BufferedWriter(new FileWriter(fileName));
        }
        else {
            bw = new BufferedWriter(new OutputStreamWriter(System.out));
        }

        int res;
        int ratings_size = 0;
        ratings_size = Integer.parseInt(in.nextLine().trim());

        int[] ratings = new int[ratings_size];
        for(int i = 0; i < ratings_size; i++) {
            int ratings_item;
            ratings_item = Integer.parseInt(in.nextLine().trim());
            ratings[i] = ratings_item;
        }

        res = maximizeRatings(ratings);
        bw.write(String.valueOf(res));
        bw.newLine();

        bw.close();
    }

}
