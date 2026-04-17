#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<pair<int, ll>>> V(200001);

void dijk(vector<ll>& D, int start) {
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> Q;
	D[start] = 0;
	Q.emplace(0, start);
	while (!Q.empty()) {
		auto [dist, now] = Q.top();
		Q.pop();
		if (dist > D[now])	continue;
		for (auto [next, cost] : V[now]) {
			if (D[next] == -1 || D[next] > dist + cost) {
				D[next] = dist + cost;
				Q.emplace(D[next], next);
			}
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N, M, A, B;
	cin >> N >> M >> A >> B;
	for (; M--;) {
		int a, b, c;
		cin >> a >> b >> c;
		V[a].emplace_back(b, c);
		V[b].emplace_back(a, c);
	}
	vector<ll> DA(200001, -1);
	vector<ll> DB(200001, -1);

	dijk(DA, A);	dijk(DB, B);
	ll mn = 1e18;
	for (int i = 1; i <= N; i++)	mn = min(mn, DA[i] + DB[i]);

	vector<int> ans;
	for (int i = 1; i <= N; i++) {
		if (DA[i] + DB[i] == mn)	ans.push_back(i);
	}
	cout << ans.size() << '\n';
	for (int i : ans)	cout << i << ' ';
}