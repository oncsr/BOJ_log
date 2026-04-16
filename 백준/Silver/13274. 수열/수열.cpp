#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll arr[100001]{}, N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++)	cin >> arr[i];
	for (; K--;) {
		sort(arr + 1, arr + N + 1);
		ll l, r, x;
		cin >> l >> r >> x;
		for (int i = l; i <= r; i++)	arr[i] += x;
	}
	sort(arr + 1, arr + N + 1);
	for (int i = 1; i <= N; i++)	cout << arr[i] << ' ';

}