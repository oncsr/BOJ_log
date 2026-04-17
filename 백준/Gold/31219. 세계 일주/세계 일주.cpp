#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
using ll = long long;
using ii = pair<ll, ll>;

int ccw(ii a, ii b, ii c) {
	ii vec1 = { b.x - a.x,b.y - a.y };
	ii vec2 = { c.x - b.x,c.y - b.y };

	return ((ll)vec1.x * vec2.y - (ll)vec1.y * vec2.x) > 0 ? 1 : -1;
}

int intersect(ii a, ii b, ii c, ii d) {
	int v1 = ccw(a, b, c) * ccw(a, b, d);
	int v2 = ccw(c, d, a) * ccw(c, d, b);
	return v1 < 0 && v2 < 0;
}

long double dist(ii a, ii b) {
	long double res = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;
	vector<ii> arr(n);
	vector<int> ord(n);
	iota(ord.begin(), ord.end(), 0);
	for (int i = 0; i < n; i++)	cin >> arr[i].x >> arr[i].y;
	
	int find = 0;
	long double ans = 1e15;
	do {
		bool poss = 1;
		long double res = dist(arr[ord[0]], arr[ord[1]]) + dist(arr[ord[1]], arr[ord[2]]);
		for (int i = 2; i < n; i++) {
			bool inter = 0;
			for (int j = 0; j < i - 1; j++) {
				if (intersect(arr[ord[i]], arr[ord[(i + 1) % n]], arr[ord[j]], arr[ord[j + 1]])) {
					inter = 1;
					break;
				}
			}
			if (inter) { poss = 0; break; }
			res += dist(arr[ord[i]], arr[ord[(i + 1) % n]]);
		}
		if (poss)	ans = min(ans, res), find = 1;

	} while (next_permutation(ord.begin(), ord.end()));

	if (!find)	cout << -1;
	else {
		cout.precision(10);
		cout << fixed << ans;
	}

}