#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int N;
    cin>>N;
    vector<int> cur = {0,1,2,3,4,5,6,7};
    vector<int> V = {1,2,3,0,5,6,7,4};
    vector<int> P = {4,5,1,0,7,6,2,3};
    auto move = [&](vector<int> x, char o) -> vector<int> {
        vector<int> nx(8);
        for(int i=0;i<8;i++)    nx[i] = o == 'V' ? x[V[i]] : x[P[i]];
        return nx;
    };
    for(int i=0;i<N;i++){
        char a;
        cin>>a;
        cur = move(cur, a);
    }

    queue<tuple<vector<int>, string>> Q;
    map<vector<int>,int> M;
    Q.emplace(cur,"");
    M[cur]++;
    while(!Q.empty()){
        auto [n,r] = Q.front();Q.pop();
        if(n[0] == 0)    return cout<<r.size()<<'\n'<<r,0;
        vector<int> v = move(n,'V');
        vector<int> p = move(n,'P');
        if(!M[v])   Q.emplace(v,r+'V'),M[v]++;
        if(!M[p])   Q.emplace(p,r+'P'),M[p]++;
    }

}