#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ii = pair<ll, ll>;
#define x first
#define y second

vector<ii> Hull;

ll ccw(ii a, ii b, ii c) {
	ii vec1 = { b.x - a.x,b.y - a.y };
	ii vec2 = { c.x - b.x,c.y - b.y };
	return (ll)vec1.x * vec2.y - (ll)vec1.y * vec2.x;
}

ld dist(ii a, ii b) {
	return sqrtl(ld(a.x - b.x) * ld(a.x - b.x) + ld(a.y - b.y) * ld(a.y - b.y));
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, l;
	cin >> n >> l;
	Hull = vector<ii>(n);
	for (int i = 0; i < n; i++)	cin >> Hull[i].x >> Hull[i].y;

	sort(Hull.begin(), Hull.end());

	vector<ii> L, R;
	for (auto i : Hull) {
		while (L.size() >= 2 && ccw(i, L.back(), L[L.size() - 2]) <= 0)	L.pop_back();
		L.emplace_back(i);
		while (R.size() >= 2 && ccw(i, R.back(), R[R.size() - 2]) >= 0)	R.pop_back();
		R.emplace_back(i);
	}
	Hull = vector<ii>();
	for (int i = 0; i < R.size() - 1; i++)	Hull.emplace_back(R[i]);
	for (int i = L.size() - 1; i > 0; i--)	Hull.emplace_back(L[i]);

	ld PI = 3.14159265358979323l, ans = 2 * PI * l;
	for (int i = 0; i < Hull.size(); i++) {
		int next = (i + 1) % int(Hull.size());
		int prev = (i + Hull.size() - 1) % int(Hull.size());
		ans += dist(Hull[i], Hull[next]);
		ld ax = Hull[prev].x, ay = Hull[prev].y;
		ld bx = Hull[i].x, by = Hull[i].y;
		ld cx = Hull[next].x, cy = Hull[next].y;
	}
	ll res = ans + 0.5l;
	cout << res;

}