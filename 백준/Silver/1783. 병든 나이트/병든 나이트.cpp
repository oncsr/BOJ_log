#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n,m;
    cin>>n>>m;
    if(n >= 3){
        if(m <= 4)  cout<<m;
        else if(m >= 7) cout<<m-2;
        else    cout<<4;
    }
    else if(n == 2) cout<<max(1, min(4, (m+1)/2));
    else    cout<<1;

}