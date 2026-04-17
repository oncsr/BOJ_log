#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	set<ii> S;
	int ans = 0, N;
	ii arr[5000]{};
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		arr[i] = make_pair(a, b);
		S.emplace(a, b);
	}

	for (int i = 0; i < N; i++) {
		auto [a1, b1] = arr[i];
		for (int j = i + 1; j < N; j++) {
			auto [a2, b2] = arr[j];
			if (a1 == a2 || b1 == b2)	continue;
			if (S.count({ a1,b2 }) && S.count({ a2, b1 }))	ans++;
		}
	}
	cout << ans / 2;

	
}