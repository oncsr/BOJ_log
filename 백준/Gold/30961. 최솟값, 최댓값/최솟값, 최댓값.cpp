#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	ll arr[1000000]{}, ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> arr[i], ans ^= arr[i] * arr[i];
	sort(arr, arr + N);

	for (int i = 1; i < N; i++)	ans ^= arr[i] * arr[i - 1];
	cout << ans;

}