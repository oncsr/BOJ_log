#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int deg[13]{};
	vector<vector<int>> V(13);
	for (int i = 0; i < 12; i++) {
		int x, y;
		cin >> x >> y;
		deg[x]++, deg[y]++;
		V[x].push_back(y);
		V[y].push_back(x);
	}

	for (int i = 1; i <= 12; i++) {
		if (deg[i] != 3)	continue;
		int s = 0;
		for (int j : V[i])	s += deg[j];
		if (s == 6)	return cout << i, 0;
	}

}