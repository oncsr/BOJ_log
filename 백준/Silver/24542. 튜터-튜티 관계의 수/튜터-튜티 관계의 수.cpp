#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N, M;
	cin >> N >> M;
	vector<vector<int>> V(200001);
	for (; M--;) {
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	int vis[200001]{};
	ll ans = 1;
	for (int i = 1; i <= N; i++) {
		if (vis[i])	continue;
		ll c = 0;
		queue<int> Q;
		Q.push(i);
		vis[i]++;
		while (!Q.empty()) {
			int n = Q.front();
			Q.pop();
			c++;
			for (int j : V[n]) {
				if (vis[j])	continue;
				vis[j]++;
				Q.push(j);
			}
		}
		ans *= c;
		ans %= 1000000007;
	}
	cout << ans;

}