// 수열과 쿼리 10^9
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<ll, ll>> seg;
vector<ll> lazy;

pair<ll, ll> mrg(pair<ll, ll> a, pair<ll, ll> b) {
	return { a.first + b.first, a.second + b.second };
}

void prop(int s, int e, int n) {
	if (lazy[n]) {
		seg[n].second = (seg[n].second + lazy[n] * seg[n].first);
		if (s != e) {
			lazy[n * 2] += lazy[n];
			lazy[n * 2 + 1] += lazy[n];
		}
		lazy[n] = 0;
	}
}

void init(int s, int e, int i, ll c, ll v, int n) {
	if (s == e) {
		seg[n] = { c,v };
		return;
	}
	int m = (s + e) >> 1;
	if (i <= m)	init(s, m, i, c, v, n * 2);
	else	init(m + 1, e, i, c, v, n * 2 + 1);
	seg[n] = mrg(seg[n * 2], seg[n * 2 + 1]);
}

void upt(int s, int e, int l, int r, ll v, int n) {
	prop(s, e, n);
	if (l > r || l > e || r < s)	return;
	if (l <= s && e <= r) {
		seg[n].second = (seg[n].second + v * seg[n].first);
		if (s != e) {
			lazy[n * 2] += v;
			lazy[n * 2 + 1] += v;
		}
		return;
	}
	int m = (s + e) >> 1;
	upt(s, m, l, r, v, n * 2);
	upt(m + 1, e, l, r, v, n * 2 + 1);
	seg[n] = mrg(seg[n * 2], seg[n * 2 + 1]);
}

ll find(int s, int e, int l, int r, int n) {
	prop(s, e, n);
	if (l > r || l > e || r < s)	return 0;
	if (l <= s && e <= r)	return seg[n].second;
	int m = (s + e) >> 1;
	return (find(s, m, l, r, n * 2) + find(m + 1, e, l, r, n * 2 + 1));
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	vector<tuple<ll, ll, ll>> V;
	vector<ll> S = { 1 };

	vector<tuple<ll, ll, ll, ll>> query;
    vector<tuple<ll, ll, ll, ll, int>> query2;
	int Q;
	cin >> Q;
    int dd = 0;
	for (int i = 0; i < Q; i++) {
		ll o, l, r, v = 0;
		cin >> o >> l >> r >> v;
		S.push_back(l);
		if (r != 1'000'000'000)	S.push_back(r + 1);
		if(o == 1)  query.emplace_back(o, l, r, v);
        else    query2.emplace_back(o,l,r,v,dd++);
	}

	sort(S.begin(), S.end());
	S.erase(unique(S.begin(), S.end()), S.end());
	S.push_back(1'000'000'001);
	ll N = S.size(), spos = 0, npos = 0;
	seg.resize(4 * (N - 1));
	lazy.resize(4 * (N - 1));

	for (int i = 1; i < N; i++) {
		int cnt = S[i] - S[i - 1];
		init(1, N - 1, ++spos, cnt, 0, 1);
	}
	N--;
    sort(query2.begin(), query2.end(), [&](auto a, auto b) -> bool {
        return get<3>(a) < get<3>(b);
    });

    int d = 0;
    vector<ll> ans(dd);
	for (auto [o, l, r, v, x] : query2) {
        while(d < v){
            auto [oo,ll,rr,vv] = query[d++];
            ll = lower_bound(S.begin(), S.end(), ll) - S.begin() + 1;
            rr = upper_bound(S.begin(), S.end(), rr) - S.begin();
            upt(1, N, ll, rr, vv, 1);
        }
        l = lower_bound(S.begin(), S.end(), l) - S.begin() + 1;
        r = upper_bound(S.begin(), S.end(), r) - S.begin();
		ans[x] = find(1, N, l, r, 1);
	}
    for(int i=0;i<dd;i++)   cout<<ans[i]<<'\n';

}