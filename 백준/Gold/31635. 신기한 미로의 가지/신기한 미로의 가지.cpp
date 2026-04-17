#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin>>n;
    int vis[101]{}, par[101]{}, no[101]{};
    vis[1]++;
    int prev = 1;
    int cnt = 1;
    vector<pair<int, int>> ans;
    while(cnt < n){
        cout<<"maze"<<endl;
        int k;
        cin>>k;
        if(!vis[k]){
            par[k] = prev;
            ans.emplace_back(prev, k);
            vis[k]++;
            cnt++;
        }
        else{
            no[prev]++;
            while(no[k]){
                cout<<"gaji "<<par[k]<<endl;
                cin>>k;
            }
        }
        prev = k;
    }
    cout<<"answer"<<endl;
    for(auto [a,b]:ans) cout<<a<<' '<<b<<endl;

}