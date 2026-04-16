#include <bits/stdc++.h>
using namespace std;

int N, M, b[300000]{}, g[300000]{}, w[300000]{}, seg[8388608]{};

int init(int s, int e, int n) {
    if(s == e) return seg[n] = 1;
    int m = (s+e)>>1;
    return seg[n] = init(s,m,n*2) + init(m+1,e,n*2+1);
}

void remove(int s, int e, int i, int n) {
    if(s == e) {
        seg[n] = 0;
        return;
    }
    int m = (s+e)>>1;
    if(i <= m) remove(s,m,i,n*2);
    else remove(m+1,e,i,n*2+1);
    seg[n] = seg[n*2] + seg[n*2+1];
}

int find(int s, int e, int v, int n) {
    if(s == e) return s;
    int m = (s+e)>>1;
    if(seg[n*2] >= v) return find(s,m,v,n*2);
    return find(m+1,e,v-seg[n*2],n*2+1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin>>N;
    for(int i=0;i<N;i++) cin>>b[i];
    for(int i=0;i<N;i++) cin>>g[i], g[i] += b[i];
    for(int i=0;i<N;i++) cin>>w[i], w[i] += g[i];
    sort(b, b+N);
    sort(g, g+N);
    sort(w, w+N);

    init(1,3000000,1);
    for(cin>>M;M--;) {
        int a;
        cin>>a;
        a = find(1,3000000,a,1);
        int black = N - (lower_bound(b, b+N, a) - b);
        int gray = N - (lower_bound(g, g+N, a) - g);
        int white = N - (lower_bound(w, w+N, a) - w);
        int ans = black + (gray-black)*2 + (white-gray)*5;
        cout<<ans<<'\n';
        remove(1,3000000,a,1);
    }

}