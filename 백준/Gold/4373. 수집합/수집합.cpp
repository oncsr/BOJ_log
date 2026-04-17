#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	for (cin >> N; N; cin >> N) {
		unordered_map<int, vector<pair<int, int>>> M;
		vector<int> arr(N);
		for (int& i : arr)	cin >> i;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j)	continue;
				M[arr[i] - arr[j]].emplace_back(arr[i], 1000 * i + j);
			}
		}

		int mx = -2e9;
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				auto& V = M[arr[i] + arr[j]];
				int g = 0;
				while (g < V.size()) {
					int temp = V[g].second;
					int a = temp / 1000, b = temp % 1000;
					if (i == a || i == b || j == a || j == b) { g++; continue; }
					mx = max(mx, V[g].first);
					break;
				}
			}
		}
		if (mx == -2e9)	cout << "no solution\n";
		else	cout << mx << '\n';
	}

}