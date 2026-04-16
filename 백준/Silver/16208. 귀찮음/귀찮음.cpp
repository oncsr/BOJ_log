#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll N, arr[500000]{}, s = 0;
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> arr[i], s += arr[i];
	ll ans = 0;
	for (int i = 0; i < N - 1; i++) {
		ans += (s - arr[i]) * arr[i];
		s -= arr[i];
	}
	cout << ans;

}