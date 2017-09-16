import javax.security.auth.login.AppConfigurationEntry;

import edu.princeton.cs.algs4.StdOut;

public class APITest {

    private int[] getarray() {
        int[] a = {1, 2, 3};
        return a;
    }

    public static void main(String[] args) {
        APITest test = new APITest();
        int[] a = test.getarray();
        int[] b = new int[0];
        StdOut.println(a);
        StdOut.println(a[1]);
    }
}