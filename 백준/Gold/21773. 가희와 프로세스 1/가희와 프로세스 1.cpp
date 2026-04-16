#include <bits/stdc++.h>
using namespace std;
using info = tuple<int, int, int>;

struct cmp {
	bool operator()(info b, info a) {
		auto [p, q, r] = a;
		auto [z, x, c] = b;
		if (p == z)	return q < x;
		return p > z;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int T, N;
	cin >> T >> N;
	priority_queue<info, vector<info>, cmp> Q;
	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		Q.emplace(c, a, b);
	}

	int t = 1;
	while (t++ <= T) {
		auto [pr, id, tm] = Q.top();
		Q.pop();
		cout << id << '\n';
		if (--tm)	Q.emplace(pr - 1, id, tm);
	}

}