#include <iostream>
using namespace std;

int parent[201]{};

int find(int n) {
	if (parent[n] == n)	return n;
	return parent[n] = find(parent[n]);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M, a;
	cin >> N >> M;
	int visit[201]{};
	for (int i = 1; i <= N; i++)	parent[i] = i;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> a;
			if (a) {
				if (parent[i] != parent[j]) {
					if (i > j)	continue;
					if(find(i) != find(j))	parent[find(i)] = j;
				}
			}
		}
	}
	bool s = true;
	int root = 0;
	while (M--) {
		cin >> a;
		if (!visit[a]) {
			if (!root)	root = a;
			if (find(a) != find(root))	s = false;
		}
	}
	cout << (s ? "YES" : "NO");
}