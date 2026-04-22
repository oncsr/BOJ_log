#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n;
	ll arr[100000]{};
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	ll k;
	cin >> k;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += min(n - i + 1, (ll)(arr + n + 1 - upper_bound(arr + 1, arr + n + 1, k + arr[i - 1])));
	}
	cout << ans;
}