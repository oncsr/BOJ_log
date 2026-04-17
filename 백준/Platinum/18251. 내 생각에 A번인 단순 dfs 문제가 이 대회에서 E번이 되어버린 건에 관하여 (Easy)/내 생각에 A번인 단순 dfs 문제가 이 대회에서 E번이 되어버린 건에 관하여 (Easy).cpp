#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using node = tuple<ll, ll, ll, ll>;

ll mx = -1e18, h;
vector<ll> G(262144);

node mrg(node a, node b){
	auto [s1, l1, r1, t1] = a;
	auto [s2, l2, r2, t2] = b;
	ll x = s1 + s2;
	ll y = max(l1, s1 + l2);
	ll z = max(r2, s2 + r1);
	ll t = max({t1, t2, r1 + l2});
	mx = max(mx, t);
	return {x,y,z,t};
}

node dfs(int n, int d, int h1, int h2){
	if(d == h2)	return {G[n], G[n], G[n], G[n]};
	node a = dfs(n<<1, d+1, h1, h2), b = dfs((n<<1)+1, d+1, h1, h2);
	if(d < h1)	return mrg(a, b);
	return mrg(mrg(a, {G[n], G[n], G[n], G[n]}), b);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N;
	cin>>N;
	h = log2(N);
	for(int i=1;i<=N;i++)	cin>>G[i], mx = max(mx, G[i]);
	for(int i=h;i>=0;i--){
		for(int j=i;j>=0;j--){
			dfs(1, 0, j, i);
		}
	}
	cout<<mx;

}