#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, Q, arr[100001]{}, e = 1'000'000'000;
	cin >> N;
	for (int i = 1; i <= N; i++)	cin >> arr[i];
	vector<vector<pair<int, int>>> V(100002);
	cin >> Q;
	for (int i = 1; i <= Q; i++) {
		int l, r, x;
		cin >> l >> r >> x;
		V[l].emplace_back(x, i);
		V[r + 1].emplace_back(x - e, i);
	}

	set<pair<int, int>> S;
	int ans[100001]{};
	for (int i = 1; i <= N; i++) {
		for (auto [j, x] : V[i]) {
			if (j < 0)	S.erase({ j + e,x });
			else	S.insert({ j,x });
		}
		if (S.empty()) {
			cout << arr[i] << ' ';
			ans[0]++;
			continue;
		}
		auto [a, b] = *S.begin();
		if (a < arr[i])	cout << a << ' ', ans[b]++;
		else	cout << arr[i] << ' ', ans[0]++;
	}
	cout << '\n';
	int s = ans[0];
	for (int i = 1; i <= Q; i++) {
		s += ans[i];
		cout << s << ' ';
	}

}