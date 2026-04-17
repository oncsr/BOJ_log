#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using point = pair<ll, ll>;
#define x first
#define y second

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int n;
	cin >> n;
	vector<point> arr(n);

	for (auto& [a, b] : arr)	cin >> a >> b;

	ll ans = 1e18;
	for (int a = 0; a < n; a++) {
		for (int b = 0; b < n; b++) {
			ll g = (arr[a].y + arr[b].y) >> 1;

			ll mx = 0;
			for (int i = 0; i < n; i++) {
				auto& [px, py] = arr[i];
				for (int j = i + 1; j < n; j++) {
					auto& [qx, qy] = arr[j];
					ll dist;
					if (px == qx)	dist = abs(py - qy);
					else	dist = abs(g - py) + abs(g - qy) + abs(px - qx);
					mx = max(mx, dist);
				}
			}
			ans = min(ans, mx);
		}
	}
	
	cout << ans;

}