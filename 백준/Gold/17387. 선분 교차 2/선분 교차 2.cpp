#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pp = pair<ll, ll>;
#define x first
#define y second

int ccw(pp a, pp b, pp c) {
	ll res = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
	if (res > 0) return 1;
	if (res < 0) return -1;
	return 0;
}

ld dist(pp a, pp b) {
	return ((ld)a.x - b.x) * ((ld)a.x - b.x) + ((ld)a.y - b.y) * ((ld)a.y - b.y);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	pp a1, a2, b1, b2;
	cin >> a1.x >> a1.y >> a2.x >> a2.y;
	cin >> b1.x >> b1.y >> b2.x >> b2.y;
	int res1 = ccw(a1, a2, b1) * ccw(a1, a2, b2);
	int res2 = ccw(b1, b2, a1) * ccw(b1, b2, a2);
	bool res;
	if (res1 < 0 && res2 < 0)	res = 1;
	else if (res1 < 0) {
		if (res2 == 0)	res = 1;
		else	res = 0;
	}
	else if (res2 < 0) {
		if (res1 == 0)	res = 1;
		else	res = 0;
	}
	else {
		if (res1 == 0 && res2 == 0) {
			vector<pp> V = { a1, a2, b1, b2 };
			sort(V.begin(), V.end());
			ld d = dist(V[0], V[3]);
			ld d1 = dist(a1, a2);
			ld d2 = dist(b1, b2);
			if (d1 + d2 + 2 * sqrt(d1) * sqrt(d2) < d)	res = 0;
			else	res = 1;
		}
		else	res = 0;
	}
	cout << (int)res;
}