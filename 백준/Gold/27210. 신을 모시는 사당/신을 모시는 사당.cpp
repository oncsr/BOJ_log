#include<iostream>
using namespace std;main(){int n,a,x=0,m=0,s=0,i=1;for(cin>>n;n--;){cin>>a;s+=a&1;x=max(x,2*s-i);m=min(m,2*s-i++);}cout<<x-m;}