#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	for (cin >> N; N; cin >> N) {
		vector<pair<string, double>> V(N);
		double mx = 0;
		for (auto& [a, b] : V) {
			cin >> a >> b;
			mx = max(mx, b);
		}
		for (auto [a, b] : V) {
			if (b == mx)	cout << a << ' ';
		}
		cout << '\n';
	}

}