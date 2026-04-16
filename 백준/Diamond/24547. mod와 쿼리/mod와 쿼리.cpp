#pragma GCC optimize("Ofast, unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, Q, sq=1359;
ll seg[100001][2]{};
ll a[100001]{}, cnt[100001]{}, q1[100001]{};

void upd(int n, int i, ll v) {
    for(;i<100001;i+=i&-i) seg[i][n] += v;
}

ll f(int n, int i) {
    ll ret = 0;
    for(;i>0;i-=i&-i) ret += seg[i][n];
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>a[i];
        cnt[a[i]]++;
        upd(0, a[i], 1);
        upd(1, a[i], a[i]);
    }

    for(int i=1;i<sq;i++) for(int j=1;j<=N;j++) q1[i] += a[j] % i;

    for(cin>>Q;Q--;) {
        int op, i, x;
        cin>>op;
        if(op == 3) {
            cin>>i>>x;
            ll prev = a[i];
            for(int k=1;k<sq;k++) q1[k] += x%k - prev%k;
            cnt[prev]--;
            cnt[x]++;
            a[i] = x;
            upd(0, prev, -1);
            upd(1, prev, -prev);
            upd(0, x, 1);
            upd(1, x, x);
        }
        else {
            cin>>x;
            if(op == 1) {
                if(x < sq) cout<<q1[x]<<'\n';
                else {
                    ll ans = 0;
                    for(int k=1;(k-1)*x<=100000;k++) {
                        ll c = f(0, min(100000, k*x-1)) - f(0, max(1,(k-1)*x)-1);
                        ll s = f(1, min(100000, k*x-1)) - f(1, max(1,(k-1)*x)-1);
                        ans += s - c*(k-1)*x;
                    }
                    cout<<ans<<'\n';
                }
            }
            else {
                ll ans = N*x;
                if(x <= 4) {
                    for(int p=1;p<=x;p++) ans -= cnt[p] * (x/p) * p;
                }
                else {
                    ans -= cnt[1] * x;
                    ll prev = x, last = x+1, p = 2;
                    for(;p<=x/p;p++) {
                        ll q = x/p;
                        ll s = f(1, prev) - f(1, q);
                        ans -= s*(p-1);
                        ans -= cnt[p] * q * p;
                        prev = q;
                        last = q+1;
                    }
                    if(p < last) {
                        ans -= (f(1, last-1) - f(1, p-1)) * (p-1);
                    }
                }
                cout<<ans<<'\n';
            }
        }
    }

}