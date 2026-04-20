#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll arr[100001]{};

bool cmp2(tuple<ll, ll, ll> a, tuple<ll, ll, ll> b) {
	auto [a1, a2, a3] = a;
	auto [b1, b2, b3] = b;
	if (a1 == b1)	return a2 > b2;
	return a1 < b1;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, K;
	cin >> N >> K;

	ll pos = 1, ans = 0;
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> Q;
	vector<tuple<int, int, int>> V;
	for (int i = 1; i <= N; i++) {
		ll a, b;
		cin >> a >> b;
		if (Q.size() < K) {
			Q.push({ b,i });
			V.push_back({ b, i, a });
		}
		else {
			ll ta = Q.top().first, tb = Q.top().second;
			Q.pop();
			V.push_back({ ta + b, tb, a });
			Q.push({ ta + b, tb });
		}
	}
	sort(V.begin(), V.end(), cmp2);
	for (ll i = 1; i <= V.size(); i++) {
		auto [x, y, z] = V[i - 1];
		ans += i * z;
	}
	cout << ans;

}