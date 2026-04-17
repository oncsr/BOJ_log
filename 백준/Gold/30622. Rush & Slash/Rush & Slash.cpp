#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;

int root[100001]{};
int find(int x){
    if(x==root[x])  return x;
    return root[x] = find(root[x]);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin>>N;
    iota(root+1, root+N+1, 1);

    int dx[8] = {1,1,1,0,0,-1,-1,-1};
    int dy[8] = {1,0,-1,1,-1,1,0,-1};

    pl arr[100001]{};

    map<pl, int> M;

    for(int i=1;i<=N;i++){
        ll x, y;
        cin>>x>>y;
        arr[i] = {x,y};
        for(int d=0;d<8;d++){
            ll xx = x+dx[d], yy = y+dy[d];
            if(M.find(make_pair(xx,yy)) != M.end()){
                int a = find(i), b = find(M[{xx,yy}]);
                root[a] = b;
            }
        }
        M[{x,y}] = i;
    }

    vector<ll> D(N+1, -1);
    vector<ll> L;
    for(int i=1;i<=N;i++){
        int a = find(i);
        ll dist = abs(arr[i].first) + abs(arr[i].second);
        if(D[a] == -1)  D[a] = dist;
        else if(D[a] > dist)    D[a] = dist;
    }
    for(int i=1;i<=N;i++){
        if(D[i] == -1)  continue;
        L.push_back(D[i]);
    }

    sort(L.begin(), L.end());
    ll ans = L.back();
    L.pop_back();
    for(ll i:L) ans += 2*i;
    cout<<ans;


}