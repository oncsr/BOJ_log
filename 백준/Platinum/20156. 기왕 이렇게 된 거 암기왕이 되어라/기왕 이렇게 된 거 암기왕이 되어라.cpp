#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int root[100001]{};
int find(int x){
    if(x == root[x])    return x;
    return root[x] = find(root[x]);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N, M, K;
    cin>>N>>M>>K;
    iota(root, root+N+1, 0);

    int par[100001]{};
    for(int i=1;i<=N;i++){
        int a;
        cin>>a;
        par[i] = a;
    }
    vector<int> R(M);
    bitset<100001> chk;
    for(int i=0;i<M;i++){
        int a;
        cin>>a;
        if(chk[a])  continue;
        R[i] = a;
        chk[a] = 1;
    }

    vector<tuple<int, int, int, int>> query;
    for(int i=0;i<K;i++){
        int a,b,c;
        cin>>a>>b>>c;
        query.emplace_back(a,b,c,i);
    }
    sort(query.begin(), query.end(), greater<>());

    for(int i=1;i<=N;i++){
        if(chk[i])  continue;
        if(par[i] == -1)    continue;
        int x = find(i), y = find(par[i]);
        root[x] = y;
    }

    bitset<100001> ans;
    int round = M-1;
    for(auto &[a,b,c,i] : query){
        while(round > a-1){
            int n = R[round];
            round--;
            if(!n)  continue;
            if(par[n] == -1)    continue;
            int x = find(n), y = find(par[n]);
            if(x == y)  continue;
            root[x] = y;
        }
        ans[i] = find(b) == find(c);
    }
    for(int i=0;i<K;i++)    cout<<(ans[i] ? "Same Same;\n" : "No;\n");

}