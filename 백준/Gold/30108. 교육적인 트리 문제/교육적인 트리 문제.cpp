#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	vector<vector<int>> V(N + 1);
	for (int i = 2; i <= N; i++) {
		int a;
		cin >> a;
		V[a].push_back(i);
	}
	vector<int> arr(N + 1);
	for (int i = 1; i <= N; i++)	cin >> arr[i];

	priority_queue<pair<int, int>> Q;
	Q.emplace(arr[1], 1);
	ll s = 0;
	while (!Q.empty()) {
		auto [v, n] = Q.top();
		Q.pop();
		s += v;
		for (int i : V[n])	Q.emplace(arr[i], i);
		cout << s << '\n';
	}

}
