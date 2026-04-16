#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
        int n;
        cin>>n;
        vector<ll> A(n), B(n);
        for(ll &i:A)    cin>>i;
        for(ll &i:B)    cin>>i;
        sort(A.begin(), A.end());
        sort(B.begin(), B.end(), greater<>());
        ll s = 0;
        for(int i=0;i<n;i++)    s += A[i]*B[i];
        cout<<"Case #"<<t<<": "<<s<<'\n';
    }
}