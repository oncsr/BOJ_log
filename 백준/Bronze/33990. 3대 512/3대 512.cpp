#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int N, mx = 1e9;
    for(cin>>N;N--;){
        int a,b,c;
        cin>>a>>b>>c;
        if(a+b+c >= 512) mx = min(mx, a+b+c);
    }
    cout<<(mx == 1e9 ? -1 : mx);
    
}