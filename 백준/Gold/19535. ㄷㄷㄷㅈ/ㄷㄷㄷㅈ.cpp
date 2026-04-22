#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	ll arr[300001]{};
	vector<vector<int> > V(300001);
	for (int i = 1; i < N; i++) {
		int u, v;
		cin >> u >> v;
		arr[u]++, arr[v]++;
		V[u].push_back(v);
		V[v].push_back(u);
	}
	ll G = 0, D = 0;
	for (int i = 1; i <= N; i++) {
		if (arr[i] >= 3) {
			G += arr[i] * (arr[i] - 1) * (arr[i] - 2) / 6;
		}
		for (int j : V[i]) {
			if (j < i)	continue;
			if (arr[i] >= 2 && arr[j] >= 2) {
				D += (arr[i] - 1) * (arr[j] - 1);
			}
		}
	}
	if (D == 3 * G)	cout << "DUDUDUNGA";
	if (D > 3 * G)	cout << "D";
	if (D < 3 * G)	cout << "G";
}