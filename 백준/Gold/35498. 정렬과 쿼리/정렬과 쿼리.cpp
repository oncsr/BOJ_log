// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
using ll = long long;

int N, Q;
ll brr[500005]{};
int minus_count = 0;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>Q;
    ll prev = -1e18;
    for(int i=1,a;i<=N;i++) {
        cin>>a;
        brr[i] = a - prev;
        if(brr[i] < 0) minus_count++;
        prev = a;
    }
    brr[N+1] = 1e18;
    
    for(int o,l,r,v;Q--;) {
        cin>>o;
        if(o == 2) cout<<(minus_count ? "NO\n" : "YES\n");
        else {
            cin>>l>>r>>v;
            if(brr[l] < 0 && brr[l] + v >= 0) minus_count--;
            if(brr[l] >= 0 && brr[l] + v < 0) minus_count++;
            if(brr[r+1] < 0 && brr[r+1] - v >= 0) minus_count--;
            if(brr[r+1] >= 0 && brr[r+1] - v < 0) minus_count++;
            brr[l] += v;
            brr[r+1] -= v;
        }
    }
    
}