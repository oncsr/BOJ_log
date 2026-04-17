#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int T;
    for(cin>>T;T--;){
        ll n, m;
        cin>>n>>m;
        ll S = n*m*(n*m+1)/2;
        ll low = 1, high = m, mid = (low+high+1)>>1;
        while(low < high){
            ll v = mid*(mid+1)/2*n + n*(n-1)/2*m*mid;
            if(v > S/2) high = mid-1;
            else    low = mid;
            mid = (low+high+1)>>1;
        }
        ll res1 = mid*(mid+1)/2*n + n*(n-1)/2*m*mid;
        ll res2 = (mid+2)*(mid+1)/2*n + n*(n-1)/2*m*(mid+1);
        res1 = abs(S - 2*res1);
        res2 = abs(S - 2*res2);
        ll p1, v1;
        if(res1 <= res2)    p1 = mid + 1, v1 = res1;
        else    p1 = mid + 2, v1 = res2;

        low = 1, high = n, mid = (low+high+1)>>1;
        while(low < high){
            ll v = m*(m+1)/2*mid + mid*(mid-1)/2*m*m;
            if(v > S/2) high = mid-1;
            else    low = mid;
            mid = (low+high+1)>>1;
        }
        res1 = m*(m+1)/2*mid + mid*(mid-1)/2*m*m;
        res2 = m*(m+1)/2*(mid+1) + mid*(mid+1)/2*m*m;
        res1 = abs(S - 2*res1);
        res2 = abs(S - 2*res2);
        ll p2, v2;
        if(res1 <= res2)    p2 = mid + 1, v2 = res1;
        else    p2 = mid + 2, v2 = res2;
        
        if(v2 < v1) cout<<"H "<<p2<<'\n';
        else    cout<<"V "<<p1<<'\n';

        //cout<<p1<<','<<v1<<'\t'<<p2<<','<<v2<<'\n';
    }

}