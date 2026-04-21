#include <bits/stdc++.h>
using namespace std;

int root[1001]{};

int find(int x) {
	if (x == root[x])	return x;
	return root[x] = find(root[x]);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)	root[i] = i;
	vector<vector<int>> V(1001);
	for (; m--;) {
		char o;
		int a, b;
		cin >> o >> a >> b;
		if (o == 'F') {
			int x = find(a), y = find(b);
			root[x] = y;
		}
		else {
			V[a].push_back(b);
			V[b].push_back(a);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (V[i].size() <= 1)	continue;
		for (int j = 0; j < V[i].size() - 1; j++) {
			int x = find(V[i][j]), y = find(V[i][j + 1]);
			root[x] = y;
		}
	}
	set<int> S;
	for (int i = 1; i <= n; i++)	S.insert(root[find(i)]);
	cout << S.size();
}