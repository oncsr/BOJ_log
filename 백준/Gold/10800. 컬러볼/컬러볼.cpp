#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main() {
	cin.tie(0)->sync_with_stdio(0);


	ll S = 0, ans[200001]{};

	int N;
	cin >> N;
	vector<tuple<ll, int, int>> V;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		V.emplace_back(b, a, i + 1);
	}
	sort(V.begin(), V.end(), less<>());

	ll sum[200001]{};
	ll temp = get<0>(V[0]);
	queue<pair<int, ll>> Q;
	for (int i = 0; i < N; i++) {
		auto [sz, color, idx] = V[i];
		if (temp == sz) {
			Q.push({ color, sz });
		}
		else {
			while (!Q.empty()) {
				auto [x, y] = Q.front();
				Q.pop();
				S += y;
				sum[x] += y;
			}
			Q.push({ color, sz });
		}
		ans[idx] = S - sum[color];
		temp = sz;
	}
	
	for (int i = 1; i <= N; i++)	cout << ans[i] << '\n';


}