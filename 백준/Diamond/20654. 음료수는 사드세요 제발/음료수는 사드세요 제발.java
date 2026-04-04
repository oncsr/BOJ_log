import java.io.*;
import java.util.*;

public class Main {
    static final int LIMIT = 100_000;
    static class SegmentTree {
        long[] count, total;
        SegmentTree(int size) {
            count = new long[size*4];
            total = new long[size*4];
        }

        void update(int s, int e, int i, long v, int n) {
            if(s == e) {
                count[n] += v;
                total[n] += v*i;
                return;
            }
            int m = (s+e) >> 1;
            if(i <= m) update(s, m, i, v, n*2);
            else update(m+1, e, i, v, n*2+1);
            count[n] = count[n*2] + count[n*2+1];
            total[n] = total[n*2] + total[n*2+1];
        }

        long find(int s, int e, long v, int n) {
            if(s == e) {
                if(v > count[n]) return (long)3e18;
                return v * s;
            }
            int m = (s+e) >> 1;
            if(v > count[n*2]) {
                return total[n*2] + find(m+1, e, v - count[n*2], n*2+1);
            }
            return find(s, m, v, n*2);
        }
    }
    static class Query implements Comparable<Query> {
        long g, L;
        int num, lo, hi, mid;
        Query(int num, long g, long L) {
            this.num = num;
            this.g = g;
            this.L = L;
            this.lo = 0;
            this.hi = LIMIT;
            this.mid = (this.lo + this.hi + 1) >> 1;
        }

        @Override
        public int compareTo(Query o) {
            return o.mid - this.mid;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int N, M;
    static int[][] drinks;
    static Query[] queries;
    static int[] answer;
    static SegmentTree seg;

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        drinks = new int[N][];
        for(int i=0;i<N;i++) {
            st = new StringTokenizer(br.readLine());
            int d = Integer.parseInt(st.nextToken());
            int p = Integer.parseInt(st.nextToken());
            int l = Integer.parseInt(st.nextToken());
            drinks[i] = new int[]{d, p, l};
        }
        Arrays.sort(drinks, (a,b) -> b[0]-a[0]);

        queries = new Query[M];
        answer = new int[M];
        for(int i=0;i<M;i++) {
            st = new StringTokenizer(br.readLine());
            queries[i] = new Query(i, Long.parseLong(st.nextToken()), Long.parseLong(st.nextToken()));
        }

        while(true) {
            int diff = 0;
            seg = new SegmentTree(LIMIT);

            Arrays.sort(queries);
            int pos = 0;
            for(int i=0;i<M;i++) if(queries[i].lo < queries[i].hi) {
                diff++;
                while(pos<N && drinks[pos][0] >= queries[i].mid) {
                    int p = drinks[pos][1], l = drinks[pos][2];
                    seg.update(1, LIMIT, p, l, 1);
                    pos++;
                }
                if(seg.find(1, LIMIT, queries[i].L, 1) <= queries[i].g) queries[i].lo = queries[i].mid;
                else queries[i].hi = queries[i].mid - 1;
                queries[i].mid = (queries[i].lo + queries[i].hi + 1) >> 1;
                if(queries[i].lo >= queries[i].hi) {
                    answer[queries[i].num] = queries[i].mid == 0 ? -1 : queries[i].mid;
                }
            }

            if(diff == 0) {
                break;
            }
        }

        for(int i=0;i<M;i++) {
            bw.write(answer[i] + "\n");
        }
        bw.close();
    }
}
