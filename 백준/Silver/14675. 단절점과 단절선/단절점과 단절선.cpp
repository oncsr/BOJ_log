#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n, deg[100001]{}, q;
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        deg[a]++,deg[b]++;
    }
    for(cin>>q;q--;){
        int a,b;
        cin>>a>>b;
        if(a == 1 && deg[b] == 1)   cout<<"no\n";
        else    cout<<"yes\n";
    }
}