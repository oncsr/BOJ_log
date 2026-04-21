#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f[51] = {1,1};
vector<string> V;

void solve(int now, ll root, ll k, string way){
    if(k == root){
        V.push_back(way);
        return;
    }
    if(k <= f[now-2] + root){
        way += 'L';
        solve(now-2, root+1, k, way);
    }
    else{
        way += 'R';
        solve(now-1, root+f[now-2]+1, k, way);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    for(int i=2;i<=50;i++)  f[i] = f[i-1]+f[i-2]+1;
    
    int N;
    ll s, e;
    cin>>N>>s>>e;
    solve(N, 1, s, "");
    solve(N, 1, e, "");
    string left = V[0], right = V[1], ans = "";
    int pos = -1;
    for(int i=0;i<min(left.size(), right.size());i++){
        if(left[i] == right[i]) continue;
        pos = i;
        break;
    }
    
    if(pos == -1){
        if(left.size() >= right.size()){
            for(int i=right.size();i<left.size();i++)   cout<<'U';
        }
        else{
            for(int i=left.size();i<right.size();i++)   cout<<right[i];
        }
    }
    else{
        for(int i=pos;i<left.size();i++)    cout<<'U';
        for(int i=pos;i<right.size();i++)   cout<<right[i];
    }

}