#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    bitset<100000001> e;
    for(int i=2;i*i<=100000000;i++) if(!e[i])   for(int j=i*i;j<=100000000;j+=i)    e[j]=1;

    int a,b;
    cin>>a>>b;
    while(a <= b){
        if(e[a])    {a++;continue;}
        string A = to_string(a), B = A;
        reverse(B.begin(), B.end());
        if(A == B)  cout<<A<<'\n';
        a++;
    }
    cout<<-1;

}