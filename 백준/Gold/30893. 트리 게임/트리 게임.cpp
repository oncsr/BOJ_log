#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> V(100001);
int par[100001]{};

void dfs(int n, int p) {
	par[n] = p;
	for (int i : V[n]) {
		if (i == p)	continue;
		dfs(i, n);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, s, e;
	cin >> n >> s >> e;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	dfs(e, 0);

	bool pos = 1;
	int child;
	while (s != e) {
		if (pos) {
			child = s;
			s = par[s];
		}
		else {
			for (int i : V[s]) {
				if (i == par[s] || i == child)	continue;
				cout << "Second";
				return 0;
			}
			child = s;
			s = par[s];
		}
		pos ^= 1;
	}
	cout << "First";
}