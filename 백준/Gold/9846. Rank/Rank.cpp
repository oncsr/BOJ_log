#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin>>n>>k;
    vector<vector<int>> V(n+1);
    int deg[1001]{};
    for(;k--;){
        int a,b,c;
        char _;
        cin>>a>>_>>b>>_>>c;
        V[a].push_back(c);
        deg[c]++;
        if(_ == ','){
            V[a].push_back(b);
            deg[b]++;
        }
        else{
            V[b].push_back(c);
            deg[c]++;
        }
    }

    priority_queue<int> Q;
    for(int i=1;i<=n;i++){
        if(!deg[i]) Q.push(-i);
    }
    vector<int> ans;
    while(!Q.empty()){
        int n = -Q.top();    Q.pop();
        ans.push_back(n);
        for(int i:V[n]){
            if(!--deg[i])   Q.push(-i);
        }
    }
    if(ans.size() != n) cout<<0;
    else    for(int i:ans)  cout<<i<<' ';

}