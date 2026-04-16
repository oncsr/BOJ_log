#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N >> M;
	vector<vector<int>> V(1000001);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int a;
			cin >> a;
			V[i * j].push_back(a);
		}
	}

	int vis[1000001]{};
	queue<int> Q;
	vis[1]++;
	for (int i : V[1])	Q.push(i), vis[i]++;

	while (!Q.empty()) {
		int n = Q.front();
		Q.pop();
		if (n == N * M)	return cout << "yes", 0;
		for (int i : V[n]) {
			if (!vis[i]) {
				vis[i]++;
				Q.push(i);
			}
		}
	}
	cout << "no";

}