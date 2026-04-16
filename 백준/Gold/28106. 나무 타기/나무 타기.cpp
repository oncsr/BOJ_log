#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N, R = 0;
    cin>>N;
    vector<vector<int>> V(N+1);
    for(int i=1;i<=N;i++){
        int p;
        cin>>p;
        if(p)   V[p].push_back(i);
        else    R = i;
    }
    vector<int> A(N+1);
    for(int i=1;i<=N;i++)   cin>>A[i];
    
    ll mod = 998244353;
    
    vector<ll> D(N+1);
    function<ll(int, int)> sol = [&](int n, int d) -> ll {
        ll res = D[n];
		if(d){
            for(int i:V[n]){
                res = (res + sol(i,d-1)) % mod;
            }
        }
        return res;
    };
    
    function<void(int)> dfs = [&](int n) -> void {
        int c = 0;
        for(int i:V[n]){
            dfs(i);
            c++;
        }
        if(!c)  D[n] = 1;
        else    D[n] = (D[n] + sol(n, A[n])) % mod;
    };
    
    dfs(R);
	cout<<D[R];
    
}