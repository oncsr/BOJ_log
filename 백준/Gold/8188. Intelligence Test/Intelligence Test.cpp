#include <bits/stdc++.h>
using namespace std;
using ld = long double;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N;
    vector<vector<int>> arr(1000001);
    cin>>N;
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        arr[a].push_back(i);
    }
    int Q;
    for(cin>>Q;Q--;){
        int m, p = -1;
        bool poss = 1;
        for(cin>>m;m--;){
            int a;
            cin>>a;
            p = upper_bound(arr[a].begin(), arr[a].end(), p) - arr[a].begin();
            if(p == arr[a].size()){
                poss = 0;
                continue;
            }
            p = arr[a][p];
        }
        cout<<(poss?"TAK\n":"NIE\n");
    }

}