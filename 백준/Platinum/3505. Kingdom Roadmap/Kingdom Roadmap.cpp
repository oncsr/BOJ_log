#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> V(100001);
vector<int> L;

void dfs(int n, int p) {
	int c = 0;
	for (int i : V[n]) {
		if (i == p)	continue;
		dfs(i, n);
		c++;
	}
	if (!c)	L.push_back(n);
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
	if (V[1].size() == 1)	L.push_back(1);
	int S = (L.size() + 1) >> 1;
	cout << S << '\n';
	for (int i = 0; i < S; i++)
		cout << L[i] << ' ' << L[(S + i) % L.size()] << '\n';
}