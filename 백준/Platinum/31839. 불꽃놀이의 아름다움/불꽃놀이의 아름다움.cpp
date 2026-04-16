#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
vector<vector<int>> V(200001);
ll sub[200001]{}, down[200001]{}, up[200001]{}, S = 0;

void dfs(int n, int p){
	for(int i:V[n]){
		if(i == p)	continue;
		dfs(i,n);
		sub[n] += sub[i];
		down[n] += down[i] + sub[i];
	}
}

void dfs2(int n, int p){
	for(int i:V[n]){
		if(i == p)	continue;
		up[i] = S + down[n] + up[n] - down[i] - 2 * sub[i];
		dfs2(i,n);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin>>N;
	for(int i=1;i<N;i++){
		int a,b;
		cin>>a>>b;
		V[a].push_back(b);
		V[b].push_back(a);
	}

	for(int i=1;i<=N;i++)	cin>>sub[i], S += sub[i];

	dfs(1,0);
	dfs2(1,0);

	ll ans = 0;
	for(int i=1;i<=N;i++)	ans = max(ans, down[i] + up[i]);
	cout<<ans;

}