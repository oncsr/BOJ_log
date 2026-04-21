#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {

	int N, M, arr[1000001]{};
	int left[1000001]{}, right[1000001]{};
	ll ans = 0;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)	cin >> arr[i];
	int mx = 0, mx2 = 0;
	for (int i = 1; i <= N; i++) {
		left[i] = mx;
		right[N - i + 1] = mx2;
		mx = max(mx, arr[i]);
		mx2 = max(mx2, arr[N - i + 1]);
	}

	for (int i = 1; i <= N; i++) {
		int g = min(left[i], right[i]);
		if (g < arr[i])	continue;
		ans += g - arr[i];
	}

	cout << ans;

}