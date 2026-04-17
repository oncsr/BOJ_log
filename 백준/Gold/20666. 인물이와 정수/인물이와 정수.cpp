#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M, P;
	cin >> N >> M;
	ll arr[100001]{};
	int vis[100001]{};
	vector<vector<pair<int, ll>>> V(100001);
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> Q;
	ll ans = 0, cnt = M;
	for (int i = 1; i <= N; i++)	cin >> arr[i];
	for (cin >> P; P--;) {
		ll a, b, c;
		cin >> a >> b >> c;
		arr[b] += c;
		V[a].emplace_back(b, c);
	}
	for (int i = 1; i <= N; i++)	Q.emplace(arr[i], i);
	while (cnt > 0) {
		auto [a, i] = Q.top();
		Q.pop();
		if (arr[i] != a || vis[i])	continue;
		cnt--;
		vis[i]++;
		ans = max(ans, a);
		for (auto [j, t] : V[i]) {
			arr[j] -= t;
			Q.emplace(arr[j], j);
		}
	}
	cout << ans;
}