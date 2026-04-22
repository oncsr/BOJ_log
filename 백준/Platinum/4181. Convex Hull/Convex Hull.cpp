#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pl = pair<ll, ll>;
#define x first
#define y second

vector<pl> arr;

ll ccw(pl a, pl b) {
	pl P = { a.x - arr[0].x,a.y - arr[0].y };
	pl Q = { b.x - a.x,b.y - a.y };
	return P.x * Q.y - P.y * Q.x;
}

bool cmp(pl a, pl b) {
	ll num = ccw(a, b);
	if (num > 0)	return true;
	if (num < 0)	return false;
	pl g = arr[0];
	ll da = (a.x - g.x) * (a.x - g.x) + (a.y - g.y) * (a.y - g.y);
	ll db = (b.x - g.x) * (b.x - g.x) + (b.y - g.y) * (b.y - g.y);
	return da < db;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll a, b;
		char c;
		cin >> a >> b >> c;
		if (c == 'Y')	arr.push_back({ a,b });
	}
	sort(arr.begin(), arr.end());
	sort(arr.begin() + 1, arr.end(), cmp);
	int p1 = arr.size() - 1, p2 = arr.size() - 2;
	if (ccw(arr[p1], arr[p2]) == 0) {
		p1--, p2--;
		while (ccw(arr[p1], arr[p2]) == 0)	p1--, p2--;
	}
	cout << arr.size() << '\n';
	for (int i = 0; i < p1; i++)	cout << arr[i].x << ' ' << arr[i].y << '\n';
	for (int i = arr.size() - 1; i >= p1; i--)	cout << arr[i].x << ' ' << arr[i].y << '\n';
}