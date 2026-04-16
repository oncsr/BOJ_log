#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

int N, M;
vector<tuple<int, int, int>> edges;
map<ll, ll> events;
vector<int> root;
vector<ll> cost;
ll X = 0, P = 0;

ll power(ll a, ll b) {
    if(b == 0) return 1;
    if(b == 1) return a % MOD;
    ll h = power(a, b>>1) % MOD;
    h = (h * h) % MOD;
    return (b&1) ? h * a % MOD : h;
}

ll g(ll x) { 
    x %= MOD;
    return x*(x+1)%MOD*power(2,MOD-2)%MOD;
}

int find(int x) { return x == root[x] ? x : root[x] = find(root[x]); }

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>M;
    P = power((1000000001LL * N % MOD * (N-1) % MOD * power(2, MOD-2) % MOD), MOD-2);
    for(int a,b,c;M--;) {
        cin>>a>>b>>c;
        edges.emplace_back(c,a,b);
    }

    root.resize(N+1);
    cost.resize(N+1);
    iota(root.begin(), root.end(), 0);
    fill(cost.begin(), cost.end(), 1);
    cost[0] = 0;
    
    sort(edges.begin(), edges.end());
    
    for(auto [c,a,b] : edges) {
        int x = find(a), y = find(b);
        if(x == y) continue;
        if(c) events[c] = (events[c] + cost[x]*cost[y]) % MOD;
        events[0] = (events[0] + (cost[x]*cost[y] % MOD * (1000000001 - c) % MOD)) % MOD;
        cost[y] += cost[x];
        root[x] = y;
        X += c;
    }

    ll C = 0, ans = 0;
    for(auto it = events.rbegin();it != events.rend();) {
        ll k = it->second;
        C = (C + k) % MOD;
        if(it->first == 0) {
            ans = (ans + (k * (X % MOD))) % MOD;
            break;
        }
        ll s = it->first;
        ll e = (++it)->first;
        
        ll cur = (X - s);
        ll nxt = (X - e);
        ans = (ans + C * ((nxt ? g(nxt-1) : 0) - (cur ? g(cur-1) : 0) + MOD) % MOD) % MOD;
    }
    cout<<ans * P % MOD;

}