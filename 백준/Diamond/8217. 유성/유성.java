import java.io.*;
import java.util.*;

public class Main {

    static class IOManager {
        static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        static StringTokenizer st = new StringTokenizer("");

        private IOManager(){}

        static String nextLine() throws Exception {
            return br.readLine();
        }

        static String nextToken() throws Exception {
            while (!st.hasMoreTokens()) {
                st = new StringTokenizer(nextLine());
            }
            return st.nextToken();
        }

        static int nextInt() throws Exception {
            return Integer.parseInt(nextToken());
        }

        static long nextLong() throws Exception {
            return Long.parseLong(nextToken());
        }

        static double nextDouble() throws Exception {
            return Double.parseDouble(nextToken());
        }

        static void write(String content) throws Exception {
            bw.write(content);
        }

        public static void close() throws Exception {
            bw.flush();
            bw.close();
            br.close();
        }
    }

    //

    static class Country implements Comparable<Country> {
        long target;
        List<Integer> meteors;
        int lo, hi, mid, num;

        Country(int num) {
            this.num = num;
            meteors = new ArrayList<>();
        }

        @Override
        public int compareTo(Country o) {
            return this.mid - o.mid;
        }
    }

    static class SegmentTree {
        long[] tree;

        SegmentTree() {
        }

        void init(int size) {
            tree = new long[size * 4];
        }

        void update(int s, int e, int i, long v, int n) {
            if (s == e) {
                tree[n] += v;
                return;
            }
            int m = (s + e) >> 1;
            if (i <= m) {
                update(s, m, i, v, n * 2);
            } else {
                update(m + 1, e, i, v, n * 2 + 1);
            }
            tree[n] = tree[n * 2] + tree[n * 2 + 1];
        }

        long rangeSum(int s, int e, int l, int r, int n) {
            if (l > r || l > e || r < s) {
                return 0;
            }
            if (l <= s && e <= r) {
                return tree[n];
            }
            int m = (s + e) >> 1;
            return rangeSum(s, m, l, r, n * 2) + rangeSum(m + 1, e, l, r, n * 2 + 1);
        }
    }

    static int N, M, Q;
    static PriorityQueue<Country> countries;
    static SegmentTree seg = new SegmentTree();
    static int[][] works;
    static int[] answer;

    public static void main(String[] args) throws Exception {
        N = IOManager.nextInt();
        M = IOManager.nextInt();
        Country[] tempCountries = new Country[N];
        for (int i = 0; i < N; i++) {
            tempCountries[i] = new Country(i + 1);
        }

        for (int i = 1; i <= M; i++) {
            int num = IOManager.nextInt();
            tempCountries[num - 1].meteors.add(i);
        }

        for (int i = 0; i < N; i++) {
            tempCountries[i].target = IOManager.nextInt();
        }

        Q = IOManager.nextInt();
        countries = new PriorityQueue<>();
        for (int i = 0; i < N; i++) {
            tempCountries[i].lo = 0;
            tempCountries[i].hi = Q;
            tempCountries[i].mid = Q >> 1;
            countries.add(tempCountries[i]);
        }

        works = new int[Q][];
        for (int i = 0; i < Q; i++) {
            works[i] = new int[]{IOManager.nextInt(), IOManager.nextInt(), IOManager.nextInt()};
        }

        answer = new int[N + 1];
        while (!countries.isEmpty()) {
            seg.init(M);
            PriorityQueue<Country> temp = new PriorityQueue<>();
            for (int i = 0; i < Q; i++) {
                int left = works[i][0], right = works[i][1], value = works[i][2];
                if (left <= right) {
                    seg.update(1, M, left, value, 1);
                    if (right < M) {
                        seg.update(1, M, right + 1, -value, 1);
                    }
                } else {
                    seg.update(1, M, 1, value, 1);
                    seg.update(1, M, right + 1, -value, 1);
                    seg.update(1, M, left, value, 1);
                }

                while(!countries.isEmpty() && countries.peek().mid == i) {
                    Country country = countries.poll();
                    long sum = 0;
                    for (int idx : country.meteors) {
                        sum = Math.min(country.target, sum + seg.rangeSum(1, M, 1, idx, 1));
                    }

                    if (sum >= country.target) {
                        country.hi = country.mid;
                    }
                    else {
                        country.lo = country.mid + 1;
                    }
                    country.mid = (country.lo + country.hi) >> 1;

                    if (country.lo >= country.hi) {
                        answer[country.num] = country.lo;
                    }
                    else {
                        temp.add(country);
                    }
                }
            }
            countries = temp;
        }

        for(int i=1;i<=N;i++) {
            IOManager.write(answer[i] != Q ? (answer[i]+1) + "\n" : "NIE\n");
        }

        IOManager.close();
    }

}