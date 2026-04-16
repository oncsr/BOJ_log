#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M, S, E;
	cin>>N>>M>>S>>E;
	vector<vector<int>> V(N+1);
	for(int x,y;M--;V[x].push_back(y),V[y].push_back(x))	cin>>x>>y;
	vector<int> vis(N+1);
	vis[S]++;
	queue<pair<int, int>> Q;
	Q.emplace(S,0);
	while(!Q.empty()){
		auto [n,t] = Q.front();	Q.pop();
		if(n == E)	return cout<<t,0;
		for(int i:V[n]){
			if(vis[i])	continue;
			vis[i]++;
			Q.emplace(i,t+1);
		}
		if(n+1 <= N && !vis[n+1])	vis[n+1]++,Q.emplace(n+1,t+1);
		if(n-1 >= 1 && !vis[n-1])	vis[n-1]++,Q.emplace(n-1,t+1);
	}

}