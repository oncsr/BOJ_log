import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int N, P;

    static int[] sieve;
    static Set<Integer>[] bag;

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        P = Integer.parseInt(st.nextToken());

        sieve = new int[10000001];
        for(int i=2;i*i<=10000000;i++) {
            if(sieve[i] == 0) {
                for(int j=i*i;j<=10000000;j+=i) {
                    if(sieve[j] == 0) {
                        sieve[j] = i;
                    }
                }
            }
        }

        if(P > 100) {
            int count = 1;
            if(N == 1) {
                bw.write(P + "\n");
                bw.close();
                return;
            }

            for(int x=2;x*P<=1000000000;x++) {
                if(sieve[x] >= P || (sieve[x] == 0 && x >= P)) {
                    count++;
                }
                if(count == N) {
                    bw.write((x*P) + "\n");
                    bw.close();
                    return;
                }
            }

            bw.write("0");
            bw.close();
            return;
        }

        bag = new Set[10];
        for(int i=1;i<=9;i++) {
            bag[i] = new TreeSet<>();
        }
        for(int i=2;i<P;i++) if(sieve[i] == 0) {
            for(int j=8;j>=1;j--) {
                for(int k : bag[j]) {
                    if((long)k * i > (long)1e9) break;
                    bag[j+1].add(k*i);
                }
            }
            bag[1].add(i);
        }

        long s = P, e = 1000000001, m = (s+e) >> 1;
        while(s < e) {
            long count = m/P;
            for(int i=1;i<=9;i++) {
                for(int j : bag[i]) {
                    if(m/P/j == 0) break;
                    count += (m/P/j) * (i%2 == 1 ? -1 : 1);
                }
            }

            if(count < N) {
                s = m+1;
            }
            else {
                e = m;
            }
            m = (s+e) >> 1;
        }

        bw.write((m == 1000000001 ? 0 : m) + "\n");
        bw.close();
    }
}