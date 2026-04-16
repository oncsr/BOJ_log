#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
ll seg[1048576]{};
vector<pair<ll, int>> arr;

void upt(int s, int e, int i, ll v, int n) {
    if(s == e) {
        seg[n] = v;
        return;
    }
    int m = (s+e)>>1;
    if(i <= m) upt(s,m,i,v,n<<1);
    else upt(m+1,e,i,v,n<<1|1);
    seg[n] = max(seg[n<<1], seg[n<<1|1]);
}

ll find(int s, int e, int l, int r, int n) {
    if(l>r || l>e || r<s) return 0;
    if(l<=s && e<=r) return seg[n];
    int m = (s+e)>>1;
    return max(find(s,m,l,r,n<<1), find(m+1,e,l,r,n<<1|1));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin>>N;
    for(int i=1;i<=N;i++) {
        ll a;
        cin>>a;
        arr.emplace_back(a,-i);
    }

    sort(arr.begin(), arr.end());
    for(auto [v,i]:arr) {
        i *= -1;
        upt(1,N,i,find(1,N,1,i,1)+v,1);
    }
    cout<<seg[1];

}