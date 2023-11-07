#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> V(100001);

int ans = 0;

int dfs(int n, int p) {
	int mx1 = 0, mx2 = 0;
	for (int i : V[n]) {
		if (i == p)	continue;
		int g = dfs(i, n);
		if (g > mx1)	mx2 = mx1, mx1 = g;
		else if (g > mx2)	mx2 = g;
	}
	ans = max(ans, mx1 + mx2);
	return mx1 + 1;	
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	for (int i = 1; i < N; i++) {
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	dfs(1, 0);
	cout << ((ans + 1) >> 1);

}