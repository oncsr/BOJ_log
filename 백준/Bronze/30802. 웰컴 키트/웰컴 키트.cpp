#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,t,p,a[6]{},b=0;
    cin>>n;
    for(int i=0;i<6;i++)cin>>a[i];
    cin>>t>>p;
    for(int i=0;i<6;i++)b+=(a[i]+t-1)/t;
    cout<<b<<'\n'<<n/p<<' '<<n%p;
}