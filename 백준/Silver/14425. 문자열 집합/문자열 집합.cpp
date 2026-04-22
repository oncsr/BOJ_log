#include<bits/stdc++.h>
using namespace std;
main(){map<string,int>S;int N,M,c=0;string a;for(cin>>N>>M;N--;)cin>>a,S[a]=1;for(;M--;)cin>>a,c+=S[a];cout<<c;}