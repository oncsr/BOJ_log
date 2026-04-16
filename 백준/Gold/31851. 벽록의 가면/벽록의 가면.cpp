#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define x first
#define y second

int ccw(ii a, ii b, ii c) {
	ii vec1 = { b.x - a.x,b.y - a.y };
	ii vec2 = { c.x - b.x,c.y - b.y };

	ll res = (ll)vec1.x * vec2.y - (ll)vec1.y * vec2.x;
	return (res > 0 ? 1 : (res < 0 ? -1 : 0));
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N;
	cin >> N;
	vector<pair<int, int>> arr(N);
	for (auto& [i, j] : arr)	cin >> i >> j;

	int ans = 0;
	for (int a = 0; a < N; a++)	for (int b = 0; b < N; b++)	for (int c = 0; c < N; c++) {
		if (a == b || b == c || c == a)	continue;
		int p = ccw(arr[a], arr[b], arr[c]);
		for (int d = 0; d < N; d++) {
			if (d == a || d == b || d == c)	continue;
			int p1 = ccw(arr[b], arr[c], arr[d]);
			int p2 = ccw(arr[c], arr[d], arr[a]);
			int p3 = ccw(arr[d], arr[a], arr[b]);

			if (p == p1 && p == p2 && p == p3)	ans++;
		}
	}

	cout << ans / 8;

}