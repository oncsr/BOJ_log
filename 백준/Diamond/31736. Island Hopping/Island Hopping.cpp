#include "island.h"
#include <bits/stdc++.h>
using namespace std;

int root[301]{};
int find(int x) {
	if (x == root[x])	return x;
	return root[x] = find(root[x]);
}

void solve(int N, int L) {
	iota(root, root + N + 1, 0);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < N - 1; j++) {
			int r = query(i, j);
			int x = find(i), y = find(r);
			if (x == y)	continue;
			answer(i, r);
			root[x] = y;
		}
	}
}