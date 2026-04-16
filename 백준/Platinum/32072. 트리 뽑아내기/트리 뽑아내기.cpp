#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	vector<vector<int>> V(300001);
	int N, arr[300001]{};
	cin >> N;
	for (int i = 2; i <= N; i++) {
		int a;
		cin >> a;
		V[a].push_back(i);
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> Q;
	for (int i = 1; i <= N; i++)	cin >> arr[i];
	Q.emplace(arr[1], 1);

	while (!Q.empty()) {
		auto [v, n] = Q.top();
		Q.pop();
		cout << v << '\n';
		for (int i : V[n])	Q.emplace(arr[i], i);
	}

}