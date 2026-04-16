#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int root[1000001]{}, N, M;
int val[1000001]{};

int to_one(int x, int y) { return x * M + y; }

pair<int, int> to_two(int a) { return { a / M,a % M }; }

int find(int x) {
	if (x == root[x])	return x;
	return root[x] = find(root[x]);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N >> M;
	iota(root, root + N * M, 0);
	fill(val, val + 1000001, -1);
	int arr[1000][1000]{};
	int dx[4] = { 1,0,0,-1 };
	int dy[4] = { 0,1,-1,0 };
	priority_queue<pair<int, int>> Q;
	for (int i = 0; i < N; i++)	for (int j = 0; j < M; j++) {
		cin >> arr[i][j];
		Q.emplace(arr[i][j], to_one(i, j));
	}
	ll ans = 0, cur = 0;
	while (!Q.empty()) {
		auto [v, a] = Q.top();
		Q.pop();
		auto [x, y] = to_two(a);
		val[a] = v;
		cur += v;
		for (int k = 0; k < 4; k++) {
			int xx = x + dx[k], yy = y + dy[k];
			int b = to_one(xx, yy);
			if (xx < 0 || xx >= N || yy < 0 || yy >= M || val[b] == -1)	continue;
			int r1 = find(a), r2 = find(b);
			if (r1 == r2)	continue;
			cur -= val[r1] + val[r2];
			root[r1] = r2;
			val[r2] ^= val[r1];
			cur += val[r2];
		}
		ans = max(ans, cur);
	}
	cout << ans;

}