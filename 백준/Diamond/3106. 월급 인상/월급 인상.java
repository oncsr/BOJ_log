import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int N;
    static int[] arr, seg, lazy;
    static int[] parent, realDepth, depth, size, chainNum, chainIndex, hldOrder;
    static List<Integer>[] chain, tree;
    static int orderCount = 0;

    public static void main(String[] args) throws Exception {
        N = Integer.parseInt(br.readLine()) + 1;
        arr = new int[N+1];
        arr[1] = Integer.parseInt(br.readLine());
        parent = new int[N+1];
        tree = new List[N+1];
        realDepth = new int[N+1];
        for(int i=1;i<=N;i++) {
            tree[i] = new ArrayList<>();
        }
        for(int i=2;i<=N;i++) {
            st = new StringTokenizer(br.readLine());
            arr[i] = Integer.parseInt(st.nextToken());
            parent[i] = Integer.parseInt(st.nextToken()) + 1;
            realDepth[i] = realDepth[parent[i]] + 1;
            tree[parent[i]].add(i);
        }

        // dfs + hld (depth는 dfs에서 하자)
        size = new int[N+1];
        dfs(1);
        depth = new int[N+1];
        chainNum = new int[N+1];
        chainIndex = new int[N+1];
        hldOrder = new int[N+1];
        chain = new List[N+1];
        for(int i=1;i<=N;i++) {
            chain[i] = new ArrayList<>();
        }
        hld(1, 1, 0);

        // query
        seg = new int[N*4];
        lazy = new int[N*4];
        update(1, N, hldOrder[1], hldOrder[1], arr[1], 1);
        for(int i=2;i<=N;i++) {
            int cur = i, val = arr[i], originDepth = realDepth[cur];
            int answer = -1;
            while(cur != 0) {
                boolean res = find(1, N, hldOrder[chainNum[cur]], hldOrder[cur], val, 1);
                if(res) {
                    int s = 0, e = chainIndex[cur], m = (s+e+1) >> 1;
                    while(s < e) {
                        if(find(1, N, hldOrder[chain[chainNum[cur]].get(m)], hldOrder[cur], val, 1)) {
                            s = m;
                        }
                        else {
                            e = m-1;
                        }
                        m = (s+e+1) >> 1;
                    }
                    answer = originDepth - realDepth[chain[chainNum[cur]].get(m)] - 1;
                    break;
                }
                else {
                    cur = parent[chainNum[cur]];
                }
            }
            if(answer == -1) {
                answer = originDepth;
            }
            bw.write(answer + "\n");

            cur = i;
            while(cur != 0) {
                update(1, N, hldOrder[chainNum[cur]], hldOrder[cur], val, 1);
                cur = parent[chainNum[cur]];
            }
        }

        bw.close();
    }

    public static void dfs(int cur) {
        size[cur] = 1;
        for(int nxt : tree[cur]) {
            dfs(nxt);
            size[cur] += size[nxt];
        }
    }

    public static void hld(int cur, int chroot, int dep) {
        depth[cur] = dep;
        chainNum[cur] = chroot;
        chainIndex[cur] = chain[chroot].size();
        chain[chroot].add(cur);

        hldOrder[cur] = ++orderCount;
        int heavy = -1;
        for(int nxt : tree[cur]) if(heavy == -1 || (size[nxt] > size[heavy])) {
            heavy = nxt;
        }

        if(heavy != -1) {
            hld(heavy, chroot, dep);
        }
        for(int nxt : tree[cur]) if(nxt != heavy) {
            hld(nxt, nxt, dep+1);
        }
    }

    public static void prop(int s, int e, int n) {
        if(lazy[n] != 0) {
            seg[n] = Math.max(seg[n], lazy[n]);
            if(s != e) {
                lazy[n*2] = Math.max(lazy[n*2], lazy[n]);
                lazy[n*2+1] = Math.max(lazy[n*2+1], lazy[n]);
            }
            lazy[n] = 0;
        }
    }

    public static void update(int s, int e, int l, int r, int v, int n) {
        if(l>r || l>e || r<s) return;
        prop(s, e, n);
        if(l <= s && e <= r) {
            seg[n] = Math.max(seg[n], v);
            if(s != e) {
                lazy[n*2] = Math.max(lazy[n*2], v);
                lazy[n*2+1] = Math.max(lazy[n*2+1], v);
            }
            return;
        }
        int m = (s+e) >> 1;
        update(s, m, l, r, v, n*2);
        update(m+1, e, l, r, v, n*2+1);
        seg[n] = Math.max(seg[n*2], seg[n*2+1]);
    }

    public static boolean find(int s, int e, int l, int r, int v, int n) {
        if(l>r || l>e || r<s) {
            return false;
        }
        prop(s, e, n);
        if(l <= s && e <= r) {
            return seg[n] >= v;
        }
        int m = (s+e)>>1;
        return find(s, m, l, r, v, n*2) || find(m+1, e, l, r, v, n*2+1);
    }
}
