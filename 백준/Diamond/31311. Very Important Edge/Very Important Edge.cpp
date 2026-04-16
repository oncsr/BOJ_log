#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dep[100001]{}, sz[100001]{}, par[100001]{}, cn[100001]{}, ci[100001]{};
vector<vector<int>> C(100001);
vector<vector<pair<int, int>>> V(100001);
int ord[100001]{}, root[100001]{}, cnt = 0, N;
vector<int> seg(262145, 1e6);
vector<int> lazy(262145, 1e6);

int find(int x) {
    if (x == root[x])    return x;
    return root[x] = find(root[x]);
}

void dfs(int n, int p) {
    sz[n] = 1, par[n] = p;
    for (auto [i, c] : V[n]) {
        if (i == p)  continue;
        dfs(i, n);
        sz[n] += sz[i];
    }
}

void hld(int n, int p, int s, int d) {
    dep[n] = d, cn[n] = s, ci[n] = C[s].size();
    C[s].push_back(n);
    ord[n] = ++cnt;
    int h = -1;
    for (auto [i, c] : V[n])  if (i != p && (h == -1 || sz[i] > sz[h]))    h = i;
    if (h != -1) hld(h, n, s, d);
    for (auto [i, c] : V[n])  if (i != p && i != h)    hld(i, n, i, d + 1);
}

void prop(int s, int e, int n) {
    if (lazy[n] != 1e6) {
        seg[n] = min(seg[n], lazy[n]);
        if (s != e) {
            lazy[n * 2] = min(lazy[n * 2], lazy[n]);
            lazy[n * 2 + 1] = min(lazy[n * 2 + 1], lazy[n]);
        }
        lazy[n] = 1e6;
    }
}

void upt(int s, int e, int l, int r, int v, int n) {
    prop(s, e, n);
    if (l > r || l > e || r < s)   return;
    if (l <= s && e <= r) {
        seg[n] = min(seg[n], v);
        if (s != e) {
            lazy[n * 2] = min(lazy[n * 2], v);
            lazy[n * 2 + 1] = min(lazy[n * 2 + 1], v);
        }
        return;
    }
    int m = (s + e) >> 1;
    upt(s, m, l, r, v, n * 2); upt(m + 1, e, l, r, v, n * 2 + 1);
}

void prop_clear(int s, int e, int n) {
    prop(s, e, n);
    if (s == e)    return;
    int m = (s + e) >> 1;
    prop_clear(s, m, n * 2);    prop_clear(m + 1, e, n * 2 + 1);
}

int cal(int s, int e, int i, int n) {
    if (s == e)  return seg[n];
    int m = (s + e) >> 1;
    if (i <= m)  return cal(s, m, i, n * 2);
    return cal(m + 1, e, i, n * 2 + 1);
}

void sol(int a, int b, int c) {
    while (cn[a] != cn[b]) {
        if (dep[a] > dep[b]){
            upt(1, N, ord[cn[a]], ord[a], c, 1);
            a = par[cn[a]];
        }
        else{
            upt(1, N, ord[cn[b]], ord[b], c, 1);
            b = par[cn[b]];
        }
    }
    int g = ci[a] < ci[b] ? a : b, d = g == a ? b : a;
    upt(1,N,ord[g]+1,ord[d],c,1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)   root[i] = i;
    vector<tuple<int, int, int, int>> E;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        E.emplace_back(c, a, b, i);
    }
    sort(E.begin(), E.end());

    ll mst = 0;
    vector<tuple<int, int, int, int>> used, unused;
    for (auto [c, a, b, n] : E) {
        int x = find(a), y = find(b);
        if (x == y) { unused.emplace_back(c, a, b, n); continue; }
        used.emplace_back(c, a, b, n);
        mst += c;
        root[x] = y;
        V[a].emplace_back(b, c);
        V[b].emplace_back(a, c);
    }
    dfs(1, 0);   hld(1, 0, 1, 0);

    for (auto [c, a, b, n] : unused)    sol(a,b,c);
    prop_clear(1, N, 1);
    ll ans = unused.size() ? mst : 0;
    for (auto [c, a, b, n] : used) {
        int d = par[a] == b ? a : b;
        int m = cal(1, N, ord[d], 1);
        ans = max(ans, mst - c + m);
    }
    cout << ans;

}