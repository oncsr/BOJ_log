#include <bits/stdc++.h>
using namespace std;

const int INF = -987654321;

struct node {
    int mn, mx, pairMin, pairMax, trioMax;
};

int N, Q, a[333334]{};
node seg[1048576]{};

node mrg(node a, node b) {
    node ret;
    ret.mn = min(a.mn, b.mn);
    ret.mx = max(a.mx, b.mx);
    ret.pairMin = min({a.pairMin, b.pairMin, b.mn-a.mx});
    ret.pairMax = max({a.pairMax, b.pairMax, b.mx-a.mn});
    ret.trioMax = max({a.trioMax, b.trioMax, a.pairMax-b.mn, -b.pairMin-a.mn});
    return ret;
}

void init(int s, int e, int n) {
    if(s == e) {
        seg[n] = {a[s],a[s],-INF,INF,INF};
        return;
    }
    int m = (s+e)>>1;
    init(s,m,n<<1);
    init(m+1,e,n<<1|1);
    seg[n] = mrg(seg[n<<1], seg[n<<1|1]);
}

void upt(int s, int e, int i, int v, int n) {
    if(s == e) {
        seg[n] = {v,v,-INF,INF,INF};
        return;
    }
    int m = (s+e)>>1;
    if(i <= m) upt(s,m,i,v,n<<1);
    else upt(m+1,e,i,v,n<<1|1);
    seg[n] = mrg(seg[n<<1], seg[n<<1|1]);
}

node f(int s, int e, int l, int r, int n) {
    if(l>r || l>e || r<s) return {-INF, INF, -INF, INF, INF};
    if(l<=s && e<=r) return seg[n];
    int m = (s+e)>>1;
    return mrg(f(s,m,l,r,n<<1), f(m+1,e,l,r,n<<1|1));
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>Q;
    for(int i=1;i<=N;i++) cin>>a[i];
    init(1,N,1);
    for(int x,y,z;Q--;) {
        cin>>x>>y>>z;
        if(x == 1) upt(1,N,y,z,1);
        else cout<<f(1,N,y,z,1).trioMax<<'\n';
    }

}