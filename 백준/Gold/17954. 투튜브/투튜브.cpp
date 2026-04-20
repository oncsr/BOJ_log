#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll N;
	cin >> N;
	if (N == 1) {
		cout << "2\n1\n2";
		return 0;
	}
	vector<ll> arr;
	for (int i = 2 * N - 3, c = 0; c < N - 1; i--, c++)	arr.emplace_back(i);
	arr.emplace_back(2 * N - 2);
	arr.emplace_back(2 * N - 1);
	for (int i = N - 2; i >= 1; i--)	arr.emplace_back(i);
	arr.emplace_back(2 * N);
	ll ans = 0, sum = 0;
	for (int i = 0; i < 2 * N; i++)	sum += arr[i];
	for (ll i = 0; i < 2 * N; i++) {
		sum -= arr[i];
		ans += (i + 1) * sum;
	}
	cout << ans << '\n';
	for (int i = 0; i < 2 * N; i++) {
		if (i == N)	cout << '\n';
		cout << arr[i] << ' ';
	}

}