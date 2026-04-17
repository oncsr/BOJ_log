#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;

ll gcd(ll a, ll b){
    if(a < b)   swap(a,b);
    return a%b?gcd(b, a%b):b;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    ll x, y;
    cin>>x>>y;
    if(gcd(x, y) != 1){
        if(x == y)  cout<<"0";
        else{
            cout<<"1\n";
            cout<<y-x;
        }
        return 0;
    }
    ll z1 = 0, z2 = 0, cnt = 2;
    z1 = x*y-x;
    z2 = x*y - y;
    if(!z1) cnt--;
    if(!z2) cnt--;
    cout<<cnt<<'\n';
    if(z1)  cout<<z1<<'\n';
    if(z2)  cout<<-z2<<'\n';
    
}