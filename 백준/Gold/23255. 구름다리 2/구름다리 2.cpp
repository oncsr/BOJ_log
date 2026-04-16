#include <iostream>
#include <queue>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin>>N>>M;
    vector<vector<int>> V(N+1);
    for(int i=0,a,b;i<M;i++) {
        cin>>a>>b;
        V[a].push_back(b);
        V[b].push_back(a);
    }

    vector<int> ans(N+1);
    int cnt = 0;
    for(int c=1;cnt<N;c++){
        for(int i=1;i<=N;i++) if(!ans[i]){
            bool poss = 1;
            for(int j:V[i]) poss &= ans[j] != c;
            if(poss) ans[i] = c, cnt++;
        }
    }

    for(int i=1;i<=N;i++) cout<<ans[i]<<' ';

}