#include <iostream>
using namespace std;

int parent[1000001]{};

int find_root(int a) {
	if (parent[a] == a)	return a;
	return parent[a] = find_root(parent[a]);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m, q, a, b;
	cin >> n >> m;
	for (int i = 0; i <= n; i++)	parent[i] = i;
	while (m--) {
		cin >> q >> a >> b;
		int x = find_root(a), y = find_root(b);
		if (!q) {
			if (x != y)	parent[x] = y;
		}
		else {
			if (x == y)	cout << "YES\n";
			else	cout << "NO\n";
		}
	}
}