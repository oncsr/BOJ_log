#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, W, L;
	cin >> N >> W >> L;
	queue<int> Q;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		Q.push(a);
	}

	int ans = 0, weight = 0;
	queue<pair<int, int>> B;
	while (!B.empty() || !Q.empty()) {
		int g = B.size();
		for (int i = 0; i < g; i++) {
			int a = B.front().first, b = B.front().second;
			B.pop();
			if (b == W) {
				weight -= a;
				continue;
			}
			B.push({ a,b + 1 });
		}

		if (!Q.empty() && Q.front() + weight <= L) {
			int a = Q.front();
			Q.pop();
			B.push({ a,1 });
			weight += a;
		}
		ans++;
	}

	cout << ans;

}