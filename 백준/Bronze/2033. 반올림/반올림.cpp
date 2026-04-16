#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int n,d=10;
    cin>>n;
    while(n>d){
        if(n%d >= d/2)  n += d - (n%d);
        else    n -= n%d;
        d *= 10;
    }
    cout<<n;

}