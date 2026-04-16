#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll arr[100001]{}, S = 0, M, N;
	cin >> N >> M;
	for (int i = 0; i < N; i++)	cin >> arr[i], S += arr[i];
	sort(arr, arr + N, greater<>());

	ll s = 0;
	for (ll i = 0; i < N; i++) {
		s += arr[i];
		if (s * 2 >= S)	return cout << M / (i + 2), 0;
	}

}