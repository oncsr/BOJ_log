#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
ll A[1000001]{}, seg[2097152]{}, lazy[2097152]{};
vector<int> idx = {0};

ll init(int s, int e, int n){
    if(s == e) return seg[n] = A[s];
    int m=(s+e)>>1;
    return seg[n] = init(s,m,n*2) + init(m+1,e,n*2+1);
}

void prop(int s, int e, int n){
    if(lazy[n]){
        ll &v = lazy[n];
        seg[n] += v*(e-s+1);
        if(s != e){
            lazy[n*2] += v;
            lazy[n*2+1] += v;
        }
        v = 0;
    }
}

void upt(int s, int e, int l, int r, ll v, int n){
    prop(s,e,n);
    if(l>r || l>e || r<s) return;
    if(l<=s && e<=r) {
        seg[n] += v*(e-s+1);
        if(s != e){
            lazy[n*2] += v;
            lazy[n*2+1] += v;
        }
        return;
    }
    int m=(s+e)>>1;
    upt(s,m,l,r,v,n*2);
    upt(m+1,e,l,r,v,n*2+1);
    seg[n] = seg[n*2] + seg[n*2+1];
}

ll find(int s, int e, int l, int r, int n){
    prop(s,e,n);
    if(l>r || l>e || r<s) return 0;
    if(l<=s && e<=r) return seg[n];
    int m=(s+e)>>1;
    return find(s,m,l,r,n*2) + find(m+1,e,l,r,n*2+1);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>M;
    for(int i=1,a,b,c;i<=M;i++){
        cin>>a>>b>>c;
        idx.push_back(a);
        A[i] = c;
    }
    init(1,M,1);
    
    int o,x,y,z;
    for(cin>>o>>x>>y;o;cin>>o>>x>>y){
        x = upper_bound(idx.begin(), idx.end(), x) - idx.begin() - 1;
        y = upper_bound(idx.begin(), idx.end(), y) - idx.begin() - 1;
        if(o == 2){
            cin>>z;
            if(x<=y) upt(1,M,x,y,z,1);
            else{
                upt(1,M,x,M,z,1);
                upt(1,M,1,y,z,1);
            }
        }
        else{
            ll ans = 0;
            if(x<=y) ans += find(1,M,x,y,1);
            else ans += find(1,M,x,M,1) + find(1,M,1,y,1);
            cout<<ans<<'\n';
        }
    }
    
}