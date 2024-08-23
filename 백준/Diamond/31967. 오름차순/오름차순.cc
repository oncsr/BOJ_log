#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll arr[250001]{}, M[250001]{};

ll lazy[524289]{}, seg[524289]{};
int idx[250001]{};

void init(int s, int e, int n) {
	if (s == e) {
		seg[n] = M[s];
		return;
	}
	int m = (s + e) >> 1;
	init(s, m, n * 2);	init(m + 1, e, n * 2 + 1);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

void prop(int s, int e, int n) {
	if (lazy[n]) {
		ll &v = lazy[n];
		seg[n] -= (ll(e) - s + 1) * v;
		if (s != e) {
			lazy[n * 2] += v;
			lazy[n * 2 + 1] += v;
		}
		v = 0;
	}
}

void upt(int s, int e, int l, int r, ll v, int n) {
	prop(s, e, n);
	if (l > r || l > e || r < s)	return;
	if (l <= s && e <= r) {
		seg[n] -= (ll(e) - s + 1) * v;
		if (s != e) {
			lazy[n * 2] += v;
			lazy[n * 2 + 1] += v;
		}
		return;
	}
	int m = (s + e) >> 1;
	upt(s, m, l, r, v, n * 2);	upt(m + 1, e, l, r, v, n * 2 + 1);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

ll find(int s, int e, int i, int n) {
	prop(s, e, n);
	if (s == e)	return seg[n];
	int m = (s + e) >> 1;
	if (i <= m)	return find(s, m, i, n * 2);
	return find(m + 1, e, i, n * 2 + 1);
}

ll sum(int s, int e, int l, int r, int n) {
	prop(s, e, n);
	if (l > r || l > e || r < s)	return 0;
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) >> 1;
	return sum(s, m, l, r, n * 2) + sum(m + 1, e, l, r, n * 2 + 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, Q;
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		if (i > 1) {
			ll a = arr[i - 1], b = arr[i];
			if (a == b)	continue;
			if (a > b) {
				while (a > b) {
					b <<= 1;
					M[i]++;
				}
			}
			else {
				while (a < b) {
					a <<= 1;
					M[i]--;
				}
				if (a != b)	M[i]++;
			}
		}
	}

	vector<pair<ll, int>> temp;
	stack<pair<ll, int>> S;
	S.emplace(0, 1);
	for (int i = 2; i <= N; i++) {
		M[i] = max(0LL, M[i - 1] + M[i]);
		while (!S.empty() && S.top().first > M[i]) {
			idx[S.top().second] = i;
			S.pop();
		}
		S.emplace(M[i], i);
	}
	init(1, N, 1);
	
	ll ans[250001]{};
	vector<tuple<int, int, int>> query;
	for (int i = 1; i <= Q; i++) {
		int l, r;
		cin >> l >> r;
		query.emplace_back(l, r, i);
	}
	sort(query.begin(), query.end());

	int s = 1;
	for (auto& [l, r, i] : query) {
		while (s < l) {
			s++;
			int L = s, R = idx[L] ? idx[L] : N + 1;
			ll v = find(1, N, L, 1);
			if (!v)	continue;
			while (R <= N) {
				upt(1, N, L, R - 1, v, 1);
				L = R;
				R = idx[L] ? idx[L] : N + 1;
				v = find(1, N, L, 1);
				if (!v)	break;
			}
			if (!v)	continue;
			if (L <= N)	upt(1, N, L, N, v, 1);
		}
		ans[i] = sum(1, N, l, r, 1);
	}
	for (int i = 1; i <= Q; i++)	cout << ans[i] << '\n';

}