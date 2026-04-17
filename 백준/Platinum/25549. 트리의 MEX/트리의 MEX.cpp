#include <bits/stdc++.h>
using namespace std;

set<int> S[200001]{};
int mex[200001]{}, N, R;
vector<vector<int>> V(200001);
int ans[200001]{};

void dfs(int n, int p){
    for(int i:V[n]){
        dfs(i,n);
        if(S[n].size() < S[i].size())   swap(S[n], S[i]), swap(mex[n], mex[i]);
        for(int j:S[i]){
            if(S[n].count(j))   continue;
            S[n].insert(j);
            if(j != mex[n]) continue;
            int new_mex = j;
            auto k = S[n].find(j);
            while(k != S[n].end() && *k == new_mex) new_mex++, k++;
            mex[n] = new_mex;
        }
    }
    ans[n] = mex[n];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin>>N;
    for(int i=1;i<=N;i++){
        int a;
        cin>>a;
        if(a == -1) {R = i;continue;}
        V[a].push_back(i);
    }
    for(int i=1;i<=N;i++){
        int a;
        cin>>a;
        S[i].insert(a);
        mex[i] = a == 0 ? 1 : 0;
    }
    dfs(R, 0);
    for(int i=1;i<=N;i++)   cout<<ans[i]<<'\n';

}