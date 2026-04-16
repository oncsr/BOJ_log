#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n,p,q,r,s,arr[21]{};
    cin>>n>>p>>q>>r>>s>>arr[1];
    ll ans = arr[1];
    for(int i=2;i<=n;i++){
        if(i&1)    arr[i]=arr[i/2]*r+s;
        else    arr[i]=arr[i/2]*p+q;
        ans+=arr[i];
    }
    cout<<ans;
}