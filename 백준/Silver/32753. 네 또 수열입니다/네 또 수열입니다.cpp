#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, k;
    cin>>n>>k;
    if(n == 2 && k == 1)    return cout<<"1 2",0;
    if(n >= 2)    return cout<<-1,0;
    for(;k--;cout<<"1 ");
}