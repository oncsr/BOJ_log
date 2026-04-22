#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> V(100001);
vector<int> leaf;

void dfs(int n, int p) {
	int c = 0;
	for (int i : V[n]) {
		if (i == p)	continue;
		dfs(i, n);
		c++;
	}
	if (!c)	leaf.push_back(n);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	dfs(1, 0);
	if (V[1].size() == 1)	leaf.push_back(1);
	int g = (leaf.size() + 1) / 2;
	cout << g << '\n';
	for (int i = 0; i < g; i++)
		cout << leaf[i] << ' ' << leaf[(i + g) % leaf.size()] << '\n';
}