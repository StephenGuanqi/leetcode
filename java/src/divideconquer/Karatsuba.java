package divideconquer;

import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.Stopwatch;

import java.math.BigInteger;
import java.util.Random;

public class Karatsuba {

    public static void main(String args[]) {
        double elapsed;
        Random random = new Random();
        int N = 100;
        // BigInteger a = new BigInteger(N, random);
        // StdOut.printf("A: %s   %s\n", a.toString(2), a.toString());
        // BigInteger b = new BigInteger(N, random);
        // StdOut.printf("B: %s   %s\n", b.toString(2), b.toString());
        BigInteger a = new BigInteger("3141592653589793238462643383279502884197169399375105820974944592");
        BigInteger b = new BigInteger("2718281828459045235360287471352662497757247093699959574966967627");

        Stopwatch timer = new Stopwatch();
        BigInteger c = karatsuba(a, b);
        StdOut.printf("C: %s   %s\n", c.toString(2), c.toString());
        elapsed = timer.elapsedTime();
        StdOut.printf("Time : %.10f\n", elapsed);

        timer = new Stopwatch();
        BigInteger d = a.multiply(b);
        StdOut.printf("D: %s   %s\n", d.toString(2), d.toString());
        elapsed = timer.elapsedTime();
        StdOut.printf("Time: %.10f\n", elapsed);
        
        StdOut.println((c.equals(d)));
    }

    public static BigInteger karatsuba(BigInteger x, BigInteger y) {
        int N = Math.max(x.bitLength(), y.bitLength());
        if (N < 10) return x.multiply(y);
        // number of bits divided by 2, rounded up
        N = (N / 2) + (N % 2);
        BigInteger a = x.shiftRight(N);
        BigInteger b = x.subtract(a.shiftLeft(N));
        BigInteger c = y.shiftRight(N);
        BigInteger d = y.subtract(c.shiftLeft(N));
        BigInteger ac = karatsuba(a, c);
        BigInteger bd = karatsuba(b, d);
        BigInteger abcd = karatsuba(a.add(b), c.add(d));
        return bd.add(abcd.subtract(ac).subtract(bd).shiftLeft(N).add(ac.shiftLeft(2*N)));
    }
}