#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> V(100001);
int mx = 0;

int dfs(int n, int p) {
	int mx1 = 0, mx2 = 0;
	for (auto e : V[n]) {
		int i = e.first, c = e.second;
		if (i == p)	continue;
		int g = dfs(i, n) + c;
		if (g > mx1) {
			mx2 = mx1;
			mx1 = g;
		}
		else if (g > mx2)	mx2 = g;
	}
	mx = max(mx, mx1 + mx2);
	return mx1;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		int b, c;
		for (cin >> b; b != -1; cin >> b) {
			cin >> c;
			V[a].push_back({ b,c });
		}
	}
	dfs(1, 0);
	cout << mx;

}