#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll, ll>;
#define x first
#define y second

// ccw > 0 : counter-clockwise

ll ccw(ii a, ii b, ii c) {
	ll res = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
	if (res > 0)	return 1;
	if (res < 0)	return -1;
	return 0;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	ii arr[300001]{};
	int N;
	cin >> N;
	int ans = -1, start = -1;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i].x >> arr[i].y;
		if (i < 3)	continue;
		if (ccw(arr[i - 2], arr[i - 1], arr[i]) > 0) {
			if (start == -1)	start = i - 2;
			if (ccw(arr[i - 1], arr[i], arr[start]) > 0 && ccw(arr[i], arr[start], arr[start + 1]) > 0)	ans = max(ans, i - start + 1);
			else {
				while (ccw(arr[i - 1], arr[i], arr[start]) <= 0 || ccw(arr[i], arr[start], arr[start + 1]) <= 0)	start++;
			}
		}
		else	start = -1;
	}
	cout << ans;
}