#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N >> M;
	vector<vector<int>> V(51);
	vector<int> L;
	int k;
	for (cin >> k; k--;) {
		int a;
		cin >> a;
		L.push_back(a);
	}

	vector<vector<int>> T(M);
	for (int i = 0; i < M; i++) {
		int b;
		cin >> b;
		T[i].resize(b);
		for (int& j : T[i])	cin >> j;
		
		for (int j = 0; j < T[i].size(); j++) {
			for (int x = j + 1; x < T[i].size(); x++) {
				V[T[i][j]].push_back(T[i][x]);
				V[T[i][x]].push_back(T[i][j]);
			}
		}

	}

	int vis[51]{};
	queue<int> Q;
	for (int& i : L)	Q.push(i), vis[i]++;

	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		for (int i : V[now]) {
			if (vis[i])	continue;
			Q.push(i);
			vis[i]++;
		}
	}

	int ans = 0;
	for (auto& R : T) {
		bool res = 0;
		for (int& i : R)	res |= vis[i];
		if (!res)	ans++;
	}
	cout << ans;

}