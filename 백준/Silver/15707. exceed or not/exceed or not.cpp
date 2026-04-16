#include <bits/stdc++.h>
using namespace std;

__int128 f(string x){
    __int128 res = 0, d = 1;
    for(int j=x.size()-1;j>=0;j--){
        res += d*(x[j]-'0');
        d *= 10;
    }
    return res;
}

int main(){
    string a, b, r;
    cin>>a>>b>>r;
    if(a == "0" || b == "0") return cout<<"0", 0;
    if(a.size() + b.size() > 20) return cout<<"overflow", 0;
    __int128 A = f(a), B = f(b), R = f(r);
    if(A*B > R) return cout<<"overflow", 0;
    cout<<(long long)(A*B);
}