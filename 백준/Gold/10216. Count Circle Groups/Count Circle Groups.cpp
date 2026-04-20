#include <bits/stdc++.h>
using namespace std;

vector<int> root;
int find(int x){
    if(x == root[x])    return x;
    return root[x] = find(root[x]);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int T;
    for(cin>>T;T--;){
        int N;
        cin>>N;
        root.resize(N+1);
        iota(root.begin()+1, root.end(), 1);
        vector<pair<pair<int, int>, int>> arr(N+1);
        for(int i=1;i<=N;i++){
            int xi, yi, ri;
            cin>>xi>>yi>>ri;
            arr[i] = {{xi, yi}, ri};
            for(int j=1;j<i;j++){
                int xj = arr[j].first.first, yj = arr[j].first.second, rj = arr[j].second;
                int dist = (xi-xj)*(xi-xj) + (yi-yj)*(yi-yj);
                if(dist > ri*ri + rj*rj + 2*ri*rj)  continue;
                int x = find(i), y = find(j);
                root[x] = y;
            }
        }
        set<int> S;
        for(int i=1;i<=N;i++)   S.insert(find(i));
        cout<<S.size()<<'\n';

    }

}