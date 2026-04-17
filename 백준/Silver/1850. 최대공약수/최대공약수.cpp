#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b){
    if(a < b)   swap(a,b);
    return a%b?gcd(b,a%b):b;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    ll a,b;
    cin>>a>>b;
    for(int i=0;i<gcd(a,b);i++) cout<<1;

}