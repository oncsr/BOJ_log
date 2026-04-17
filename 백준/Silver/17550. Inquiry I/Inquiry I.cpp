#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll n, arr[1000001]{}, arr2[1000001]{};
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr2[i] += arr2[i - 1] + arr[i] * arr[i];
		arr[i] += arr[i - 1];
	}
	ll ans = 0;
	for (int k = 1; k <= n; k++) {
		ans = max(ans, arr2[k] * (arr[n] - arr[k]));
	}
	cout << ans;

}