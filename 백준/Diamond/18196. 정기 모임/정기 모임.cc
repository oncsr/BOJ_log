#include <bits/stdc++.h>
using namespace std;

int N, Q;
vector<vector<pair<int, int>>> v(300001);
int par[300001][19]{}, mx[300001][19]{}, dep[300001]{};
int lca[1048576]{}, dist[1048576]{};

void dfs(int n, int p, int d) {
	par[n][0] = p, dep[n] = d;
	for(auto [i,c]:v[n]) if(i != p) {
		mx[i][0] = c;
		dfs(i,n,d+1);
	}
}

pair<int,int> mrg(pair<int,int> A, pair<int,int> B) {
	if(A.first == -1) return B;
	if(B.first == -1) return A;
	int a = A.first, b = B.first, res = max(A.second, B.second);
	int diff = abs(dep[a]-dep[b]);
	for(int k=0;k<19;k++) if(diff & (1<<k)) {
		if(dep[a] > dep[b]) res = max(res, mx[a][k]), a = par[a][k];
		else res = max(res, mx[b][k]), b = par[b][k];
	}
	for(int k=18;k>=0;k--) if(par[a][k] != par[b][k]) {
		res = max({res, mx[a][k], mx[b][k]});
		a = par[a][k], b = par[b][k];
	}
	if(a != b) res = max({res, mx[a][0], mx[b][0]}), a = par[a][0];
	return {a, res};
}

void init(int s, int e, int n) {
	if(s == e) {
		lca[n] = s;
		return;
	}
	int m = (s+e)>>1;
	init(s,m,n*2);	init(m+1,e,n*2+1);
	auto [a, b] = mrg({lca[n*2], dist[n*2]}, {lca[n*2+1], dist[n*2+1]});
	lca[n] = a, dist[n] = b;
}

pair<int,int> find(int s, int e, int l, int r, int n) {
	if(l>r || l>e || r<s) return {-1,0};
	if(l<=s && e<=r) return {lca[n], dist[n]};
	int m = (s+e)>>1;
	auto a = find(s,m,l,r,n*2);
	auto b = find(m+1,e,l,r,n*2+1);
	return mrg(a,b);
}

int main(){
	cin.tie(0)->sync_with_stdio(0);

	cin>>N>>Q;
	for(int i=1,a,b,c;i<N;i++) {
		cin>>a>>b>>c;
		v[a].emplace_back(b,c);
		v[b].emplace_back(a,c);
	}

	dfs(1,0,0);
	for(int k=1;k<19;k++) for(int i=1;i<=N;i++) {
		par[i][k] = par[par[i][k-1]][k-1];
		mx[i][k] = max(mx[i][k-1], mx[par[i][k-1]][k-1]);
	}
	init(1,N,1);
	for(int a,b;Q--;cout<<find(1,N,a,b,1).second<<'\n') cin>>a>>b;

}