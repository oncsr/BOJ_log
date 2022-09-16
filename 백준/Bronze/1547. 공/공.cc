#include<iostream>
using namespace std;
int main(){int x=1,m,a,b;cin>>m;while(m--){cin>>a>>b;if(x==a)x=b;else if(x==b)x=a;}cout<<x;}