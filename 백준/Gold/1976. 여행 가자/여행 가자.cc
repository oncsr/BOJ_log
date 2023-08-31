#include <bits/stdc++.h>
using namespace std;

int N, M, root[201]{};

int find(int x) {
	if (x == root[x])	return x;
	return root[x] = find(root[x]);
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)	root[i] = i;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int a;
			cin >> a;
			if (a)	root[find(i)] = find(j);
		}
	}
	int a;
	cin >> a;
	for (int i = 1; i < M; i++) {
		int t;
		cin >> t;
		if (find(a) != find(t)) {
			cout << "NO";
			return 0;
		}
		a = t;
	}
	cout << "YES";
}