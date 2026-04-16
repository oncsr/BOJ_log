#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, M, a;
vector<vector<ll>> arr;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	arr.resize(N);
	for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) {
		cin >> a;
		arr[j].push_back(a);
	}

	ll dist = 0;
	vector<ll> ans;
	for (auto& v : arr) {
		sort(v.begin(), v.end());
		ans.push_back(v[M >> 1]);
		for (ll& i : v) dist += abs(v[M >> 1] - i);
	}

	cout << dist << '\n';
	for (ll& i : ans) cout << i << ' ';
	
}