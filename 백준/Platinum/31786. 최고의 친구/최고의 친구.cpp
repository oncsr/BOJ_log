#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll seg[2097153][2]{};

void upt(int a, int s, int e, int i, ll v, int n) {
	if (s == e) { seg[n][a] += v; return; }
	int m = s + e >> 1;
	if (i <= m)	upt(a, s, m, i, v, n * 2);
	else	upt(a, m + 1, e, i, v, n * 2 + 1);
	seg[n][a] = seg[n * 2][a] + seg[n * 2 + 1][a];
}

ll find(int a, int s, int e, int l, int r, int n) {
	if (l > r || l > e || r < s)	return 0;
	if (l <= s && e <= r)	return seg[n][a];
	int m = s + e >> 1;
	return find(a, s, m, l, r, n * 2) + find(a, m + 1, e, l, r, n * 2 + 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int Q;
	cin >> Q;
	vector<tuple<int, ll, ll>> V(Q);
	vector<ll> S;
	for (int i = 0; i < Q; i++) {
		auto& [x, y, z] = V[i];
		cin >> x >> y;
		if (x == 2)	cin >> z, S.push_back(y * y + z * z);
		S.push_back(y * y);
	}

	sort(S.begin(), S.end());
	S.erase(unique(S.begin(), S.end()), S.end());
	map<ll, ll> M;
	int c = 0;
	for (ll i : S)	M[i] = ++c;

	set<pair<ll, ll>> E;
	for (auto& [x, y, z] : V) {
		ll d = x == 2 ? M[y * y + z * z] : M[y * y];
		if (x == 2) {
			if (E.count(make_pair(y, z))) {
				E.erase(make_pair(y, z));
				upt(0, 1, 2 * Q, d, -1, 1);
				upt(1, 1, 2 * Q, M[y * y], -1, 1);
			}
			else {
				E.insert(make_pair(y, z));
				upt(0, 1, 2 * Q, d, 1, 1);
				upt(1, 1, 2 * Q, M[y * y], 1, 1);
			}
		}
		else {
			cout << ll(E.size()) - find(0, 1, 2 * Q, 1, d, 1) - find(1, 1, 2 * Q, d, 2 * Q, 1) << '\n';
		}
	}

}