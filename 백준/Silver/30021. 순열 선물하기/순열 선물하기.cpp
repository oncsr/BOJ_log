#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    if(n == 1)    return cout<<"YES\n1",0;
    if(n == 2)    return cout<<"NO",0;
    cout<<"YES\n1 3 2 ";
    for(int i=4;i<=n;i++)    cout<<i<<' ';
}