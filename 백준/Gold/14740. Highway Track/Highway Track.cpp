#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll arr[500001]{}, N;
	cin >> N;
	for (int i = 1; i <= N; i++)	cin >> arr[i];
	for (int i = 1, a; i <= N; i++)	cin >> a, arr[i] -= a;
	ll mn = 1e18;
	for (int i = 1; i <= N; i++) {
		arr[i] += arr[i - 1];
		mn = min(mn, arr[i]);
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (arr[i] == mn)	ans++;
	}
	cout << ans;

}