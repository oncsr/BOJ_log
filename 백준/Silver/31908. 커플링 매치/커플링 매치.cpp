#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int N;
    cin>>N;
    map<string, set<string>> M;
    for(int i=0;i<N;i++){
        string a,b;
        cin>>a>>b;
        if(b == "-")    continue;
        M[b].insert(a);
    }
    vector<pair<string, string>> ans;
    for(auto &[a,b]:M){
        if(b.size() != 2)   continue;
        string aa = *b.begin();
        b.erase(aa);
        string bb = *b.begin();
        ans.emplace_back(aa,bb);
    }
    cout<<ans.size()<<'\n';
    for(auto [a,b]:ans) cout<<a<<' '<<b<<'\n';
    
}