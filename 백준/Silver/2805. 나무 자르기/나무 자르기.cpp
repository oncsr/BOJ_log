#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll N, M, arr[1'000'000]{};
	cin >> N >> M;

	for (int i = 0; i < N; i++)	cin >> arr[i];

	ll low, mid, high;
	low = 0;
	high = 2'000'000'000;
	mid = (low + high + 1) / 2;
	while (low < high) {
		
		ll sum = 0;
		for (int i = 0; i < N; i++) {
			if (arr[i] >= mid)	sum += arr[i] - mid;
		}

		if (sum >= M)	low = mid;
		else	high = mid - 1;
		mid = (low + high + 1) / 2;
	}

	cout << mid;

}