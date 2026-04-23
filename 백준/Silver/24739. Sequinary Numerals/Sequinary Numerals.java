import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st = new StringTokenizer("");

    public static long gcd(long a, long b) {
        if(a < b) {
            return gcd(b, a);
        }
        if(a%b != 0) {
            return gcd(b, a%b);
        }
        return b;
    }

    public static void main(String[] args) throws Exception {
        char[] line = br.readLine().toCharArray();

        long parent = 1L << (line.length - 1);
        long child = 0;
        long g = 1;
        for(int i=1;i<line.length;i++) {
            g *= 3;
        }
        long h = 1;
        for(char c : line) {
            child += g * h * (c - '0');
            g /= 3;
            h *= 2;
        }

        if(child == 0) {
            bw.write("0");
        }
        else {
            long cd = gcd(child, parent);
            child /= cd;
            parent /= cd;
            bw.write((child/parent) + " ");
            if(parent != 1) {
                bw.write((child%parent) + "/" + parent);
            }
        }

        bw.close();
    }



}