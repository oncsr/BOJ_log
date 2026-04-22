#include<bits/stdc++.h>
using namespace std;
main(){map<string,int> M;M["ChongChong"]=1;int N,s=1;for(cin>>N;N--;){string a,b;cin>>a>>b;int c=M[a]+M[b];if(c)s+=2-c,M[a]=M[b]=1;}cout<<s;}