#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int N, M;
		cin >> N >> M;
		vector<vector<pair<int, int>>> V(M);
		for (; N--;) {
			int a, b, c;
			cin >> a >> b >> c;
			V[a].emplace_back(b, c);
			V[b].emplace_back(a, c);
		}
		vector<int> D(M, -1), P(M);
		D[0] = 0;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> Q;
		Q.emplace(0, 0);
		while (!Q.empty()) {
			auto [d, n] = Q.top();
			Q.pop();
			if (d > D[n])	continue;
			for (auto [i, c] : V[n]) {
				if (D[i] == -1 || D[i] > d + c) {
					D[i] = d + c;
					P[i] = n;
					Q.emplace(D[i], i);
				}
			}
		}
		cout << "Case #" << tc << ": ";
		if (D[M - 1] == -1)	cout << D[M - 1];
		else {
			int n = M - 1;
			stack<int> ans;
			ans.push(n);
			while (n) {
				n = P[n];
				ans.push(n);
			}
			while (!ans.empty())	cout << ans.top() << ' ', ans.pop();
		}
		cout << '\n';
	}

}