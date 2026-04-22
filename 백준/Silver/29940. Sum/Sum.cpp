#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	ll arr[100000]{}, N, S, ans = 0;
	cin >> N >> S;
	for (int i = 0; i < N; i++)	cin >> arr[i];
	for (int i = 0; i < N; i++) {
		ans += upper_bound(arr + i + 1, arr + N, S - arr[i]) - lower_bound(arr + i + 1, arr + N, S - arr[i]);
	}
	cout << ans;
}