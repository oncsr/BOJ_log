import java.io.*;
import java.util.*;

public class Main {

    static class Query implements Comparable<Query> {
        int num, x, y, lo, hi, mid;
        long j;
        Query(int num, int x, int y, long j) {
            this.num = num;
            this.x = x;
            this.y = y;
            this.j = j;
            this.lo = 1;
        }

        @Override
        public int compareTo(Query o) {
            return this.mid - o.mid;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int N, M, Q;
    static int[][] arr;
    static Query[] queries;
    static int[] answer, realValue;
    static long[] seg, lazy, realPos;
    static TreeMap<Integer, Integer> compressedPos, compressedValue;

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        Q = Integer.parseInt(st.nextToken());

        arr = new int[M][];
        compressedPos = new TreeMap<>();
        compressedValue = new TreeMap<>();
        for(int i=0;i<M;i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken()) + 1;
            int v = Integer.parseInt(st.nextToken());
            compressedPos.put(a, 0);
            compressedPos.put(b, 0);
            compressedValue.put(v, 0);
            arr[i] = new int[]{a, b, v};
        }

        Arrays.sort(arr, (a,b) -> a[2]-b[2]);

        queries = new Query[Q];
        for(int i=0;i<Q;i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken()) + 1;
            long j = Long.parseLong(st.nextToken());
            queries[i] = new Query(i, x, y, j);
            compressedPos.put(x, 0);
            compressedPos.put(y, 0);
        }

        compressedPos.put(1, 0);
        compressedPos.put(N+1, 0);

        int posCount = 0;
        for(int key : compressedPos.keySet()) {
            compressedPos.put(key, ++posCount);
        }
        realPos = new long[posCount+1];
        for(int key : compressedPos.keySet()) {
            realPos[compressedPos.get(key)] = key;
        }

        int valueCount = 0;
        for(int key : compressedValue.keySet()) {
            compressedValue.put(key, ++valueCount);
        }
        realValue = new int[valueCount+1];
        for(int key : compressedValue.keySet()) {
            realValue[compressedValue.get(key)] = key;
        }

        for(int i=0;i<M;i++) {
            arr[i][0] = compressedPos.get(arr[i][0]);
            arr[i][1] = compressedPos.get(arr[i][1]);
            arr[i][2] = compressedValue.get(arr[i][2]);
        }
        for(int i=0;i<Q;i++) {
            queries[i].x = compressedPos.get(queries[i].x);
            queries[i].y = compressedPos.get(queries[i].y);
            queries[i].hi = valueCount;
            queries[i].mid = (queries[i].lo + queries[i].hi) >> 1;
        }

        answer = new int[Q];
        int remains = Q;
        while(remains > 0) {
            seg = new long[posCount*4];
            lazy = new long[posCount*4];
            Arrays.sort(queries);
            int pos = 0;
            for(int i=0;i<Q;i++) if(queries[i].lo < queries[i].hi) {
                while(pos<M && arr[pos][2] <= queries[i].mid) {
                    update(1, posCount, arr[pos][0], arr[pos][1]-1, 1);
                    pos++;
                }
                if(find(1, posCount, queries[i].x, queries[i].y-1, 1) < queries[i].j) {
                    queries[i].lo = queries[i].mid + 1;
                }
                else {
                    queries[i].hi = queries[i].mid;
                }
                queries[i].mid = (queries[i].lo + queries[i].hi) >> 1;
                if(queries[i].lo >= queries[i].hi) {
                    remains--;
                    answer[queries[i].num] = realValue[queries[i].mid];
                }
            }
        }

        for(int i=0;i<Q;i++) {
            bw.write(answer[i] + "\n");
        }
        bw.close();
    }

    public static void propagation(int s, int e, int n) {
        if(lazy[n] != 0) {
            seg[n] += lazy[n] * (realPos[e+1] - realPos[s]);
            if(s != e) {
                lazy[n*2] += lazy[n];
                lazy[n*2+1] += lazy[n];
            }
            lazy[n] = 0;
        }
    }

    public static void update(int s, int e, int l, int r, int n) {
        propagation(s, e, n);
        if(l>r || l>e || r<s) return;
        if(l <= s && e <= r) {
            seg[n] += realPos[e+1] - realPos[s];
            if(s != e) {
                lazy[n*2]++;
                lazy[n*2+1]++;
            }
            return;
        }
        int m = (s+e) >> 1;
        update(s, m, l, r, n*2);
        update(m+1, e, l, r, n*2+1);
        seg[n] = seg[n*2] + seg[n*2+1];
    }

    public static long find(int s, int e, int l, int r, int n) {
        propagation(s, e, n);
        if(l>r || l>e || r<s) return 0;
        if(l <= s && e <= r) return seg[n];
        int m = (s+e) >> 1;
        return find(s, m, l, r, n*2) + find(m+1, e, l, r, n*2+1);
    }
}