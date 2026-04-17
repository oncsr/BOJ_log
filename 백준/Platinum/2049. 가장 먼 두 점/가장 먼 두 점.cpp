#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll, ll>;
#define x first
#define y second

vector<ii> Hull;

ll ccw(ii a, ii b, ii c) {
	ii vec1 = { b.x - a.x,b.y - a.y };
	ii vec2 = { c.x - b.x,c.y - b.y };
	return (ll)vec1.x * vec2.y - (ll)vec1.y * vec2.x;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
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

	ll ans = 0, p = 0;
	for (int i = 0, sz = Hull.size(); i < sz; i++) {
		ii q = { Hull[(p + 1) % sz].x - Hull[p % sz].x + Hull[(i + 1) % sz].x, Hull[(p + 1) % sz].y - Hull[p % sz].y + Hull[(i + 1) % sz].y };
		ans = max(ans, ((ll)Hull[i].x - Hull[p % sz].x) * ((ll)Hull[i].x - Hull[p % sz].x) + ((ll)Hull[i].y - Hull[p % sz].y) * ((ll)Hull[i].y - Hull[p % sz].y));
		while (p < 2 * sz && ccw(Hull[i], Hull[(i + 1) % sz], q) >= 0) {
			ans = max(ans, ((ll)Hull[i].x - Hull[p % sz].x) * ((ll)Hull[i].x - Hull[p % sz].x) + ((ll)Hull[i].y - Hull[p % sz].y) * ((ll)Hull[i].y - Hull[p % sz].y));
			p++;
			q = { Hull[(p + 1) % sz].x - Hull[p % sz].x + Hull[(i + 1) % sz].x, Hull[(p + 1) % sz].y - Hull[p % sz].y + Hull[(i + 1) % sz].y };
		}
		ans = max(ans, ((ll)Hull[i].x - Hull[p % sz].x) * ((ll)Hull[i].x - Hull[p % sz].x) + ((ll)Hull[i].y - Hull[p % sz].y) * ((ll)Hull[i].y - Hull[p % sz].y));
	}
	cout << ans;
}