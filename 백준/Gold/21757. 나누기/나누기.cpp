#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int arr[100001]{}, N, sum = 0;
	cin >> N;
	for (int i = 1; i <= N; i++)	cin >> arr[i], sum += arr[i];

	int left[100001]{}, sum2 = 0;
	for (int i = 1; i <= N; i++) {
		sum2 += arr[i];
		if (sum2 * 4 == sum)	left[i]++;
		left[i] += left[i - 1];
	}
	int right[100002]{};
	sum2 = 0;
	for (int i = N; i >= 1; i--) {
		sum2 += arr[i];
		if (sum2 * 4 == sum)	right[i]++;
		right[i] += right[i + 1];
	}

	long long ans = 0;
	sum2 = arr[1];
	for (int i = 2; i < N - 1; i++) {
		sum2 += arr[i];
		if (sum2 * 2 != sum)	continue;
		ans += (long long)left[i - 1] * (long long)right[i + 2];
	}
	cout << ans;

}