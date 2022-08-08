import java.util.Scanner;
import java.lang.Math;

class Golems {
    /*
     * Returns 0 if 2^a * 3^b = 2^c * 3^d
     *        -1 if 2^a * 3^b < 2^c * 3^d
     *         1 if 2^a * 3^b > 2^c * 3^d.
     *
     * This will run into precision issues for large a, b, c and d,
     * but for the range of values in this question it is OK.
     */
    private static int compare(int a, int b, int c, int d) {
        if (a == c && b == d) return 0;
        if ((a - c) * Math.log(2) + (b - d) * Math.log(3) <= 0) return -1;
        return 1;
    }

    private static int count_ways(int m, int n) {
        // Write your code here!
        return 0;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        
        System.out.println(count_ways(m, n));
    }
}
